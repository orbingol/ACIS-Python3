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

#ifndef ACIS_ENTITY_H
#define ACIS_ENTITY_H

#include <Python.h>
#include <structmember.h>

#include "kernapi.hxx"
#include <entity.hxx>
#include <body.hxx>
#include <face.hxx>
#include <at_name.hxx>
#include <at_int.hxx>

#include "acis_entity_export.h"


#ifdef __cplusplus
extern "C" {
#endif

// Types and their functions

// Define ENTITY as a base class
typedef struct
{
  PyObject_HEAD
  ENTITY *_acis_obj;
  PyObject *attrib_name;
  PyObject *attrib_object_id;
} ACIS_Entity_ENTITY;

int ACIS_ENTITY_EXPORT ACIS_Entity_traverse_ENTITY(ACIS_Entity_ENTITY *self, visitproc visit, void *arg);

int ACIS_ENTITY_EXPORT ACIS_Entity_clear_ENTITY(ACIS_Entity_ENTITY *self);

void ACIS_ENTITY_EXPORT ACIS_Entity_dealloc_ENTITY(ACIS_Entity_ENTITY *self);

PyObject ACIS_ENTITY_EXPORT *ACIS_Entity_new_ENTITY(PyTypeObject *type, PyObject *args, PyObject *kwargs);

int ACIS_ENTITY_EXPORT ACIS_Entity_init_ENTITY(ACIS_Entity_ENTITY *self, PyObject *args, PyObject *kwargs);

PyObject ACIS_ENTITY_EXPORT *ACIS_Entity_repr_ENTITY(ACIS_Entity_ENTITY *self);

PyObject ACIS_ENTITY_EXPORT *ACIS_Entity_str_ENTITY(ACIS_Entity_ENTITY *self);

PyObject ACIS_ENTITY_EXPORT *ACIS_Entity_method_ENTITY_get_attrib_name(ACIS_Entity_ENTITY *self, PyObject *value, void *closure);

int ACIS_ENTITY_EXPORT ACIS_Entity_method_ENTITY_set_attrib_name(ACIS_Entity_ENTITY *self, PyObject *value, void *closure);

PyObject ACIS_ENTITY_EXPORT *ACIS_Entity_method_ENTITY_get_attrib_obj_id(ACIS_Entity_ENTITY *self, PyObject *value, void *closure);

int ACIS_ENTITY_EXPORT ACIS_Entity_method_ENTITY_set_attrib_obj_id(ACIS_Entity_ENTITY *self, PyObject *value, void *closure);

static PyGetSetDef
  ACIS_Entity_getseters_ENTITY[] =
  {
    { (char *) "name", (getter) ACIS_Entity_method_ENTITY_get_attrib_name, (setter) ACIS_Entity_method_ENTITY_set_attrib_name, (char *) "object name", NULL },
    { (char *) "id", (getter) ACIS_Entity_method_ENTITY_get_attrib_obj_id, (setter) ACIS_Entity_method_ENTITY_set_attrib_obj_id, (char *) "object id", NULL },
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Entity_members_ENTITY[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Entity_methods_ENTITY[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Entity_type_ENTITY =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.ENTITY",        /* tp_name */
    sizeof(ACIS_Entity_ENTITY),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_Entity_dealloc_ENTITY,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Entity_repr_ENTITY,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Entity_str_ENTITY,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "ACIS ENTITY class",           /* tp_doc */
    (traverseproc) ACIS_Entity_traverse_ENTITY, /* tp_traverse */
    (inquiry) ACIS_Entity_clear_ENTITY, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Entity_methods_ENTITY,             /* tp_methods */
    ACIS_Entity_members_ENTITY,             /* tp_members */
    ACIS_Entity_getseters_ENTITY,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Entity_init_ENTITY,      /* tp_init */
    0,                         /* tp_alloc */
    ACIS_Entity_new_ENTITY,                 /* tp_new */
  };

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_ENTITY();

bool ACIS_ENTITY_EXPORT _ACIS_check_ENTITY(PyObject *ob);

// Define BODY
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_BODY;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_BODY();

bool ACIS_ENTITY_EXPORT _ACIS_check_BODY(PyObject *ob);

// Define FACE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_FACE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_FACE();

bool ACIS_ENTITY_EXPORT _ACIS_check_FACE(PyObject *ob);

// Define EDGE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_EDGE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_EDGE();

bool ACIS_ENTITY_EXPORT _ACIS_check_EDGE(PyObject *ob);

// Define WIRE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_WIRE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_WIRE();

bool ACIS_ENTITY_EXPORT _ACIS_check_WIRE(PyObject *ob);

// Define LUMP
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_LUMP;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_LUMP();

bool ACIS_ENTITY_EXPORT _ACIS_check_LUMP(PyObject *ob);

// Define SHELL
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_SHELL;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_SHELL();

bool ACIS_ENTITY_EXPORT _ACIS_check_SHELL(PyObject *ob);

// Define SUBSHELL
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_SUBSHELL;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_SUBSHELL();

bool ACIS_ENTITY_EXPORT _ACIS_check_SUBSHELL(PyObject *ob);

// Define COEDGE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_COEDGE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_COEDGE();

bool ACIS_ENTITY_EXPORT _ACIS_check_COEDGE(PyObject *ob);

// Define LOOP
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_LOOP;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_LOOP();

bool ACIS_ENTITY_EXPORT _ACIS_check_LOOP(PyObject *ob);

// Define VERTEX
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_VERTEX;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_VERTEX();

bool ACIS_ENTITY_EXPORT _ACIS_check_VERTEX(PyObject *ob);

// Define SURFACE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_SURFACE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_SURFACE();

bool ACIS_ENTITY_EXPORT _ACIS_check_SURFACE(PyObject *ob);

// Define CONE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_CONE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_CONE();

bool ACIS_ENTITY_EXPORT _ACIS_check_CONE(PyObject *ob);

// Define PLANE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_PLANE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_PLANE();

bool ACIS_ENTITY_EXPORT _ACIS_check_PLANE(PyObject *ob);

// Define SPHERE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_SPHERE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_SPHERE();

bool ACIS_ENTITY_EXPORT _ACIS_check_SPHERE(PyObject *ob);

// Define SPLINE
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_SPLINE;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_SPLINE();

bool ACIS_ENTITY_EXPORT _ACIS_check_SPLINE(PyObject *ob);

// Define TORUS
typedef struct
{
  ACIS_Entity_ENTITY base_obj;
} ACIS_Entity_TORUS;

PyObject ACIS_ENTITY_EXPORT *_ACIS_new_TORUS();

bool ACIS_ENTITY_EXPORT _ACIS_check_TORUS(PyObject *ob);


// Additional functions

/**
 * Sets the internal ocis_obj variable to NULL
 * @param ob Topology object, such as ENTITY, BODY, FACE, etc.
 */
void ACIS_ENTITY_EXPORT _ACIS_make_null(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_ENTITY_H
