# Python 3.5.x wrapper module for 3D ACIS Modeler

ACIS-Python3 is a Python 3 module which provides a direct interface to Spatial Corporation's _3D ACIS Modeler_ solid modeling kernel.

## For Researchers

I would be glad if you cite this repository using the DOI provided as a badge at the top.

## Introduction

This package wraps Spatial Corporation's 3D ACIS Modeler into a Python (v3.5.x) module with minor changes due to how Python's C interface works. _3D ACIS Modeler_ or _ACIS_, in short, is a [solid and geometric modeling kernel](https://en.wikipedia.org/wiki/Geometric_modeling_kernel). Solid modeling kernels are sometimes called as "CAD Engines" too. These systems work behind the scenes and responsible for generation of solid models or surfaces, evaluation of geometric operations on solid models or surfaces, and so.

_3D ACIS Modeler_ provides a C++ API and its Scheme extension with variety of additional features. Even though it is used in a variety of commercial and research applications, it doesn't provide a Python interface which would be very useful for integration purposes. This module tries to fulfill the gap up to some point.

If you are

* not aware of what solid modeling or a CAD kernel is
* looking for the source code of a proprietary software
* seeking for help on CAD programming

you might be checking the wrong place. This repository only contains the source code for the _3D ACIS Modeler_ Python wrapper.

## Getting Started

This package depends on _3D ACIS Modeler_ headers and libraries. In order to obtain these, you might need to contact [Spatial Corporation](https://www.spatial.com/) for developer or university licenses.

After obtaining _3D ACIS Modeler_, please follow the steps below:

* Clone the repository: `git clone https://github.com/orbingol/ACIS-Python3.git`
* Update the submodules: `git submodule update --init --recursive`
* Install Python 3 and its development package, if necessary
* Install [CMake](https://cmake.org/)
* Using CMake GUI, choose the root of your cloned repository as the source directory
* Choose a build directory, preferable different from the source directory. You can use `<project_root>/build` for this purpose.
* Press configure button and choose your builder type, e.g. Visual Studio 2015 or Unix Makefiles.
* Set `ACIS_ROOT` to your ACIS installation directory; e.g. _C:\Program Files\Spatial\acisR26_. CMake will automatically find and fill the necessary variables.
* Don't forget to set Python library paths in CMake GUI.
* Use `APP_INSTALL_DIR` to set the install path for the module
* At the final step, press generate button and you are all set!

If you prefer, you can use CMake's command line tool to set up variables and generate build files.

## Compiling and Installing the Module

Most of the time a simple `make install` will take care of all necessary operations. Please note that, you have to run it in your build directory, not in your source directory.

The following CMake targets are also provided for convenience:

* `make uninstall`: Deletes installed files
* `make install_module`: Generates a .pth file inside the site-packages directory. May require root/admin priviliges.
* `make uninstall_module`: Deletes the .pth file inside the site-packages directory. May require root/admin privileges.

Please try using `make uninstall` and `make clean`, if you encounter any problems during compile or running stages.

By default, the module name is set to _ACIS_. The CMake variable `APP_MODULE_NAME` allows users to change the module name. Please don't forget to modify the import line in your Python code after changing the module name via CMake.

For Visual Studio 2015 users, you will see a lot of projects in your solution. If you only want to compile and run the package, right click on _INSTALL_ and choose _Rebuild_. 

## Using the Module

Please check `examples/` directory for example scripts and [the instructions](examples/README.md) on how to use these scripts.

## Function Reference

Please see the [Function Reference](FUNCTION_REFERENCE.md) to check which functions were implemented in this module.

## Author (Python module)

* Onur Rauf Bingol (contact@onurbingol.net)

## Licensing

The Python module is released under [MIT License](LICENSE). ACIS and SAT are registered trademarks of [Spatial Corporation](https://www.spatial.com/), a subsidiary of [Dassault Systemes](https://www.3ds.com/).
