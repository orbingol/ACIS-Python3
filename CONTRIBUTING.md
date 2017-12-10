# Contribution Guidelines

This is my first Python module developed with [Python C API](https://docs.python.org/3.5/c-api/index.html). I have been working with [SWIG](http://swig.org/) for a while and I would say that it is easy until you start working with [typemaps](http://swig.org/Doc3.0/Typemaps.html#Typemaps). SWIG is a great piece of software, if you know how to use it. That kind of knowledge requires a strong dedication to obtain, especially for the typemaps.

I developed this module to experiment on Python C API, in addition to aid my research on CAD, surface modeling and finite element analysis areas. Getting ready for a C++ program is time consuming but, creating a Python script is very easy and takes nearly no time in compared to a C++ program. A Python module also helps in integration of various systems with a CAD kernel.

It is nearly impossible to wrap all ACIS functions in Python, as the library is very huge and contains documented and undocumented functionality. I tried to wrap functions and classes that I need, so this wrapper might not contain your favorite functions or classes. I also did minimal checks on memory leaks and some types might contain unnecessary functionality. These are some points where I need help.

## Limitations and Implementation Strategies

There are some incompatibilities between some ACIS functions and Python API. For instance, FILE pointers. ACIS requires these pointers in a variety of functions and methods as a function argument, but Python API doesn't like them that much. So, instead of using a FILE pointer as a function argument, I passed a string, which acts as the file name to be saved, to the function and handled FILE pointers on the C/C++ side without exposing them to the Python side.

## How to Contribute

I would like to introduce some rules on contributing to this module.

### Contribution to the code

* All pull requests should be made to the `devmaster` branch
* After adding new functions or classes, the [function reference](FUNCTION_REFERENCE.md) should be also updated
* ACIS documentation convention (Topology, Geometric Atoms, Surfaces, etc.) should be followed when creating new modules
* I follow a naming convention for the functions and classes. Please see below for details.
* Create new examples covering the newly added functionality
* When creating new examples, do not use numbering.
* Make use of the issue tracker for any issues, comments or feature requests
* If you are not feeling comfortable with the issue tracker, please feel free to email me on anything related to this module.

#### Naming conventions in the Python module

* Type functions: `a3dp_{ACISName}_{function_name}`, e.g. _a3dp_SPAposition_init_ which corresponds to Python's _tp_init_ function.
* Methods for types: `a3dp_{ACISName}__{MethodName}`, e.g. _a3dp_ENTITY_LIST__add_ which corresponds to _ENTITY_LIST::add()_ on the C++ side
* ACIS API calls: `a3dp_{API-Call}`, e.g. _a3dp_api_start_modeller_ which corresponds to _api_start_modeller()_ on the C++ side

### Contribution in general

You don't have to contribute to the code. All new ideas, comments and requests on improving the module are welcome. Please don't hesitate to email me.

I am looking forward to your contributions.
