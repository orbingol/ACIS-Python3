# Implementation Details

I would like to talk about some implementation details and assumptions that I made during the programming of this Python module. This is going to be a long one, but if you are interested in the reasons, please take the risk and go on reading.

ACIS is a solid modeling kernel and it has C++ and Scheme language bindings. Scheme bindings depend on the C++ API too (please check your ACIS directory for details). On the other hand Python has a pure C API, even though Python programming language allows object-oriented programming. In order to port C++ to C correctly, we definitely need wrappers for each class method and structs for wrapping the class fields. Please see [this reference](https://isocpp.org/wiki/faq/mixing-c-and-cpp#cpp-objs-passed-to-c) for further discussion of this technique.

However, I believe the things could be different if we just consider ACIS and its implementation details. Before being harsh on what I wrote below, please don't forget that I am not a professional C/C++ programmer, not affiliated with Spatial and this is just a hobby project.

Let's divide the details into 2 parts:

## Solid Modeling Objects

ACIS, fortunately, comes with a custom memory manager. Using this integrated memory manager seems optional but by default, it comes enabled and to be honest, I never tried to disable it. If we return back to our discussion on the advantages of this memory manager, we could easily say that memory manager literally manages all main solid modeling components, such as `ENTITY` and others. Therefore, you cannot simply use `ENTITY` class (and the similar ones) before calling `api_start_modeller` and after calling `api_stop_modeller`.
In other words, ACIS does its object initialization and destruction inside its memory management system.

This looks like an advantage on the Python side, since ACIS does the heavy lifting in its memory manager. The only requirement is creating a solid modeling object pointer and if required, initialize the pointer with `ACIS_NEW` macro. Most of the API calls seem to handle the initialization step for the objects.

Destruction of the objects are also easy. Simply calling `api_stop_modeller` deletes all ACIS solid modeling pointers and on the Python side, all we need to is setting these pointers to `NULL` (therefore, Valgrind stops complaining).

The points that I am discussing in this section are:

* We never need to initialize a class inside Python code
* If we really need to initialize a class, we have a macro for this purpose
* ACIS memory manager handles the construction and destruction of most classes

As a result, it seems that there is no need to do the C++ to C wrapping tricks on the solid modeling objects.

## Geometric Atoms and Other Classes

This is where the thunderstorm comes. Let me start with the easy ones.

Some classes starting with `SPA`, such as `SPAposition`, needs to be implemented in Python but they don't have to be implemented in C. For instance, a `SPAposition` object is a wrapper for (x, y, z) coordinates and it could be possible to implement this class in pure Python. However, ACIS will require its C++ counterparts, and in each function which has a pure Python input needs to be converted on the C side (I mean pure Python `SPAposition` to C++ `SPAposition`).
Such conversions could be a memory hog and repetitive for the programmer, but I believe this could be the only way to conform the programming standards.

And finally, I would like to discuss the other classes, such as `BoolOptions`. Unfortunately, some of these classes require the wrapping trick that I explained above.

## Final Notes on Implementation Details

These details completely depend on my observations and experiences on ACIS. Some of them could be wrong or partially wrong. Please don't take these as a reference.

I will try to do my best to follow these details on the programming of this Python wrapper module, but definitely it is going to take some time to complete.
