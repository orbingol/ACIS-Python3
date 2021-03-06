cmake_minimum_required( VERSION 2.8 )
project( ACIS-Python3 CXX )

#
# Application Configuration
#

# Set Python version
set( APP_PYTHON_VERSION 3.5 )

#
# CMake setup and quick fixes
#

# Extend CMake module path for loading custom modules
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake-modules/" )

# Silence MSVC warnings regarding to strdup, fopen, etc.
if( MSVC )
  add_definitions( -D_SCL_SECURE_NO_WARNINGS )
  add_definitions( -D_CRT_SECURE_NO_WARNINGS )
  add_definitions( -D_CRT_SECURE_NO_DEPRECATE )
  add_definitions( -D_CRT_NONSTDC_NO_DEPRECATE )
endif( MSVC )

# Required for GenerateExportHeader module
#include( GenerateExportHeader )

# Activate GCC C++11 support for CMake versions before v3.1
if( CMAKE_VERSION VERSION_LESS 3.1 )
  message( STATUS "Using CMake " ${CMAKE_VERSION} )
  if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
    if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.7 )
      message( FATAL_ERROR "You need at least GCC v4.7" )
    elseif( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0 )
      # Enable experimental C++11 support in GCC
      add_compile_options( -std=c++11 )
    else( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.7 )
      # We are good to go!
    endif( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.7 )
  endif( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
endif( CMAKE_VERSION VERSION_LESS 3.1 )

# Fix a common problem related to cmath and Python
add_definitions( -D_hypot=hypot )


#
# Setup module name and install path
#

# Set module name
set( APP_MODULE_NAME "ACIS" CACHE STRING "Python module name." )

# Set install directory
set( APP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install CACHE PATH "Module install directory" )
set( CMAKE_INSTALL_PREFIX ${APP_INSTALL_DIR} )

# Set RPATH
set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )
set( CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${APP_MODULE_NAME}" )


#
# Find 3D ACIS Modeler
#

# findACIS module accepts a parameter for processing additional search paths
set( ACIS_ROOT "/opt" CACHE PATH "3D ACIS Modeler custom install path." )

# Find 3D ACIS Modeler headers and libraries
find_package( ACIS REQUIRED )

# Check if CMake has found libraries and headers for 3D ACIS Modeler
if( ACIS_FOUND )
  include_directories( ${ACIS_INCLUDE_DIRS} )
  # We don't need ACIS_ROOT variable anymore
  unset( ACIS_ROOT )
  unset( ACIS_ROOT CACHE )
else()
  message( FATAL_ERROR "ACIS not found" )
endif()


#
# Find Python libraries, interpreter and site-packages directory
#

# Find Python libs
find_package( PythonLibs ${APP_PYTHON_VERSION} REQUIRED )
if( PythonLibs_FOUND )
  include_directories( ${PYTHON_INCLUDE_DIRS} )
else()
  message( FATAL_ERROR "Python libraries not found" )
endif()

# Find Python interpreter
find_package( PythonInterp ${PYTHONLIBS_VERSION_STRING} REQUIRED )

# Find Python's site-packages directory and set PYTHON_SITE_PACKAGES variable
if( PYTHONINTERP_FOUND )
  execute_process(
      COMMAND ${PYTHON_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())"
      OUTPUT_VARIABLE PYTHON_SITE_PACKAGES
      OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  #message(STATUS "site-packages directory: " ${PYTHON_SITE_PACKAGES})
else()
  message( FATAL_ERROR "A valid Python interpreter is required for finding Python's site-packages directory!" )
endif()

#
# ACIS Python Module
#

# Set source files
set( ACIS_SOURCES_Modeler
    src/acis_includes.h
    src/acis_modeler.cpp
    src/acis_modeler.h
    src/acis_api.cpp
    src/acis_api.h
    src/acis_api2.cpp
    src/acis_api2.h
    src/acis_classes.cpp
    src/acis_classes.h
    src/acis_entity.cpp
    src/acis_entity.h
    src/acis_enums.cpp
    src/acis_enums.h
    src/acis_operators.cpp
    src/acis_operators.h
    src/utilities.cpp
    src/utilities.h
    )

# Generate Python module
add_library( Modeler SHARED ${ACIS_SOURCES_Modeler} )

# Set link targets
target_link_libraries( Modeler ${ACIS_LINK_LIBRARIES} ${PYTHON_LIBRARIES} )

# Add the build location to the include directories
target_include_directories( Modeler PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} )

# Set required C++ standard
set_property( TARGET Modeler PROPERTY CXX_STANDARD 11 )
set_property( TARGET Modeler PROPERTY CXX_STANDARD_REQUIRED ON )

# Add suffix to debug builds
if( WIN32 )
  set_target_properties( Modeler PROPERTIES DEBUG_POSTFIX "_d" )
endif()

# On Windows, Python modules have .pyd filename extension
if( WIN32 AND NOT CYGWIN )
  set_target_properties( Modeler PROPERTIES SUFFIX ".pyd" )
endif()

# This is only needed for the python case where a modulename.so is generated
set_target_properties( Modeler PROPERTIES PREFIX "" )


#
# CMake install rules for the Python modules
#

# Install Python modules to APP_INSTALL_DIR
install(
    TARGETS Modeler
    DESTINATION ${APP_INSTALL_DIR}/${APP_MODULE_NAME}
)

# Install helper modules
install(
    DIRECTORY python/
    DESTINATION ${APP_INSTALL_DIR}/${APP_MODULE_NAME}
)

# On Windows, it might be good to copy required DLL files into the module directory
if( WIN32 )
  install(
      FILES ${ACIS_REDIST_RELEASE}
      DESTINATION ${APP_INSTALL_DIR}/${APP_MODULE_NAME}
      CONFIGURATIONS Release RelWithDebInfo MinSizeRel
  )

  install(
      FILES ${ACIS_REDIST_DEBUG}
      DESTINATION ${APP_INSTALL_DIR}/${APP_MODULE_NAME}
      CONFIGURATIONS Debug
  )
endif()


#
# Install Python examples
#

# These examples are for demonstration purposes only
install( DIRECTORY examples/ DESTINATION ${APP_INSTALL_DIR} )


#
# Generate a target that generates __init__.py file
#

# Custom target to generate __init__py.file
add_custom_target( generate_init_py
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/__init__.py
    )

# Add generate_init_py target as a dependency to the main python module
add_dependencies( Modeler generate_init_py )

# Install __init__.py to the module/app directory
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py
    DESTINATION ${APP_INSTALL_DIR}/${APP_MODULE_NAME}
)


#
# Generate an uninstall target
# @see: https://cmake.org/Wiki/CMake_FAQ#Can_I_do_.22make_uninstall.22_with_CMake.3F
#

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
)

add_custom_target( uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
    )


#
# Generate a "complete install" target
# This target installs the module to Python's site-packages directory by creating a .pth file
#

# Run INSTALL target and then, generate .pth file in the site-packages directory
add_custom_target( install_module
    #COMMAND ${CMAKE_COMMAND} --build . --target install
    COMMAND ${CMAKE_COMMAND} -E echo ${APP_INSTALL_DIR} > "${PYTHON_SITE_PACKAGES}/ACIS.pth"
    )


#
# Generate a "complete uninstall" target
# This target uninstalls the module from Python's site-packages directory by deleting the .pth file
#

# Run UNINSTALL target and remove .pth file generated by the "install_module" target
add_custom_target( uninstall_module
    #COMMAND ${CMAKE_COMMAND} --build . --target uninstall
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PYTHON_SITE_PACKAGES}/ACIS.pth
    )


#
# Additional "make clean" files
#

# This will make "make clean" command to clean some extra files in addition to generated libraries
set_property(
    DIRECTORY
    APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "__init__.py"
)

#
# Create a custom install target for calling from IDEs
# This target installs the module and example scripts to the user-specified directory
#
add_custom_target( install_project
    $(CMAKE_COMMAND) --build . --target install
    COMMENT "Installing ${PROJECT_NAME}..."
    )
