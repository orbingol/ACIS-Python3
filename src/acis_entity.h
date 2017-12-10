/**
 *
 * Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler
 *
 * ACIS and SAT are registered trademarks of Spatial Corporation.
 *
 * The Python module is developed by Onur R. Bingol and released under MIT license.
 * Please see the LICENSE file for details.
 *
 */

#ifndef A3DPY_ENTITY_H
#define A3DPY_ENTITY_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "acis_operators.h"


// Define ENTITY as a base class
typedef struct
{
  PyObject_HEAD
  ENTITY *_acis_obj;
  PyObject *attrib_name;
  PyObject *attrib_object_id;
} a3dp_ENTITY;

// Define BODY
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_BODY;

// Define FACE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_FACE;

// Define EDGE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_EDGE;

// Define WIRE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_WIRE;

// Define LUMP
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_LUMP;

// Define SHELL
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SHELL;

// Define SUBSHELL
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SUBSHELL;

// Define COEDGE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_COEDGE;

// Define LOOP
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_LOOP;

// Define VERTEX
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_VERTEX;

// Define SURFACE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SURFACE;

// Define CONE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_CONE;

// Define PLANE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_PLANE;

// Define SPHERE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SPHERE;

// Define SPLINE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SPLINE;

// Define TORUS
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_TORUS;

// Define surface
typedef struct
{
  surface* _acis_obj;
} a3dp_surface;

// Define ENTITY_LIST
typedef struct
{
  PyObject_HEAD
  ENTITY_LIST *_acis_obj;
} a3dp_ENTITY_LIST;

extern PyTypeObject a3dp_type_ENTITY;
extern PyTypeObject a3dp_type_BODY;
extern PyTypeObject a3dp_type_FACE;
extern PyTypeObject a3dp_type_EDGE;
extern PyTypeObject a3dp_type_WIRE;
extern PyTypeObject a3dp_type_LUMP;
extern PyTypeObject a3dp_type_SHELL;
extern PyTypeObject a3dp_type_SUBSHELL;
extern PyTypeObject a3dp_type_COEDGE;
extern PyTypeObject a3dp_type_LOOP;
extern PyTypeObject a3dp_type_VERTEX;
extern PyTypeObject a3dp_type_SURFACE;
extern PyTypeObject a3dp_type_CONE;
extern PyTypeObject a3dp_type_PLANE;
extern PyTypeObject a3dp_type_SPHERE;
extern PyTypeObject a3dp_type_SPLINE;
extern PyTypeObject a3dp_type_TORUS;
extern PyTypeObject a3dp_type_surface;
extern PyTypeObject a3dp_type_ENTITY_LIST;

#ifdef __cplusplus
extern "C" {
#endif

PyObject *_PyNew_ENTITY();
bool _PyCheck_ENTITY(PyObject *ob);

PyObject *_PyNew_BODY();
bool _PyCheck_BODY(PyObject *ob);

PyObject *_PyNew_FACE();
bool _PyCheck_FACE(PyObject *ob);

PyObject *_PyNew_EDGE();
bool _PyCheck_EDGE(PyObject *ob);

PyObject *_PyNew_WIRE();
bool _PyCheck_WIRE(PyObject *ob);

PyObject *_PyNew_LUMP();
bool _PyCheck_LUMP(PyObject *ob);

PyObject *_PyNew_SHELL();
bool _PyCheck_SHELL(PyObject *ob);

PyObject *_PyNew_SUBSHELL();
bool _PyCheck_SUBSHELL(PyObject *ob);

PyObject *_PyNew_COEDGE();
bool _PyCheck_COEDGE(PyObject *ob);

PyObject *_PyNew_LOOP();
bool _PyCheck_LOOP(PyObject *ob);

PyObject *_PyNew_VERTEX();
bool _PyCheck_VERTEX(PyObject *ob);

PyObject *_PyNew_SURFACE();
bool _PyCheck_SURFACE(PyObject *ob);

PyObject *_PyNew_CONE();
bool _PyCheck_CONE(PyObject *ob);

PyObject *_PyNew_PLANE();
bool _PyCheck_PLANE(PyObject *ob);

PyObject *_PyNew_SPHERE();
bool _PyCheck_SPHERE(PyObject *ob);

PyObject *_PyNew_SPLINE();
bool _PyCheck_SPLINE(PyObject *ob);

PyObject *_PyNew_TORUS();
bool _PyCheck_TORUS(PyObject *ob);

PyObject *_PyNew_surface();
bool _PyCheck_surface(PyObject *ob);

PyObject *_PyNew_ENTITY_LIST();
bool _PyCheck_ENTITY_LIST(PyObject *ob);

// Additional functions

/**
 * Sets the internal ocis_obj variable to NULL
 * @param ob Topology object, such as ENTITY, BODY, FACE, etc.
 */
void __make_null(PyObject *ob);

void __set_entity(PyObject *ob, ENTITY *ent);

PyObject *__convert_entity(ENTITY *ent);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_ENTITY_H
