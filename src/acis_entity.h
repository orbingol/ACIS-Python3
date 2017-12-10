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
} a3dp_ENTITY;

int a3dp_ENTITY_traverse(a3dp_ENTITY *self, visitproc visit, void *arg);
int a3dp_ENTITY_clear(a3dp_ENTITY *self);
void a3dp_ENTITY_dealloc(a3dp_ENTITY *self);
PyObject *a3dp_ENTITY_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_ENTITY_init(a3dp_ENTITY *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_ENTITY_repr(a3dp_ENTITY *self);
PyObject *a3dp_ENTITY_str(a3dp_ENTITY *self);
PyObject *a3dp_ENTITY_get_attrib_name(a3dp_ENTITY *self, PyObject *value, void *closure);
int a3dp_ENTITY_set_attrib_name(a3dp_ENTITY *self, PyObject *value, void *closure);
PyObject *a3dp_ENTITY_get_attrib_obj_id(a3dp_ENTITY *self, PyObject *value, void *closure);
int a3dp_ENTITY_set_attrib_obj_id(a3dp_ENTITY *self, PyObject *value, void *closure);
PyObject *a3dp_ENTITY_type_name(PyObject *self);

static PyGetSetDef
  a3dp_getseters_ENTITY[] =
  {
    { (char *) "name", (getter) a3dp_ENTITY_get_attrib_name, (setter) a3dp_ENTITY_set_attrib_name, (char *) "object name", NULL },
    { (char *) "id", (getter) a3dp_ENTITY_get_attrib_obj_id, (setter) a3dp_ENTITY_set_attrib_obj_id, (char *) "object id", NULL },
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  a3dp_methods_ENTITY[] =
  {
	  { "type_name", (PyCFunction) a3dp_ENTITY_type_name, METH_NOARGS, "Returns a name for this ENTITY's type" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_ENTITY =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.ENTITY",        /* tp_name */
    sizeof(a3dp_ENTITY),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) a3dp_ENTITY_dealloc,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_ENTITY_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_ENTITY_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "ACIS ENTITY class",           /* tp_doc */
    (traverseproc) a3dp_ENTITY_traverse, /* tp_traverse */
    (inquiry) a3dp_ENTITY_clear, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_ENTITY,             /* tp_methods */
    0,             /* tp_members */
    a3dp_getseters_ENTITY,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_ENTITY_init,      /* tp_init */
    0,                         /* tp_alloc */
    a3dp_ENTITY_new,                 /* tp_new */
  };

PyObject *_PyNew_ENTITY();

bool _PyCheck_ENTITY(PyObject *ob);

// Define BODY
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_BODY;

int a3dp_BODY_init(a3dp_BODY *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_BODY_repr(a3dp_BODY *self);
PyObject *a3dp_BODY_str(a3dp_BODY *self);

static PyTypeObject
  a3dp_type_BODY =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.BODY",        /* tp_name */
    sizeof(a3dp_BODY),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_BODY_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_BODY_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS BODY class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_BODY_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


PyObject *_PyNew_BODY();

bool _PyCheck_BODY(PyObject *ob);

// Define FACE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_FACE;

int a3dp_FACE_init(a3dp_FACE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_FACE_repr(a3dp_FACE *self);
PyObject *a3dp_FACE_str(a3dp_FACE *self);
PyObject *a3dp_FACE__sense(a3dp_FACE *self);
PyObject *a3dp_FACE__geometry(a3dp_FACE *self);

static PyMethodDef
  a3dp_methods_FACE[] =
  {
    { "sense", (PyCFunction) a3dp_FACE__sense, METH_NOARGS, "Returns the sense of this FACE relative to its SURFACE" },
    { "geometry", (PyCFunction) a3dp_FACE__geometry, METH_NOARGS, "Returns a pointer to the underlying SURFACE defining this FACE" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_FACE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.FACE",        /* tp_name */
    sizeof(a3dp_FACE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_FACE_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_FACE_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS FACE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_FACE,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_FACE_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_FACE();

bool _PyCheck_FACE(PyObject *ob);

// Define EDGE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_EDGE;

int a3dp_EDGE_init(a3dp_EDGE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_EDGE_repr(a3dp_EDGE *self);
PyObject *a3dp_EDGE_str(a3dp_EDGE *self);

static PyTypeObject
  a3dp_type_EDGE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.EDGE",        /* tp_name */
    sizeof(a3dp_EDGE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_EDGE_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_EDGE_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS EDGE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_EDGE_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_EDGE();

bool _PyCheck_EDGE(PyObject *ob);

// Define WIRE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_WIRE;

int a3dp_WIRE_init(a3dp_WIRE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_WIRE_repr(a3dp_WIRE *self);
PyObject *a3dp_WIRE_str(a3dp_WIRE *self);

static PyTypeObject
  a3dp_type_WIRE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.WIRE",        /* tp_name */
    sizeof(a3dp_WIRE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_WIRE_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_WIRE_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS WIRE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_WIRE_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_WIRE();

bool _PyCheck_WIRE(PyObject *ob);

// Define LUMP
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_LUMP;

int a3dp_LUMP_init(a3dp_LUMP *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_LUMP_repr(a3dp_LUMP *self);
PyObject *a3dp_LUMP_str(a3dp_LUMP *self);

static PyTypeObject
  a3dp_type_LUMP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.LUMP",        /* tp_name */
    sizeof(a3dp_LUMP),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_LUMP_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_LUMP_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS LUMP class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_LUMP_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


PyObject *_PyNew_LUMP();

bool _PyCheck_LUMP(PyObject *ob);

// Define SHELL
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SHELL;

int a3dp_SHELL_init(a3dp_SHELL *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SHELL_repr(a3dp_SHELL *self);
PyObject *a3dp_SHELL_str(a3dp_SHELL *self);

static PyTypeObject
  a3dp_type_SHELL =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SHELL",        /* tp_name */
    sizeof(a3dp_SHELL),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_SHELL_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_SHELL_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SHELL class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_SHELL_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_SHELL();

bool _PyCheck_SHELL(PyObject *ob);

// Define SUBSHELL
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SUBSHELL;

int a3dp_SUBSHELL_init(a3dp_SUBSHELL *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SUBSHELL_repr(a3dp_SUBSHELL *self);
PyObject *a3dp_SUBSHELL_str(a3dp_SUBSHELL *self);

static PyTypeObject
  a3dp_type_SUBSHELL =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SUBSHELL",        /* tp_name */
    sizeof(a3dp_SUBSHELL),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_SUBSHELL_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_SUBSHELL_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SUBSHELL class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_SUBSHELL_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_SUBSHELL();

bool _PyCheck_SUBSHELL(PyObject *ob);

// Define COEDGE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_COEDGE;

int a3dp_COEDGE_init(a3dp_COEDGE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_COEDGE_repr(a3dp_COEDGE *self);
PyObject *a3dp_COEDGE_str(a3dp_COEDGE *self);

static PyTypeObject
  a3dp_type_COEDGE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.COEDGE",        /* tp_name */
    sizeof(a3dp_COEDGE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_COEDGE_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_COEDGE_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS COEDGE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_COEDGE_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_COEDGE();

bool _PyCheck_COEDGE(PyObject *ob);

// Define LOOP
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_LOOP;

int a3dp_LOOP_init(a3dp_LOOP *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_LOOP_repr(a3dp_LOOP *self);
PyObject *a3dp_LOOP_str(a3dp_LOOP *self);

static PyTypeObject
  a3dp_type_LOOP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.LOOP",        /* tp_name */
    sizeof(a3dp_LOOP),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_LOOP_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_LOOP_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS LOOP class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_LOOP_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_LOOP();

bool _PyCheck_LOOP(PyObject *ob);

// Define VERTEX
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_VERTEX;

int a3dp_VERTEX_init(a3dp_VERTEX *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_VERTEX_repr(a3dp_VERTEX *self);
PyObject *a3dp_VERTEX_str(a3dp_VERTEX *self);

static PyTypeObject
  a3dp_type_VERTEX =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.VERTEX",        /* tp_name */
    sizeof(a3dp_VERTEX),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_VERTEX_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_VERTEX_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS VERTEX class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_VERTEX_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_VERTEX();

bool _PyCheck_VERTEX(PyObject *ob);

// Define SURFACE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SURFACE;

int a3dp_SURFACE_init(a3dp_SURFACE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SURFACE_repr(a3dp_SURFACE *self);
PyObject *a3dp_SURFACE_str(a3dp_SURFACE *self);
PyObject *a3dp_SURFACE__equation(a3dp_SURFACE *self);
PyObject *a3dp_SURFACE__trans_surface(a3dp_SURFACE *self, PyObject *args, PyObject *kwargs);

static PyMethodDef
  a3dp_methods_SURFACE[] =
  {
    { "equation", (PyCFunction) a3dp_SURFACE__equation, METH_NOARGS, "Returns the equation of this SURFACE" },
    { "trans_surface", (PyCFunction) a3dp_SURFACE__trans_surface, METH_VARARGS | METH_KEYWORDS, "Returns the transformed surface" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_SURFACE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SURFACE",        /* tp_name */
    sizeof(a3dp_SURFACE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) a3dp_SURFACE_repr,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) a3dp_SURFACE_str,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SURFACE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_SURFACE,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_SURFACE_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };

PyObject *_PyNew_SURFACE();

bool _PyCheck_SURFACE(PyObject *ob);

// Define CONE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_CONE;

int a3dp_CONE_init(a3dp_CONE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_CONE_repr(a3dp_CONE *self);
PyObject *a3dp_CONE_str(a3dp_CONE *self);

static PyTypeObject
    a3dp_type_CONE =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.CONE",        /* tp_name */
        sizeof(a3dp_CONE),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        0,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_CONE_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_CONE_str,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "ACIS CONE class",           /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_CONE_init,      /* tp_init */
        0,                         /* tp_alloc */
        0,                 /* tp_new */
    };

PyObject *_PyNew_CONE();

bool _PyCheck_CONE(PyObject *ob);

// Define PLANE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_PLANE;

int a3dp_PLANE_init(a3dp_PLANE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_PLANE_repr(a3dp_PLANE *self);
PyObject *a3dp_PLANE_str(a3dp_PLANE *self);

static PyTypeObject
    a3dp_type_PLANE =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.PLANE",        /* tp_name */
        sizeof(a3dp_PLANE),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        0,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_PLANE_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_PLANE_str,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,        /* tp_flags */
        "ACIS PLANE class",           /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_PLANE_init,      /* tp_init */
        0,                         /* tp_alloc */
        0,                 /* tp_new */
    };

PyObject *_PyNew_PLANE();

bool _PyCheck_PLANE(PyObject *ob);

// Define SPHERE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SPHERE;

int a3dp_SPHERE_init(a3dp_SPHERE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPHERE_repr(a3dp_SPHERE *self);
PyObject *a3dp_SPHERE_str(a3dp_SPHERE *self);

static PyTypeObject
    a3dp_type_SPHERE =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPHERE",        /* tp_name */
        sizeof(a3dp_SPHERE),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        0,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPHERE_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPHERE_str,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "ACIS SPHERE class",           /* tp_doc */
        0, /* tp_traverse */
        0, /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPHERE_init,      /* tp_init */
        0,                         /* tp_alloc */
        0,                 /* tp_new */
    };

PyObject *_PyNew_SPHERE();

bool _PyCheck_SPHERE(PyObject *ob);

// Define SPLINE
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_SPLINE;

int a3dp_SPLINE_init(a3dp_SPLINE *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPLINE_repr(a3dp_SPLINE *self);
PyObject *a3dp_SPLINE_str(a3dp_SPLINE *self);

static PyTypeObject
    a3dp_type_SPLINE =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPLINE",        /* tp_name */
        sizeof(a3dp_SPLINE),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        0,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPLINE_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPLINE_str,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "ACIS SPLINE class",           /* tp_doc */
        0, /* tp_traverse */
        0, /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPLINE_init,      /* tp_init */
        0,                         /* tp_alloc */
        0,                 /* tp_new */
    };


PyObject *_PyNew_SPLINE();

bool _PyCheck_SPLINE(PyObject *ob);

// Define TORUS
typedef struct
{
  a3dp_ENTITY base_obj;
} a3dp_TORUS;

int a3dp_TORUS_init(a3dp_TORUS *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_TORUS_repr(a3dp_TORUS *self);
PyObject *a3dp_TORUS_str(a3dp_TORUS *self);

static PyTypeObject
    a3dp_type_TORUS =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.TORUS",        /* tp_name */
        sizeof(a3dp_TORUS),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        0,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_TORUS_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_TORUS_str,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "ACIS TORUS class",           /* tp_doc */
        0, /* tp_traverse */
        0, /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_TORUS_init,      /* tp_init */
        0,                         /* tp_alloc */
        0,                 /* tp_new */
    };

PyObject *_PyNew_TORUS();

bool _PyCheck_TORUS(PyObject *ob);

// Define surface
typedef struct
{
  surface* _acis_obj;
} a3dp_surface;

void a3dp_surface_dealloc(a3dp_surface *self);
PyObject *a3dp_surface_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_surface_init(a3dp_surface *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_surface__eval_normal(a3dp_surface *self, PyObject *arg);
PyObject *a3dp_surface__eval_position(a3dp_surface *self, PyObject *arg);

static PyMethodDef
  a3dp_methods_surface[] =
  {
    { "eval_normal", (PyCFunction) a3dp_surface__eval_normal, METH_O, "Finds the normal to a parametric surface at the point with the given parameter position" },
    { "eval_position", (PyCFunction) a3dp_surface__eval_position, METH_O, "Finds the point on a parametric surface with the given parameter position" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_surface =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.surface",        /* tp_name */
    sizeof(a3dp_surface),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) a3dp_surface_dealloc,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "ACIS surface class",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_surface,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_surface_init,      /* tp_init */
    0,                         /* tp_alloc */
    a3dp_surface_new,                 /* tp_new */
  };

PyObject *_PyNew_surface();

bool _PyCheck_surface(PyObject *ob);

// Define ENTITY_LIST
typedef struct
{
  PyObject_HEAD
  ENTITY_LIST *_acis_obj;
} a3dp_ENTITY_LIST;

void a3dp_ENTITYLIST_dealloc(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_ENTITYLIST_init(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__init(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__clear(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__add(a3dp_ENTITY_LIST *self, PyObject *arg);
PyObject *a3dp_ENTITYLIST__remove(a3dp_ENTITY_LIST *self, PyObject *arg);
PyObject *a3dp_ENTITYLIST__count(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__iteration_count(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__reverse(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__lookup(a3dp_ENTITY_LIST *self, PyObject *arg);
PyObject *a3dp_ENTITYLIST__byte_count(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__first(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__next(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST__next_from(a3dp_ENTITY_LIST *self, PyObject *arg);
PyObject *a3dp_ENTITYLIST__array(a3dp_ENTITY_LIST *self);
PyObject *a3dp_ENTITYLIST_iter(PyObject *self);
PyObject *a3dp_ENTITYLIST_iter_next(PyObject *self);

static PyMethodDef
    a3dp_methods_ENTITY_LIST[] =
    {
        { "add", (PyCFunction) a3dp_ENTITYLIST__add, METH_O, "Adds an entity or entities to the list" },
        { "remove", (PyCFunction) a3dp_ENTITYLIST__remove, METH_O, "Removes an entity or entities from the list" },
        { "count", (PyCFunction) a3dp_ENTITYLIST__count, METH_NOARGS, "Returns the number of entries in the list including the deleted ones (tombstones)" },
        { "iteration_count", (PyCFunction) a3dp_ENTITYLIST__iteration_count, METH_NOARGS, "Returns the number of live entities in the list not including deleted entries" },
        { "init", (PyCFunction) a3dp_ENTITYLIST__init, METH_NOARGS, "Adds an entity or entities to the list" },
        { "clear", (PyCFunction) a3dp_ENTITYLIST__clear, METH_NOARGS, "Clear all entries from the list and reset indexes and counters for reuse" },
        { "lookup", (PyCFunction) a3dp_ENTITYLIST__lookup, METH_O, "Adds an entity or entities to the list" },
        { "reverse", (PyCFunction) a3dp_ENTITYLIST__reverse, METH_NOARGS, "Adds an entity or entities to the list" },
        { "byte_count", (PyCFunction) a3dp_ENTITYLIST__byte_count, METH_NOARGS, "Returns the size in bytes of this class" },
        { "first", (PyCFunction) a3dp_ENTITYLIST__first, METH_NOARGS, "Initializes the iterator, which is used by the next method, to the beginning of the list" },
        { "next", (PyCFunction) a3dp_ENTITYLIST__next, METH_NOARGS, "Returns the next undeleted (live) entry" },
        { "next_from", (PyCFunction) a3dp_ENTITYLIST__next_from, METH_O, "Returns the next non deleted entry after the index given without affecting the member variables used by init and next" },
        { "array", (PyCFunction) a3dp_ENTITYLIST__array, METH_NOARGS, "Gets an array of the entities in the list (creates a Python generator)" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_ENTITYLIST =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.ENTITY_LIST",        /* tp_name */
        sizeof(a3dp_ENTITY_LIST),    /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_ENTITYLIST_dealloc,                         /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        0,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        0,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "ACIS ENTITY_LIST class",           /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        (getiterfunc) a3dp_ENTITYLIST_iter,                         /* tp_iter */
        (iternextfunc) a3dp_ENTITYLIST_iter_next,                         /* tp_iternext */
        a3dp_methods_ENTITY_LIST,             /* tp_methods */
        0,             /* tp_members */
        0,                         /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_ENTITYLIST_init,      /* tp_init */
        0,                         /* tp_alloc */
        a3dp_ENTITYLIST_new,                 /* tp_new */
    };

PyObject *_PyNew_ENTITY_LIST();

bool _PyCheck_ENTITY_LIST(PyObject *ob);

PyObject *__convert_entity(ENTITY *ent);


// Additional functions

/**
 * Sets the internal ocis_obj variable to NULL
 * @param ob Topology object, such as ENTITY, BODY, FACE, etc.
 */
void _a3dp_make_null(PyObject *ob);

void _a3dp_set_entity(PyObject *ob, ENTITY *ent);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_ENTITY_H
