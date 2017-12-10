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

#ifndef A3DPY_CLASSES_H
#define A3DPY_CLASSES_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "utilities.h"


#ifdef __cplusplus
extern "C" {
#endif

// Define SPAposition
typedef struct
{
  PyObject_HEAD
  SPAposition *_acis_obj;
} a3dp_SPAposition;

void a3dp_SPAposition_dealloc(a3dp_SPAposition *self);
PyObject *a3dp_SPAposition_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAposition_init(a3dp_SPAposition *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAposition_repr(a3dp_SPAposition *self);
PyObject *a3dp_SPAposition__coordinate(a3dp_SPAposition *self, PyObject *arg);
PyObject *a3dp_SPAposition__set_coordinate(a3dp_SPAposition *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAposition__set_x(a3dp_SPAposition *self, PyObject *arg);
PyObject *a3dp_SPAposition__set_y(a3dp_SPAposition *self, PyObject *arg);
PyObject *a3dp_SPAposition__set_z(a3dp_SPAposition *self, PyObject *arg);
PyObject *a3dp_SPAposition__x(a3dp_SPAposition *self);
PyObject *a3dp_SPAposition__y(a3dp_SPAposition *self);
PyObject *a3dp_SPAposition__z(a3dp_SPAposition *self);
PyObject *a3dp_SPAposition_x_getter(a3dp_SPAposition *self, PyObject *value, void *closure);
PyObject *a3dp_SPAposition_y_getter(a3dp_SPAposition *self, PyObject *value, void *closure);
PyObject *a3dp_SPAposition_z_getter(a3dp_SPAposition *self, PyObject *value, void *closure);
int a3dp_SPAposition_x_setter(a3dp_SPAposition *self, PyObject *value, void *closure);
int a3dp_SPAposition_y_setter(a3dp_SPAposition *self, PyObject *value, void *closure);
int a3dp_SPAposition_z_setter(a3dp_SPAposition *self, PyObject *value, void *closure);

static PyGetSetDef
    a3dp_getseters_SPAposition[] =
    {
        { (char *) "x_value", (getter) a3dp_SPAposition_x_getter, (setter) a3dp_SPAposition_x_setter, (char *) "value of the x-coordinate", NULL },
        { (char *) "y_value", (getter) a3dp_SPAposition_y_getter, (setter) a3dp_SPAposition_y_setter, (char *) "value of the y-coordinate", NULL },
        { (char *) "z_value", (getter) a3dp_SPAposition_z_getter, (setter) a3dp_SPAposition_z_setter, (char *) "value of the z-coordinate", NULL },
        { NULL }  /* Sentinel */
    };

static PyMethodDef
    a3dp_methods_SPAposition[] =
    {
        { "coordinate", (PyCFunction) a3dp_SPAposition__coordinate, METH_O, "Returns the i-th component value" },
        { "set_coordinate", (PyCFunction) a3dp_SPAposition__set_coordinate, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component value" },
        { "set_x", (PyCFunction) a3dp_SPAposition__set_x, METH_O, "Sets the x-coordinate value" },
        { "set_y", (PyCFunction) a3dp_SPAposition__set_x, METH_O, "Sets the y-coordinate value" },
        { "set_z", (PyCFunction) a3dp_SPAposition__set_x, METH_O, "Sets the z-coordinate value" },
        { "x", (PyCFunction) a3dp_SPAposition__x, METH_NOARGS, "Returns the x-coordinate value" },
        { "y", (PyCFunction) a3dp_SPAposition__y, METH_NOARGS, "Returns the y-coordinate value" },
        { "z", (PyCFunction) a3dp_SPAposition__z, METH_NOARGS, "Returns the z-coordinate value" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAposition =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAposition",             /* tp_name */
        sizeof(a3dp_SPAposition), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAposition_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPAposition_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPAposition_repr,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,        /* tp_flags */
        "SPAposition represents position vectors (points) in 3D Cartesian space that are subject to certain vector and transformation operations", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        a3dp_methods_SPAposition, /* tp_methods */
        0, /* tp_members */
        a3dp_getseters_SPAposition, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAposition_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAposition_new, /* tp_new */
    };


PyObject *_PyNew_SPAposition();

bool _PyCheck_SPAposition(PyObject *ob);

// Define SPAvector
typedef struct
{
  PyObject_HEAD
  SPAvector *_acis_obj;
} a3dp_SPAvector;

void a3dp_SPAvector_dealloc(a3dp_SPAvector *self);
PyObject *a3dp_SPAvector_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAvector_init(a3dp_SPAvector *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAvector_repr(a3dp_SPAvector *self);
PyObject *a3dp_SPAvector__component(a3dp_SPAvector *self, PyObject *arg);
PyObject *a3dp_SPAvector__set_component(a3dp_SPAvector *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAvector__set_x(a3dp_SPAvector *self, PyObject *arg);
PyObject *a3dp_SPAvector__set_y(a3dp_SPAvector *self, PyObject *arg);
PyObject *a3dp_SPAvector__set_z(a3dp_SPAvector *self, PyObject *arg);
PyObject *a3dp_SPAvector__x(a3dp_SPAvector *self);
PyObject *a3dp_SPAvector__y(a3dp_SPAvector *self);
PyObject *a3dp_SPAvector__z(a3dp_SPAvector *self);
PyObject *a3dp_SPAvector_x_getter(a3dp_SPAvector *self, PyObject *value, void *closure);
PyObject *a3dp_SPAvector_y_getter(a3dp_SPAvector *self, PyObject *value, void *closure);
PyObject *a3dp_SPAvector_z_getter(a3dp_SPAvector *self, PyObject *value, void *closure);
int a3dp_SPAvector_x_setter(a3dp_SPAvector *self, PyObject *value, void *closure);
int a3dp_SPAvector_y_setter(a3dp_SPAvector *self, PyObject *value, void *closure);
int a3dp_SPAvector_z_setter(a3dp_SPAvector *self, PyObject *value, void *closure);

static PyGetSetDef
    a3dp_getseters_SPAvector[] =
    {
        { (char *) "x_value", (getter) a3dp_SPAvector_x_getter, (setter) a3dp_SPAvector_x_setter, (char *) "value of the x component", NULL },
        { (char *) "y_value", (getter) a3dp_SPAvector_y_getter, (setter) a3dp_SPAvector_y_setter, (char *) "value of the y component", NULL },
        { (char *) "z_value", (getter) a3dp_SPAvector_z_getter, (setter) a3dp_SPAvector_z_setter, (char *) "value of the z component", NULL },
        { NULL }  /* Sentinel */
    };

static PyMethodDef
    a3dp_methods_SPAvector[] =
    {
        { "component", (PyCFunction) a3dp_SPAvector__component, METH_O, "Returns the i-th component of the vector" },
        { "set_component", (PyCFunction) a3dp_SPAvector__set_component, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component of the vector" },
        { "set_x", (PyCFunction) a3dp_SPAvector__set_x, METH_O, "Sets the x-component of the vector" },
        { "set_y", (PyCFunction) a3dp_SPAvector__set_x, METH_O, "Sets the y-component of the vector" },
        { "set_z", (PyCFunction) a3dp_SPAvector__set_x, METH_O, "Sets the z-component of the vector" },
        { "x", (PyCFunction) a3dp_SPAvector__x, METH_NOARGS, "Returns the x-component of the vector" },
        { "y", (PyCFunction) a3dp_SPAvector__y, METH_NOARGS, "Returns the y-component of the vector" },
        { "z", (PyCFunction) a3dp_SPAvector__z, METH_NOARGS, "Returns the z-component of the vector" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAvector =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAvector",             /* tp_name */
        sizeof(a3dp_SPAvector), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAvector_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPAvector_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPAvector_repr,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,        /* tp_flags */
        "SPAvector represents a displacement vector in 3D Cartesian space", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        a3dp_methods_SPAvector, /* tp_methods */
        0, /* tp_members */
        a3dp_getseters_SPAvector, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAvector_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAvector_new, /* tp_new */
    };

PyObject *_PyNew_SPAvector();

bool _PyCheck_SPAvector(PyObject *ob);

// Define SPAunit_vector
typedef struct
{
  PyObject_HEAD
  SPAunit_vector *_acis_obj;
} a3dp_SPAunit_vector;

void a3dp_SPAunitvector_dealloc(a3dp_SPAunit_vector *self);
PyObject *a3dp_SPAunitvector_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAunitvector_init(a3dp_SPAunit_vector *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAunitvector_repr(a3dp_SPAunit_vector *self);
PyObject *a3dp_SPAunitvector__component(a3dp_SPAunit_vector *self, PyObject *arg);
PyObject *a3dp_SPAunitvector__set_component(a3dp_SPAunit_vector *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAunitvector__set_x(a3dp_SPAunit_vector *self, PyObject *arg);
PyObject *a3dp_SPAunitvector__set_y(a3dp_SPAunit_vector *self, PyObject *arg);
PyObject *a3dp_SPAunitvector__set_z(a3dp_SPAunit_vector *self, PyObject *arg);
PyObject *a3dp_SPAunitvector__x(a3dp_SPAunit_vector *self);
PyObject *a3dp_SPAunitvector__y(a3dp_SPAunit_vector *self);
PyObject *a3dp_SPAunitvector__z(a3dp_SPAunit_vector *self);
PyObject *a3dp_SPAunitvector_x_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);
PyObject *a3dp_SPAunitvector_y_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);
PyObject *a3dp_SPAunitvector_z_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);
int a3dp_SPAunitvector_x_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);
int a3dp_SPAunitvector_y_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);
int a3dp_SPAunitvector_z_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure);

static PyGetSetDef
    a3dp_getseters_SPAunit_vector[] =
    {
        { (char *) "x_value", (getter) a3dp_SPAunitvector_x_getter, (setter) a3dp_SPAunitvector_x_setter, (char *) "value of the x component", NULL },
        { (char *) "y_value", (getter) a3dp_SPAunitvector_y_getter, (setter) a3dp_SPAunitvector_y_setter, (char *) "value of the y component", NULL },
        { (char *) "z_value", (getter) a3dp_SPAunitvector_z_getter, (setter) a3dp_SPAunitvector_z_setter, (char *) "value of the z component", NULL },
        { NULL }  /* Sentinel */
    };

static PyMethodDef
    a3dp_methods_SPAunit_vector[] =
    {
        { "component", (PyCFunction) a3dp_SPAunitvector__component, METH_O, "Returns the i-th component of the vector" },
        { "set_component", (PyCFunction) a3dp_SPAunitvector__set_component, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component of the vector" },
        { "set_x", (PyCFunction) a3dp_SPAunitvector__set_x, METH_O, "Sets the x-component of the vector" },
        { "set_y", (PyCFunction) a3dp_SPAunitvector__set_x, METH_O, "Sets the y-component of the vector" },
        { "set_z", (PyCFunction) a3dp_SPAunitvector__set_x, METH_O, "Sets the z-component of the vector" },
        { "x", (PyCFunction) a3dp_SPAunitvector__x, METH_NOARGS, "Returns the x-component of the vector" },
        { "y", (PyCFunction) a3dp_SPAunitvector__y, METH_NOARGS, "Returns the y-component of the vector" },
        { "z", (PyCFunction) a3dp_SPAunitvector__z, METH_NOARGS, "Returns the z-component of the vector" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAunitvector =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAunit_vector",             /* tp_name */
        sizeof(a3dp_SPAunit_vector), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAunitvector_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPAunitvector_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPAunitvector_repr,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,        /* tp_flags */
        "SPAunit_vector provides a direction in 3D Cartesian space that has unit length", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        a3dp_methods_SPAunit_vector, /* tp_methods */
        0, /* tp_members */
        a3dp_getseters_SPAunit_vector, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAunitvector_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAunitvector_new, /* tp_new */
    };

PyObject *_PyNew_SPAunit_vector();

bool _PyCheck_SPAunit_vector(PyObject *ob);

// Define SPAmatrix
typedef struct
{
  PyObject_HEAD
  SPAmatrix *_acis_obj;
} a3dp_SPAmatrix;

void a3dp_SPAmatrix_dealloc(a3dp_SPAmatrix *self);
PyObject *a3dp_SPAmatrix_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAmatrix_init(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAmatrix__column(a3dp_SPAmatrix *self, PyObject *arg);
PyObject *a3dp_SPAmatrix__row(a3dp_SPAmatrix *self, PyObject *arg);
PyObject *a3dp_SPAmatrix__inverse(a3dp_SPAmatrix *self);
PyObject *a3dp_SPAmatrix__transpose(a3dp_SPAmatrix *self);
PyObject *a3dp_SPAmatrix__determinant(a3dp_SPAmatrix *self);
PyObject *a3dp_SPAmatrix__element(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAmatrix__set_element(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAmatrix__is_identity(a3dp_SPAmatrix *self);

static PyMethodDef
    a3dp_methods_SPAmatrix[] =
    {
        { "column", (PyCFunction) a3dp_SPAmatrix__column, METH_O, "Extracts a column from this matrix" },
        { "row", (PyCFunction) a3dp_SPAmatrix__row, METH_O, "Extracts a row from this matrix" },
        { "element", (PyCFunction) a3dp_SPAmatrix__element, METH_VARARGS | METH_KEYWORDS, "Extracts an element of this matrix" },
        { "set_element", (PyCFunction) a3dp_SPAmatrix__set_element, METH_VARARGS | METH_KEYWORDS, "Assigns a value to an element in the matrix" },
        { "determinant", (PyCFunction) a3dp_SPAmatrix__determinant, METH_NOARGS, "Returns the determinant of this matrix" },
        { "transpose", (PyCFunction) a3dp_SPAmatrix__transpose, METH_NOARGS, "Returns a transpose of this matrix" },
        { "inverse", (PyCFunction) a3dp_SPAmatrix__inverse, METH_NOARGS, "Returns the inverse of this matrix" },
        { "is_identity", (PyCFunction) a3dp_SPAmatrix__is_identity, METH_NOARGS, "Returns TRUE if this matrix is the identity matrix" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAmatrix =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAmatrix",             /* tp_name */
        sizeof(a3dp_SPAmatrix), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAmatrix_dealloc, /* tp_dealloc */
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
        "SPAmatrix defines a 3x3 affine transformation acting on vectors and positions", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        a3dp_methods_SPAmatrix, /* tp_methods */
        0, /* tp_members */
        0, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAmatrix_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAmatrix_new, /* tp_new */
    };

PyObject *_PyNew_SPAmatrix();

bool _PyCheck_SPAmatrix(PyObject *ob);

// Define SPAtransf
typedef struct
{
  PyObject_HEAD
  SPAtransf *_acis_obj;
} a3dp_SPAtransf;

void a3dp_SPAtransf_dealloc(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAtransf_init(a3dp_SPAtransf *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAtransf__affine(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__inverse(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__translation(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__identity(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__reflect(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__rotate(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__scaling(a3dp_SPAtransf *self);
PyObject *a3dp_SPAtransf__shear(a3dp_SPAtransf *self);

static PyMethodDef
    a3dp_methods_SPAtransf[] =
    {
        { "affine", (PyCFunction) a3dp_SPAtransf__affine, METH_NOARGS, "Returns the affine portion of the transformation" },
        { "inverse", (PyCFunction) a3dp_SPAtransf__inverse, METH_NOARGS, "Returns the inverse transformation" },
        { "translation", (PyCFunction) a3dp_SPAtransf__translation, METH_NOARGS, "Returns the vector representing the translational portion of the transformation" },
        { "identity", (PyCFunction) a3dp_SPAtransf__identity, METH_NOARGS, "Queries whether or not the transformation is the identity" },
        { "reflect", (PyCFunction) a3dp_SPAtransf__reflect, METH_NOARGS, "Queries whether or not the transformation is reflecting" },
        { "rotate", (PyCFunction) a3dp_SPAtransf__rotate, METH_NOARGS, "Queries whether or not the transformation has a rotational component" },
        { "scaling", (PyCFunction) a3dp_SPAtransf__scaling, METH_NOARGS, "Returns the scaling factor of the transformation" },
        { "shear", (PyCFunction) a3dp_SPAtransf__shear, METH_NOARGS, "Queries whether or not the transformation has a shearing component" },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAtransf =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAtransf",             /* tp_name */
        sizeof(a3dp_SPAtransf), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAtransf_dealloc, /* tp_dealloc */
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
        "SPAtransf represents a general 3D affine transformation", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        a3dp_methods_SPAtransf, /* tp_methods */
        0, /* tp_members */
        0, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAtransf_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAtransf_new, /* tp_new */
    };

PyObject *_PyNew_SPAtransf();

bool _PyCheck_SPAtransf(PyObject *ob);

// Define SPApar_pos
typedef struct
{
  PyObject_HEAD
  SPApar_pos *_acis_obj;
} a3dp_SPApar_pos;

void a3dp_SPAparpos_dealloc(a3dp_SPApar_pos *self);
PyObject *a3dp_SPAparpos_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAparpos_init(a3dp_SPApar_pos *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAparpos_repr(a3dp_SPApar_pos *self);
PyObject *a3dp_SPAparpos_u_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure);
int a3dp_SPAparpos_u_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure);
PyObject *a3dp_SPAparpos_v_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure);
int a3dp_SPAparpos_v_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure);

static PyGetSetDef
    a3dp_getseters_SPAparpos[] =
    {
        { (char *) "u", (getter) a3dp_SPAparpos_u_getter, (setter) a3dp_SPAparpos_u_setter, (char *) "value of the u parameter", NULL },
        { (char *) "v", (getter) a3dp_SPAparpos_v_getter, (setter) a3dp_SPAparpos_v_setter, (char *) "value of the v parameter", NULL },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAparpos =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPAtransf",             /* tp_name */
        sizeof(a3dp_SPApar_pos), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAparpos_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPAparpos_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPAparpos_repr,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "SPApar_pos defines a parameter position in the parameter-space of a surface", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0, /* tp_methods */
        0, /* tp_members */
        a3dp_getseters_SPAparpos, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAparpos_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAparpos_new, /* tp_new */
    };

PyObject *_PyNew_SPApar_pos();

bool _PyCheck_SPApar_pos(PyObject *ob);

// Define SPApar_vec
typedef struct
{
  PyObject_HEAD
  SPApar_vec *_acis_obj;
} a3dp_SPApar_vec;

void a3dp_SPAparvec_dealloc(a3dp_SPApar_vec *self);
PyObject *a3dp_SPAparvec_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_SPAparvec_init(a3dp_SPApar_vec *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_SPAparvec_repr(a3dp_SPApar_vec *self);
PyObject *a3dp_SPAparvec_du_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure);
int a3dp_SPAparvec_du_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure);
PyObject *a3dp_SPAparvec_dv_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure);
int a3dp_SPAparvec_dv_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure);

static PyGetSetDef
    a3dp_getseters_SPAparvec[] =
    {
        { (char *) "du", (getter) a3dp_SPAparvec_du_getter, (setter) a3dp_SPAparvec_du_setter, (char *) "value of the u parameter", NULL },
        { (char *) "dv", (getter) a3dp_SPAparvec_dv_getter, (setter) a3dp_SPAparvec_dv_setter, (char *) "value of the v parameter", NULL },
        { NULL }  /* Sentinel */
    };

static PyTypeObject
    a3dp_type_SPAparvec =
    {
        PyVarObject_HEAD_INIT(NULL, 0)
        "ACIS.SPApar_vec",             /* tp_name */
        sizeof(a3dp_SPApar_vec), /* tp_basicsize */
        0,                         /* tp_itemsize */
        (destructor) a3dp_SPAparvec_dealloc, /* tp_dealloc */
        0,                         /* tp_print */
        0,                         /* tp_getattr */
        0,                         /* tp_setattr */
        0,                         /* tp_reserved */
        (reprfunc) a3dp_SPAparvec_repr,                         /* tp_repr */
        0,                         /* tp_as_number */
        0,                         /* tp_as_sequence */
        0,                         /* tp_as_mapping */
        0,                         /* tp_hash  */
        0,                         /* tp_call */
        (reprfunc) a3dp_SPAparvec_repr,                         /* tp_str */
        0,                         /* tp_getattro */
        0,                         /* tp_setattro */
        0,                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,   /* tp_flags */
        "SPApar_vec defines a vector (du, dv) in 2D parameter-space", /* tp_doc */
        0,                         /* tp_traverse */
        0,                         /* tp_clear */
        0,                         /* tp_richcompare */
        0,                         /* tp_weaklistoffset */
        0,                         /* tp_iter */
        0,                         /* tp_iternext */
        0, /* tp_methods */
        0, /* tp_members */
        a3dp_getseters_SPAparvec, /* tp_getset */
        0,                         /* tp_base */
        0,                         /* tp_dict */
        0,                         /* tp_descr_get */
        0,                         /* tp_descr_set */
        0,                         /* tp_dictoffset */
        (initproc) a3dp_SPAparvec_init, /* tp_init */
        0,                         /* tp_alloc */
        a3dp_SPAparvec_new, /* tp_new */
    };

PyObject *_PyNew_SPApar_vec();

bool _PyCheck_SPApar_vec(PyObject *ob);

// Define FileInfo
typedef struct
{
  PyObject_HEAD
  FileInfo *_acis_obj;
} a3dp_FileInfo;

void a3dp_FileInfo_dealloc(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_FileInfo_init(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_FileInfo__acis_version(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__date(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__file_version(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__product_id(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__reset(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__reset_vars(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__restore(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__save(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__set_masked(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_FileInfo__set_product_id(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_FileInfo__set_units(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_FileInfo__tol_abs(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__tol_nor(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__units(a3dp_FileInfo *self);
PyObject *a3dp_FileInfo__valid(a3dp_FileInfo *self);

static PyMemberDef
  a3dp_members_FileInfo[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  a3dp_methods_FileInfo[] =
  {
    { "acis_version", (PyCFunction) a3dp_FileInfo__acis_version, METH_NOARGS, "Returns the ACIS version number used to save the model" },
    { "date", (PyCFunction) a3dp_FileInfo__date, METH_NOARGS, "Returns the date on the save file" },
    { "file_version", (PyCFunction) a3dp_FileInfo__file_version, METH_NOARGS, "Returns the save file version used in storing the file" },
    { "product_id", (PyCFunction) a3dp_FileInfo__product_id, METH_NOARGS, "Returns the ID of the product" },
    { "reset", (PyCFunction) a3dp_FileInfo__reset, METH_NOARGS, "Resets the values to the default settings for the file information" },
    { "reset_vars", (PyCFunction) a3dp_FileInfo__reset_vars, METH_NOARGS, "Routine to reset the values for the file information to the default values" },
    { "restore", (PyCFunction) a3dp_FileInfo__restore, METH_NOARGS, "Restores the file information from a save file" },
    { "save", (PyCFunction) a3dp_FileInfo__save, METH_NOARGS, "Saves the product ID, version, time, units, SPAresabs and SPAresnor" },
    //{ "set_masked", (PyCFunction)a3dp_FileInfo__set_masked,  METH_VARARGS | METH_KEYWORDS, "Copies selected fields from another instance" },
    { "set_product_id", (PyCFunction) a3dp_FileInfo__set_product_id, METH_VARARGS | METH_KEYWORDS, "Sets the product ID" },
    { "set_units", (PyCFunction) a3dp_FileInfo__set_units, METH_VARARGS | METH_KEYWORDS, "Sets the model units scale (in millimeters)" },
    { "tol_abs", (PyCFunction) a3dp_FileInfo__tol_abs, METH_NOARGS, "Returns the value of the SPAresabs when the model was saved" },
    { "tol_nor", (PyCFunction) a3dp_FileInfo__tol_nor, METH_NOARGS, "Returns the value of the SPAresnor when the model was saved" },
    { "units", (PyCFunction) a3dp_FileInfo__units, METH_NOARGS, "Returns the value of the millimeters per model unit" },
    { "valid", (PyCFunction) a3dp_FileInfo__valid, METH_NOARGS, "Checks the values of the units and product id" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_FileInfo =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.FileInfo",             /* tp_name */
    sizeof(a3dp_FileInfo), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) a3dp_FileInfo_dealloc, /* tp_dealloc */
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
    "FileInfo object contains additional required save file header information", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_FileInfo, /* tp_methods */
    a3dp_members_FileInfo, /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_FileInfo_init, /* tp_init */
    0,                         /* tp_alloc */
    a3dp_FileInfo_new, /* tp_new */
  };

bool _PyCheck_FileInfo(PyObject *ob);

// Define sweep_options
typedef struct
{
    PyObject_HEAD
    sweep_options *_acis_obj;
} a3dp_sweep_options;

void a3dp_sweepoptions_dealloc(a3dp_sweep_options *self);
PyObject *a3dp_sweepoptions_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_sweepoptions_init(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_sweepoptions__set_bool_type(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs);

static PyMethodDef
  a3dp_methods_sweepoptions[] =
  {
    { "set_bool_type", (PyCFunction) a3dp_sweepoptions__set_bool_type, METH_VARARGS | METH_KEYWORDS, "Sets the option for the Boolean operation type with the to_body" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  a3dp_type_sweep_options =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.sweep_options",             /* tp_name */
    sizeof(a3dp_sweep_options), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) a3dp_sweepoptions_dealloc, /* tp_dealloc */
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
    "sweep_options class provides a data structure for sweeping operations to be used in the function api_sweep_with_options", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    a3dp_methods_sweepoptions, /* tp_methods */
    0, /* tp_members */
    0, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_sweepoptions_init, /* tp_init */
    0,                         /* tp_alloc */
    a3dp_sweepoptions_new, /* tp_new */
  };

PyObject *_PyNew_sweep_options();
bool _PyCheck_sweep_options(PyObject *ob);

// Define make_sweep_path_options
typedef struct
{
    PyObject_HEAD
    make_sweep_path_options *_acis_obj;
} a3dp_make_sweep_path_options;

void a3dp_makesweeppathoptions_dealloc(a3dp_make_sweep_path_options *self);
PyObject *a3dp_makesweeppathoptions_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
int a3dp_makesweeppathoptions_init(a3dp_make_sweep_path_options *self, PyObject *args, PyObject *kwargs);

static PyTypeObject
  a3dp_type_make_sweep_path_options =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.make_sweep_path_options",             /* tp_name */
    sizeof(a3dp_make_sweep_path_options), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) a3dp_makesweeppathoptions_dealloc, /* tp_dealloc */
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
    "make_sweep_path_options class allows the user to exercise finer control over the construction of sweep path", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0, /* tp_methods */
    0, /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) a3dp_makesweeppathoptions_init, /* tp_init */
    0,                         /* tp_alloc */
    a3dp_makesweeppathoptions_new, /* tp_new */
  };

PyObject *_PyNew_make_sweep_path_options();
bool _PyCheck_make_sweep_path_options(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_CLASSES_H
