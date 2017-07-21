#include "acis_geometric_atoms.h"


/**
 * SPAposition wrapper
 */

static int
ACIS_GeometricAtoms_traverse_SPAposition(ACIS_GeometricAtoms_SPAposition *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject variables

  return 0;
}

static int
ACIS_GeometricAtoms_clear_SPAposition(ACIS_GeometricAtoms_SPAposition *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Use Py_CLEAR macro for PyObject variables

  return 0;
}

static void
ACIS_GeometricAtoms_dealloc_SPAposition(ACIS_GeometricAtoms_SPAposition *self)
{
  ACIS_GeometricAtoms_clear_SPAposition(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_GeometricAtoms_new_SPAposition(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_GeometricAtoms_SPAposition *self;

  self = (ACIS_GeometricAtoms_SPAposition *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_GeometricAtoms_init_SPAposition(ACIS_GeometricAtoms_SPAposition *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  static char *kwlist[] =
    {
      (char *) "x",
      (char *) "y",
      (char *) "z",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ddd", kwlist, &input_x, &input_y, &input_z))
    return -1;

  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAposition(input_x, input_y, input_z);

  return 0;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_coordinate(ACIS_GeometricAtoms_SPAposition *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  // No parsing required as this function takes exactly 1 argument
  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  int _i = (int) PyLong_AsLong(arg);

  // SPAposition class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The input argument must be 0, 1 or 2");
    return NULL;
  }

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Return data from the ACIS object
  return PyFloat_FromDouble(self->_acis_obj->coordinate(_i));
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_set_coordinate(ACIS_GeometricAtoms_SPAposition *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  static char *kwlist[] =
    {
      (char *) "i",
      (char *) "new_c",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "id", kwlist, &_i, &_new_c))
    return NULL;

  // SPAposition class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The coordinate input must be 0, 1 or 2");
    return NULL;
  }

  self->_acis_obj->set_coordinate(_i, _new_c);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_set_x(ACIS_GeometricAtoms_SPAposition *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_x(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_set_y(ACIS_GeometricAtoms_SPAposition *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_y(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_set_z(ACIS_GeometricAtoms_SPAposition *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_z(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_x(ACIS_GeometricAtoms_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_y(ACIS_GeometricAtoms_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_z(ACIS_GeometricAtoms_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_x_getter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAposition_x(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_y_getter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAposition_y(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAposition_z_getter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAposition_z(self);
}

static int
ACIS_GeometricAtoms_method_SPAposition_x_setter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAposition_set_x(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAposition_y_setter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAposition_set_y(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAposition_z_setter(ACIS_GeometricAtoms_SPAposition *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAposition_set_z(self, value);
  return 0;
}

static PyGetSetDef
  ACIS_GeometricAtoms_getseters_SPAposition[] =
  {
    { (char *) "x_value", (getter) ACIS_GeometricAtoms_method_SPAposition_x_getter, (setter) ACIS_GeometricAtoms_method_SPAposition_x_setter, (char *) "value of the x-coordinate", NULL },
    { (char *) "y_value", (getter) ACIS_GeometricAtoms_method_SPAposition_y_getter, (setter) ACIS_GeometricAtoms_method_SPAposition_y_setter, (char *) "value of the y-coordinate", NULL },
    { (char *) "z_value", (getter) ACIS_GeometricAtoms_method_SPAposition_z_getter, (setter) ACIS_GeometricAtoms_method_SPAposition_z_setter, (char *) "value of the z-coordinate", NULL },
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_GeometricAtoms_members_SPAposition[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_GeometricAtoms_methods_SPAposition[] =
  {
    { "coordinate", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_coordinate, METH_O, "Returns the i-th component value" },
    { "set_coordinate", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_set_coordinate, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component value" },
    { "set_x", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_set_x, METH_O, "Sets the x-coordinate value" },
    { "set_y", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_set_x, METH_O, "Sets the y-coordinate value" },
    { "set_z", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_set_x, METH_O, "Sets the z-coordinate value" },
    { "x", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_x, METH_NOARGS, "Returns the x-coordinate value" },
    { "y", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_y, METH_NOARGS, "Returns the y-coordinate value" },
    { "z", (PyCFunction) ACIS_GeometricAtoms_method_SPAposition_z, METH_NOARGS, "Returns the z-coordinate value" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_GeometricAtoms_type_SPAposition =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAposition",             /* tp_name */
    sizeof(ACIS_GeometricAtoms_SPAposition), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_GeometricAtoms_dealloc_SPAposition, /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "SPAposition represents position vectors (points) in 3D Cartesian space that are subject to certain vector and transformation operations", /* tp_doc */
    (traverseproc) ACIS_GeometricAtoms_traverse_SPAposition, /* tp_traverse */
    (inquiry) ACIS_GeometricAtoms_clear_SPAposition, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_GeometricAtoms_methods_SPAposition, /* tp_methods */
    ACIS_GeometricAtoms_members_SPAposition, /* tp_members */
    ACIS_GeometricAtoms_getseters_SPAposition, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_GeometricAtoms_init_SPAposition, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_GeometricAtoms_new_SPAposition, /* tp_new */
  };


/**
 * SPAvector wrapper
 */

static int
ACIS_GeometricAtoms_traverse_SPAvector(ACIS_GeometricAtoms_SPAvector *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject variables

  return 0;
}

static int
ACIS_GeometricAtoms_clear_SPAvector(ACIS_GeometricAtoms_SPAvector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Use Py_CLEAR macro for PyObject variables

  return 0;
}

static void
ACIS_GeometricAtoms_dealloc_SPAvector(ACIS_GeometricAtoms_SPAvector *self)
{
  ACIS_GeometricAtoms_clear_SPAvector(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_GeometricAtoms_new_SPAvector(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_GeometricAtoms_SPAvector *self;

  self = (ACIS_GeometricAtoms_SPAvector *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_GeometricAtoms_init_SPAvector(ACIS_GeometricAtoms_SPAvector *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  static char *kwlist[] =
    {
      (char *) "x",
      (char *) "y",
      (char *) "z",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ddd", kwlist, &input_x, &input_y, &input_z))
    return -1;

  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAvector(input_x, input_y, input_z);

  return 0;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_component(ACIS_GeometricAtoms_SPAvector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  // No parsing required as this function takes exactly 1 argument
  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  int _i = (int) PyLong_AsLong(arg);

  // SPAvector class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The input argument must be 0, 1 or 2");
    return NULL;
  }

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Return data from the ACIS object
  return PyFloat_FromDouble(self->_acis_obj->component(_i));
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_set_component(ACIS_GeometricAtoms_SPAvector *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  static char *kwlist[] =
    {
      (char *) "i",
      (char *) "new_c",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "id", kwlist, &_i, &_new_c))
    return NULL;

  // SPAvector class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The component input must be 0, 1 or 2");
    return NULL;
  }

  self->_acis_obj->set_component(_i, _new_c);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_set_x(ACIS_GeometricAtoms_SPAvector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_x(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_set_y(ACIS_GeometricAtoms_SPAvector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_y(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_set_z(ACIS_GeometricAtoms_SPAvector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_z(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_x(ACIS_GeometricAtoms_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_y(ACIS_GeometricAtoms_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_z(ACIS_GeometricAtoms_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_x_getter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAvector_x(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_y_getter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAvector_y(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAvector_z_getter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAvector_z(self);
}

static int
ACIS_GeometricAtoms_method_SPAvector_x_setter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAvector_set_x(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAvector_y_setter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAvector_set_y(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAvector_z_setter(ACIS_GeometricAtoms_SPAvector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAvector_set_z(self, value);
  return 0;
}

static PyGetSetDef
  ACIS_GeometricAtoms_getseters_SPAvector[] =
  {
    { (char *) "x_value", (getter) ACIS_GeometricAtoms_method_SPAvector_x_getter, (setter) ACIS_GeometricAtoms_method_SPAvector_x_setter, (char *) "value of the x component", NULL },
    { (char *) "y_value", (getter) ACIS_GeometricAtoms_method_SPAvector_y_getter, (setter) ACIS_GeometricAtoms_method_SPAvector_y_setter, (char *) "value of the y component", NULL },
    { (char *) "z_value", (getter) ACIS_GeometricAtoms_method_SPAvector_z_getter, (setter) ACIS_GeometricAtoms_method_SPAvector_z_setter, (char *) "value of the z component", NULL },
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_GeometricAtoms_members_SPAvector[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_GeometricAtoms_methods_SPAvector[] =
  {
    { "component", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_component, METH_O, "Returns the i-th component of the vector" },
    { "set_component", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_set_component, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component of the vector" },
    { "set_x", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_set_x, METH_O, "Sets the x-component of the vector" },
    { "set_y", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_set_x, METH_O, "Sets the y-component of the vector" },
    { "set_z", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_set_x, METH_O, "Sets the z-component of the vector" },
    { "x", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_x, METH_NOARGS, "Returns the x-component of the vector" },
    { "y", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_y, METH_NOARGS, "Returns the y-component of the vector" },
    { "z", (PyCFunction) ACIS_GeometricAtoms_method_SPAvector_z, METH_NOARGS, "Returns the z-component of the vector" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_GeometricAtoms_type_SPAvector =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAvector",             /* tp_name */
    sizeof(ACIS_GeometricAtoms_SPAvector), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_GeometricAtoms_dealloc_SPAvector, /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "SPAvector represents a displacement vector in 3D Cartesian space", /* tp_doc */
    (traverseproc) ACIS_GeometricAtoms_traverse_SPAvector, /* tp_traverse */
    (inquiry) ACIS_GeometricAtoms_clear_SPAvector, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_GeometricAtoms_methods_SPAvector, /* tp_methods */
    ACIS_GeometricAtoms_members_SPAvector, /* tp_members */
    ACIS_GeometricAtoms_getseters_SPAvector, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_GeometricAtoms_init_SPAvector, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_GeometricAtoms_new_SPAvector, /* tp_new */
  };


/**
 * SPAunit_vector wrapper
 */

static int
ACIS_GeometricAtoms_traverse_SPAunit_vector(ACIS_GeometricAtoms_SPAunit_vector *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject variables

  return 0;
}

static int
ACIS_GeometricAtoms_clear_SPAunit_vector(ACIS_GeometricAtoms_SPAunit_vector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Use Py_CLEAR macro for PyObject variables

  return 0;
}

static void
ACIS_GeometricAtoms_dealloc_SPAunit_vector(ACIS_GeometricAtoms_SPAunit_vector *self)
{
  ACIS_GeometricAtoms_clear_SPAunit_vector(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_GeometricAtoms_new_SPAunit_vector(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_GeometricAtoms_SPAunit_vector *self;

  self = (ACIS_GeometricAtoms_SPAunit_vector *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_GeometricAtoms_init_SPAunit_vector(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  static char *kwlist[] =
    {
      (char *) "x",
      (char *) "y",
      (char *) "z",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ddd", kwlist, &input_x, &input_y, &input_z))
    return -1;

  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAunit_vector(input_x, input_y, input_z);

  return 0;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_component(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  // No parsing required as this function takes exactly 1 argument
  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  int _i = (int) PyLong_AsLong(arg);

  // SPAunit_vector class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The input argument must be 0, 1 or 2");
    return NULL;
  }

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Return data from the ACIS object
  return PyFloat_FromDouble(self->_acis_obj->component(_i));
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_set_component(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  static char *kwlist[] =
    {
      (char *) "i",
      (char *) "new_c",
      NULL
    };

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "id", kwlist, &_i, &_new_c))
    return NULL;

  // SPAunit_vector class has a coord field which has a size of 3, corresponding to x, y, z
  if (_i < 0 || _i > 2)
  {
    PyErr_SetString(PyExc_ValueError, "The component input must be 0, 1 or 2");
    return NULL;
  }

  self->_acis_obj->set_component(_i, _new_c);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_set_x(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_x(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_set_y(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_y(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_set_z(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  double _value;

  // No parsing required as this function takes exactly 1 argument
  if (PyFloat_Check(arg))
  {
    _value = PyFloat_AsDouble(arg);
  }
  else
  {
    if (PyLong_Check(arg))
    {
      _value = PyLong_AsDouble(arg);
    }
    else
    {
      PyErr_SetString(PyExc_TypeError, "The input argument must be a floating point number");
      return NULL;
    }
  }

  self->_acis_obj->set_z(_value);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_x(ACIS_GeometricAtoms_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_y(ACIS_GeometricAtoms_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_z(ACIS_GeometricAtoms_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_x_getter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAunit_vector_x(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_y_getter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAunit_vector_y(self);
}

static PyObject *
ACIS_GeometricAtoms_method_SPAunit_vector_z_getter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  return ACIS_GeometricAtoms_method_SPAunit_vector_z(self);
}

static int
ACIS_GeometricAtoms_method_SPAunit_vector_x_setter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAunit_vector_set_x(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAunit_vector_y_setter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAunit_vector_set_y(self, value);
  return 0;
}

static int
ACIS_GeometricAtoms_method_SPAunit_vector_z_setter(ACIS_GeometricAtoms_SPAunit_vector *self, PyObject *value, void *closure)
{
  ACIS_GeometricAtoms_method_SPAunit_vector_set_z(self, value);
  return 0;
}

static PyGetSetDef
  ACIS_GeometricAtoms_getseters_SPAunit_vector[] =
  {
    { (char *) "x_value", (getter) ACIS_GeometricAtoms_method_SPAunit_vector_x_getter, (setter) ACIS_GeometricAtoms_method_SPAunit_vector_x_setter, (char *) "value of the x component", NULL },
    { (char *) "y_value", (getter) ACIS_GeometricAtoms_method_SPAunit_vector_y_getter, (setter) ACIS_GeometricAtoms_method_SPAunit_vector_y_setter, (char *) "value of the y component", NULL },
    { (char *) "z_value", (getter) ACIS_GeometricAtoms_method_SPAunit_vector_z_getter, (setter) ACIS_GeometricAtoms_method_SPAunit_vector_z_setter, (char *) "value of the z component", NULL },
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_GeometricAtoms_members_SPAunit_vector[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_GeometricAtoms_methods_SPAunit_vector[] =
  {
    { "component", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_component, METH_O, "Returns the i-th component of the vector" },
    { "set_component", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_set_component, METH_VARARGS | METH_KEYWORDS, "Sets the i-th component of the vector" },
    { "set_x", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_set_x, METH_O, "Sets the x-component of the vector" },
    { "set_y", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_set_x, METH_O, "Sets the y-component of the vector" },
    { "set_z", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_set_x, METH_O, "Sets the z-component of the vector" },
    { "x", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_x, METH_NOARGS, "Returns the x-component of the vector" },
    { "y", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_y, METH_NOARGS, "Returns the y-component of the vector" },
    { "z", (PyCFunction) ACIS_GeometricAtoms_method_SPAunit_vector_z, METH_NOARGS, "Returns the z-component of the vector" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_GeometricAtoms_type_SPAunit_vector =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAunit_vector",             /* tp_name */
    sizeof(ACIS_GeometricAtoms_SPAunit_vector), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_GeometricAtoms_dealloc_SPAunit_vector, /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "SPAunit_vector provides a direction in 3D Cartesian space that has unit length", /* tp_doc */
    (traverseproc) ACIS_GeometricAtoms_traverse_SPAunit_vector, /* tp_traverse */
    (inquiry) ACIS_GeometricAtoms_clear_SPAunit_vector, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_GeometricAtoms_methods_SPAunit_vector, /* tp_methods */
    ACIS_GeometricAtoms_members_SPAunit_vector, /* tp_members */
    ACIS_GeometricAtoms_getseters_SPAunit_vector, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_GeometricAtoms_init_SPAunit_vector, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_GeometricAtoms_new_SPAunit_vector, /* tp_new */
  };


/**
 * SPAmatrix wrapper
 */

static int
ACIS_GeometricAtoms_traverse_SPAmatrix(ACIS_GeometricAtoms_SPAmatrix *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject variables

  return 0;
}

static int
ACIS_GeometricAtoms_clear_SPAmatrix(ACIS_GeometricAtoms_SPAmatrix *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Use Py_CLEAR macro for PyObject variables

  return 0;
}

static void
ACIS_GeometricAtoms_dealloc_SPAmatrix(ACIS_GeometricAtoms_SPAmatrix *self)
{
  ACIS_GeometricAtoms_clear_SPAmatrix(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_GeometricAtoms_new_SPAmatrix(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_GeometricAtoms_SPAmatrix *self;

  self = (ACIS_GeometricAtoms_SPAmatrix *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_GeometricAtoms_init_SPAmatrix(ACIS_GeometricAtoms_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAmatrix();

  return 0;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_column(ACIS_GeometricAtoms_SPAmatrix *self, PyObject *arg)
{
  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  // Create a new SPAvector python object
  PyObject *_python_ret = _ACIS_new_SPAvector();

  // Convert python input argument into a C variable
  int _in_col = (int) PyLong_AsLong(arg);

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((ACIS_GeometricAtoms_SPAvector *) _python_ret)->_acis_obj = self->_acis_obj->column(_in_col);

  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  // Return the updated python object
  return _python_ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_row(ACIS_GeometricAtoms_SPAmatrix *self, PyObject *arg)
{
  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  // Create a new SPAvector python object
  PyObject *_python_ret = _ACIS_new_SPAvector();

  // Convert python input argument into a C variable
  int _in_row = (int) PyLong_AsLong(arg);

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((ACIS_GeometricAtoms_SPAvector *) _python_ret)->_acis_obj = self->_acis_obj->row(_in_row);

  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  // Return the updated python object
  return _python_ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_inverse(ACIS_GeometricAtoms_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _ACIS_new_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((ACIS_GeometricAtoms_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->inverse();

  // Return the updated python object
  return _python_ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_transpose(ACIS_GeometricAtoms_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _ACIS_new_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((ACIS_GeometricAtoms_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->transpose();

  // Return the updated python object
  return _python_ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_determinant(ACIS_GeometricAtoms_SPAmatrix *self)
{
  // Execute the ACIS function and return the value as a python object
  return PyFloat_FromDouble(self->_acis_obj->determinant());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_element(ACIS_GeometricAtoms_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  int input_row, input_col;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "row",
      (char *) "col",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii", kwlist, &input_row, &input_col))
    return NULL;

  // Execute the ACIS function and return the value as a python object
  return PyFloat_FromDouble(self->_acis_obj->element(input_row, input_col));
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_set_element(ACIS_GeometricAtoms_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  int input_row, input_col;
  double input_new_e;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "row",
      (char *) "col",
      (char *) "new_e",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "iid", kwlist, &input_row, &input_col, &input_new_e))
    return NULL;

  // Execute the ACIS function
  self->_acis_obj->set_element(input_row, input_col, input_new_e);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAmatrix_is_identity(ACIS_GeometricAtoms_SPAmatrix *self)
{
  logical _ret_val = self->_acis_obj->is_identity();

  if (_ret_val)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyGetSetDef
  ACIS_GeometricAtoms_getseters_SPAmatrix[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_GeometricAtoms_members_SPAmatrix[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_GeometricAtoms_methods_SPAmatrix[] =
  {
    { "column", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_column, METH_O, "Extracts a column from this matrix" },
    { "row", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_row, METH_O, "Extracts a row from this matrix" },
    { "element", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_element, METH_VARARGS | METH_KEYWORDS, "Extracts an element of this matrix" },
    { "set_element", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_set_element, METH_VARARGS | METH_KEYWORDS, "Assigns a value to an element in the matrix" },
    { "determinant", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_determinant, METH_NOARGS, "Returns the determinant of this matrix" },
    { "transpose", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_transpose, METH_NOARGS, "Returns a transpose of this matrix" },
    { "inverse", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_inverse, METH_NOARGS, "Returns the inverse of this matrix" },
    { "is_identity", (PyCFunction) ACIS_GeometricAtoms_method_SPAmatrix_is_identity, METH_NOARGS, "Returns TRUE if this matrix is the identity matrix" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_GeometricAtoms_type_SPAmatrix =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAmatrix",             /* tp_name */
    sizeof(ACIS_GeometricAtoms_SPAmatrix), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_GeometricAtoms_dealloc_SPAmatrix, /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "SPAmatrix defines a 3x3 affine transformation acting on vectors and positions", /* tp_doc */
    (traverseproc) ACIS_GeometricAtoms_traverse_SPAmatrix, /* tp_traverse */
    (inquiry) ACIS_GeometricAtoms_clear_SPAmatrix, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_GeometricAtoms_methods_SPAmatrix, /* tp_methods */
    ACIS_GeometricAtoms_members_SPAmatrix, /* tp_members */
    ACIS_GeometricAtoms_getseters_SPAmatrix, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_GeometricAtoms_init_SPAmatrix, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_GeometricAtoms_new_SPAmatrix, /* tp_new */
  };


/**
 * SPAtransf wrapper
 */

static int
ACIS_GeometricAtoms_traverse_SPAtransf(ACIS_GeometricAtoms_SPAtransf *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject variables

  return 0;
}

static int
ACIS_GeometricAtoms_clear_SPAtransf(ACIS_GeometricAtoms_SPAtransf *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Use Py_CLEAR macro for PyObject variables

  return 0;
}

static void
ACIS_GeometricAtoms_dealloc_SPAtransf(ACIS_GeometricAtoms_SPAtransf *self)
{
  ACIS_GeometricAtoms_clear_SPAtransf(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_GeometricAtoms_new_SPAtransf(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_GeometricAtoms_SPAtransf *self;

  self = (ACIS_GeometricAtoms_SPAtransf *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_GeometricAtoms_init_SPAtransf(ACIS_GeometricAtoms_SPAtransf *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAtransf();

  return 0;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_affine(ACIS_GeometricAtoms_SPAtransf *self)
{
  PyObject *_ret = _ACIS_new_SPAmatrix();

  *((ACIS_GeometricAtoms_SPAmatrix *) _ret)->_acis_obj = self->_acis_obj->affine();

  return _ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_inverse(ACIS_GeometricAtoms_SPAtransf *self)
{
  PyObject *_ret = _ACIS_new_SPAtransf();

  *((ACIS_GeometricAtoms_SPAtransf *) _ret)->_acis_obj = self->_acis_obj->inverse();

  return _ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_translation(ACIS_GeometricAtoms_SPAtransf *self)
{
  PyObject *_ret = _ACIS_new_SPAvector();

  *((ACIS_GeometricAtoms_SPAvector *) _ret)->_acis_obj = self->_acis_obj->translation();

  return _ret;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_identity(ACIS_GeometricAtoms_SPAtransf *self)
{
  logical _check = self->_acis_obj->identity();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_reflect(ACIS_GeometricAtoms_SPAtransf *self)
{
  logical _check = self->_acis_obj->reflect();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_rotate(ACIS_GeometricAtoms_SPAtransf *self)
{
  logical _check = self->_acis_obj->rotate();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_scaling(ACIS_GeometricAtoms_SPAtransf *self)
{
  return PyFloat_FromDouble(self->_acis_obj->scaling());
}

static PyObject *
ACIS_GeometricAtoms_method_SPAtransf_shear(ACIS_GeometricAtoms_SPAtransf *self)
{
  logical _check = self->_acis_obj->shear();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyGetSetDef
  ACIS_GeometricAtoms_getseters_SPAtransf[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_GeometricAtoms_members_SPAtransf[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_GeometricAtoms_methods_SPAtransf[] =
  {
    { "affine", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_affine, METH_NOARGS, "Returns the affine portion of the transformation" },
    { "inverse", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_inverse, METH_NOARGS, "Returns the inverse transformation" },
    { "translation", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_translation, METH_NOARGS, "Returns the vector representing the translational portion of the transformation" },
    { "identity", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_identity, METH_NOARGS, "Queries whether or not the transformation is the identity" },
    { "reflect", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_reflect, METH_NOARGS, "Queries whether or not the transformation is reflecting" },
    { "rotate", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_rotate, METH_NOARGS, "Queries whether or not the transformation has a rotational component" },
    { "scaling", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_scaling, METH_NOARGS, "Returns the scaling factor of the transformation" },
    { "shear", (PyCFunction) ACIS_GeometricAtoms_method_SPAtransf_shear, METH_NOARGS, "Queries whether or not the transformation has a shearing component" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_GeometricAtoms_type_SPAtransf =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAtransf",             /* tp_name */
    sizeof(ACIS_GeometricAtoms_SPAtransf), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_GeometricAtoms_dealloc_SPAtransf, /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE |
      Py_TPFLAGS_HAVE_GC,   /* tp_flags */
    "SPAtransf represents a general 3D affine transformation", /* tp_doc */
    (traverseproc) ACIS_GeometricAtoms_traverse_SPAtransf, /* tp_traverse */
    (inquiry) ACIS_GeometricAtoms_clear_SPAtransf, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_GeometricAtoms_methods_SPAtransf, /* tp_methods */
    ACIS_GeometricAtoms_members_SPAtransf, /* tp_members */
    ACIS_GeometricAtoms_getseters_SPAtransf, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_GeometricAtoms_init_SPAtransf, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_GeometricAtoms_new_SPAtransf, /* tp_new */
  };


/**
 * Python module definitions
 */

static PyObject *
ACIS_GeometricAtoms_method_coordinate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_origin = NULL, *input_x_axis = NULL, *input_y_axis = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "new_origin",
      (char *) "new_x_axis",
      (char *) "new_y_axis",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO", kwlist, &input_origin, &input_x_axis, &input_y_axis))
    return NULL;

  // Check inputs
  if (!_ACIS_check_SPAposition(input_origin))
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (new_origin) must be a SPAposition object");
    return NULL;
  }

  if (!_ACIS_check_SPAunit_vector(input_x_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Second parameter (new_x_axis) must be a SPAunit_vector object");
    return NULL;
  }

  if (!_ACIS_check_SPAunit_vector(input_y_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Third parameter (new_y_axis) must be a SPAunit_vector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAposition *&_new_origin = ((ACIS_GeometricAtoms_SPAposition *) input_origin)->_acis_obj;
  SPAunit_vector *&_new_x_axis = ((ACIS_GeometricAtoms_SPAunit_vector *) input_x_axis)->_acis_obj;
  SPAunit_vector *&_new_y_axis = ((ACIS_GeometricAtoms_SPAunit_vector *) input_y_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = coordinate_transf(*_new_origin, *_new_x_axis, *_new_y_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_make_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_affine = NULL, *input_translation = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "affine",
      (char *) "translation",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_affine, &input_translation))
    return NULL;

  // Check inputs
  if (!_ACIS_check_SPAmatrix(input_affine))
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (affine) must be a SPAmatrix object");
    return NULL;
  }

  if (!_ACIS_check_SPAvector(input_translation))
  {
    PyErr_SetString(PyExc_TypeError, "Second parameter (translate) must be a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAmatrix *&_affine = ((ACIS_GeometricAtoms_SPAmatrix *) input_affine)->_acis_obj;
  SPAvector *&_translation = ((ACIS_GeometricAtoms_SPAvector *) input_translation)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = make_transf(*_affine, *_translation);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_reflect_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_axis = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "axis",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_axis))
    return NULL;

  // Check inputs
  if (!_ACIS_check_SPAvector(input_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_axis = ((ACIS_GeometricAtoms_SPAvector *) input_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = reflect_transf(*_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_rotate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_axis = NULL;
  double input_angle;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "angle",
      (char *) "axis",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "dO", kwlist, &input_angle, &input_axis))
    return NULL;

  // Check inputs
  if (!_ACIS_check_SPAvector(input_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_axis = ((ACIS_GeometricAtoms_SPAvector *) input_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = rotate_transf(input_angle, *_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_scale_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_arg1 = NULL, *input_arg2 = NULL, *input_arg3 = NULL, *input_arg4 = NULL, *input_arg5 = NULL, *input_arg6 = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "scale",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|OOOOO", kwlist, &input_arg1, &input_arg2, &input_arg3, &input_arg4, &input_arg5, &input_arg6))
    return NULL;

  SPAtransf retval;

  if (!PyFloat_Check(input_arg1))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a floating-point number");
    return NULL;
  }

  double _arg1 = PyFloat_AsDouble(input_arg1);

  if (input_arg2 != NULL || input_arg3 != NULL)
  {
    if (!PyFloat_Check(input_arg2) && !PyFloat_Check(input_arg3))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a floating-point number");
      return NULL;
    }

    double _arg2 = PyFloat_AsDouble(input_arg2);
    double _arg3 = PyFloat_AsDouble(input_arg3);

    if (input_arg4 != NULL || input_arg5 != NULL || input_arg6 != NULL)
    {
      if (!PyFloat_Check(input_arg4) && !PyFloat_Check(input_arg5) && !PyFloat_Check(input_arg5))
      {
        PyErr_SetString(PyExc_TypeError, "Expecting a floating-point number");
        return NULL;
      }

      double _arg4 = PyFloat_AsDouble(input_arg4);
      double _arg5 = PyFloat_AsDouble(input_arg5);
      double _arg6 = PyFloat_AsDouble(input_arg5);

      retval = scale_transf(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
    }
    else
    {
      retval = scale_transf(_arg1, _arg2, _arg3);
    }
  }
  else
  {
    retval = scale_transf(_arg1);
  }

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_shear_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double _shear_xy, _shear_xz, _shear_yz;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "shearxy",
      (char *) "shearxz",
      (char *) "shearyz",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddd", kwlist, &_shear_xy, &_shear_xz, &_shear_yz))
    return NULL;

  // Execute ACIS function
  SPAtransf retval = shear_transf(_shear_xy, _shear_xz, _shear_yz);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_translate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_disp = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "disp",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_disp))
    return NULL;

  // "disp" must be a SPAvector object
  if (!_ACIS_check_SPAvector(input_disp))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_disp = ((ACIS_GeometricAtoms_SPAvector *) input_disp)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = translate_transf(*_disp);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_GeometricAtoms_method_angle_between(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL, *input_z = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "v1",
      (char *) "v2",
      (char *) "z",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|O", kwlist, &input_v1, &input_v2, &input_z))
    return NULL;

  // Set return value
  double _retval;

  // SPAvector scenario
  if (_ACIS_check_SPAvector(input_v1))
  {
    if (!_ACIS_check_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((ACIS_GeometricAtoms_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((ACIS_GeometricAtoms_SPAvector *) input_v2)->_acis_obj;

    if (input_z != NULL)
    {
      if (!_ACIS_check_SPAvector(input_z))
      {
        PyErr_SetString(PyExc_TypeError, "Third parameter (z) should be a SPAunit_vector object");
        return NULL;
      }

      SPAunit_vector *&_z = ((ACIS_GeometricAtoms_SPAunit_vector *) input_z)->_acis_obj;

      _retval = angle_between(*_v1, *_v2, *_z);
    }
    else
    {
      _retval = angle_between(*_v1, *_v2);
    }
  }
  else if (_ACIS_check_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_ACIS_check_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v2)->_acis_obj;

    if (input_z != NULL)
    {
      if (!_ACIS_check_SPAunit_vector(input_z))
      {
        PyErr_SetString(PyExc_TypeError, "Third parameter (z) should be a SPAunit_vector object");
        return NULL;
      }

      SPAunit_vector *&_z = ((ACIS_GeometricAtoms_SPAunit_vector *) input_z)->_acis_obj;

      _retval = angle_between(*_v1, *_v2, *_z);
    }
    else
    {
      _retval = angle_between(*_v1, *_v2);
    }
  }
  else
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (v1) should be a SPAvector or SPAunit_vector object");
    return NULL;
  }

  // Return PyFloat object
  return PyFloat_FromDouble(_retval);
}

static PyObject *
ACIS_GeometricAtoms_method_antiparallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  double input_res = -1.0;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "v1",
      (char *) "v2",
      (char *) "res",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|d", kwlist, &input_v1, &input_v2, &input_res))
    return NULL;

  // Set return value
  logical _retval;

  // SPAvector scenario
  if (_ACIS_check_SPAvector(input_v1))
  {
    if (!_ACIS_check_SPAvector(input_v2) || !_ACIS_check_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector or SPAunit_vector object");
      return NULL;
    }

    SPAvector *&_v1 = ((ACIS_GeometricAtoms_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((ACIS_GeometricAtoms_SPAvector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = antiparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = antiparallel(*_v1, *_v2);
    }
  }
  else if (_ACIS_check_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_ACIS_check_SPAunit_vector(input_v2) || !_ACIS_check_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector or SPAvector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = antiparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = antiparallel(*_v1, *_v2);
    }
  }
  else
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (v1) should be a SPAvector or SPAunit_vector object");
    return NULL;
  }

  // Return logical
  if (_retval == 1)
    Py_RETURN_TRUE;
  Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_are_parallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  int input_same_dir = 0;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "v1",
      (char *) "v2",
      (char *) "same_dir",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|i", kwlist, &input_v1, &input_v2, &input_same_dir))
    return NULL;

  // Set return value
  logical _retval;

  // SPAvector scenario
  if (_ACIS_check_SPAvector(input_v1))
  {
    if (!_ACIS_check_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((ACIS_GeometricAtoms_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((ACIS_GeometricAtoms_SPAvector *) input_v2)->_acis_obj;

    _retval = are_parallel(*_v1, *_v2, input_same_dir);
  }
  else if (_ACIS_check_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_ACIS_check_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v2)->_acis_obj;

    _retval = are_parallel(*_v1, *_v2, input_same_dir);
  }
  else
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (v1) should be a SPAvector or SPAunit_vector object");
    return NULL;
  }

  // Return logical
  if (_retval == 1)
    Py_RETURN_TRUE;
  Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_are_perpendicular(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "v1",
      (char *) "v2",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_v1, &input_v2))
    return NULL;

  // Set return value
  logical _retval;

  // SPAvector scenario
  if (_ACIS_check_SPAvector(input_v1))
  {
    if (!_ACIS_check_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((ACIS_GeometricAtoms_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((ACIS_GeometricAtoms_SPAvector *) input_v2)->_acis_obj;

    _retval = are_perpendicular(*_v1, *_v2);
  }
  else if (_ACIS_check_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_ACIS_check_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v2)->_acis_obj;

    _retval = are_perpendicular(*_v1, *_v2);
  }
  else
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (v1) should be a SPAvector or SPAunit_vector object");
    return NULL;
  }

  // Return logical
  if (_retval == 1)
    Py_RETURN_TRUE;
  Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_biparallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  double input_res = -1.0;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "v1",
      (char *) "v2",
      (char *) "res",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|d", kwlist, &input_v1, &input_v2, &input_res))
    return NULL;

  // Set return value
  logical _retval;

  // SPAvector scenario
  if (_ACIS_check_SPAvector(input_v1))
  {
    if (!_ACIS_check_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((ACIS_GeometricAtoms_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((ACIS_GeometricAtoms_SPAvector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = biparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = biparallel(*_v1, *_v2);
    }
  }
  else if (_ACIS_check_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_ACIS_check_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((ACIS_GeometricAtoms_SPAunit_vector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = biparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = biparallel(*_v1, *_v2);
    }
  }
  else
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (v1) should be a SPAvector or SPAunit_vector object");
    return NULL;
  }

  // Return logical
  if (_retval == 1)
    Py_RETURN_TRUE;
  Py_RETURN_FALSE;
}

static PyObject *
ACIS_GeometricAtoms_method_degrees_to_radians(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_ang;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "ang",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "d", kwlist, &input_ang))
    return NULL;

  double _retval = degrees_to_radians(input_ang);

  // Return double
  return PyFloat_FromDouble(_retval);
}

static PyObject *
ACIS_GeometricAtoms_method_radians_to_degrees(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_ang;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "ang",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "d", kwlist, &input_ang))
    return NULL;

  double _retval = radians_to_degrees(input_ang);

  // Return double
  return PyFloat_FromDouble(_retval);
}

static PyObject *
ACIS_GeometricAtoms_method_get_resabs(PyObject *self)
{
  return PyFloat_FromDouble(get_resabs());
}

static PyObject *
ACIS_GeometricAtoms_method_get_resfit(PyObject *self)
{
  return PyFloat_FromDouble(get_resfit());
}

static PyObject *
ACIS_GeometricAtoms_method_get_resmch(PyObject *self)
{
  return PyFloat_FromDouble(get_resmch());
}

static PyObject *
ACIS_GeometricAtoms_method_get_resnor(PyObject *self)
{
  return PyFloat_FromDouble(get_resnor());
}

static PyObject *
ACIS_GeometricAtoms_method_distance_to_point(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "pt1",
      (char *) "pt2",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pt1, &input_pt2))
    return NULL;

  if (!_ACIS_check_SPAposition(input_pt1) || !_ACIS_check_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "Input values should be SPAposition objects");
    return NULL;
  }

  SPAposition *&_pt1 = ((ACIS_GeometricAtoms_SPAposition *) input_pt1)->_acis_obj;
  SPAposition *&_pt2 = ((ACIS_GeometricAtoms_SPAposition *) input_pt2)->_acis_obj;

  // Return double
  return PyFloat_FromDouble(distance_to_point(*_pt1, *_pt2));
}

static PyObject *
ACIS_GeometricAtoms_method_distance_to_point_squared(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "pt1",
      (char *) "pt2",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pt1, &input_pt2))
    return NULL;

  if (!_ACIS_check_SPAposition(input_pt1) || !_ACIS_check_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "Input values should be SPAposition objects");
    return NULL;
  }

  SPAposition *&_pt1 = ((ACIS_GeometricAtoms_SPAposition *) input_pt1)->_acis_obj;
  SPAposition *&_pt2 = ((ACIS_GeometricAtoms_SPAposition *) input_pt2)->_acis_obj;

  // Return double
  return PyFloat_FromDouble(distance_to_point_squared(*_pt1, *_pt2));
}

static PyMethodDef
  module_methods[] =
  {
    { "coordinate_transf", (PyCFunction) ACIS_GeometricAtoms_method_coordinate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a coordinate transformation" },
    { "make_transf", (PyCFunction) ACIS_GeometricAtoms_method_make_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation retrieving the needed information from the provided transformation matrix and the scaling vector" },
    { "reflect_transf", (PyCFunction) ACIS_GeometricAtoms_method_reflect_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a reflection through a plane, specified by its normal" },
    { "rotate_transf", (PyCFunction) ACIS_GeometricAtoms_method_rotate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a simple rotation by an angle about a given axis" },
    { "scale_transf", (PyCFunction) ACIS_GeometricAtoms_method_scale_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a scale transformation (uniform, non-uniform and shear)" },
    { "shear_transf", (PyCFunction) ACIS_GeometricAtoms_method_shear_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a shear transformation" },
    { "translate_transf", (PyCFunction) ACIS_GeometricAtoms_method_translate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a translation by a given vector" },
    { "angle_between", (PyCFunction) ACIS_GeometricAtoms_method_angle_between, METH_VARARGS | METH_KEYWORDS, "Calculates the angle between two vectors or unit vectors" },
    { "antiparallel", (PyCFunction) ACIS_GeometricAtoms_method_antiparallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are anti-parallel" },
    { "are_parallel", (PyCFunction) ACIS_GeometricAtoms_method_are_parallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are parallel" },
    { "are_perpendicular", (PyCFunction) ACIS_GeometricAtoms_method_are_perpendicular, METH_VARARGS | METH_KEYWORDS, "	Determines if two vectors or unit vectors are perpendicular" },
    { "biparallel", (PyCFunction) ACIS_GeometricAtoms_method_biparallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are bi-parallel" },
    { "degrees_to_radians", (PyCFunction) ACIS_GeometricAtoms_method_degrees_to_radians, METH_VARARGS | METH_KEYWORDS, "Converts an angle from degrees to radians" },
    { "radians_to_degrees", (PyCFunction) ACIS_GeometricAtoms_method_radians_to_degrees, METH_VARARGS | METH_KEYWORDS, "Converts an angle from radians to degrees" },
    { "get_resabs", (PyCFunction) ACIS_GeometricAtoms_method_get_resabs, METH_NOARGS, "Gets the SPAresabs resolution" },
    { "get_resfit", (PyCFunction) ACIS_GeometricAtoms_method_get_resfit, METH_NOARGS, "Gets the SPAresfit resolution" },
    { "get_resmch", (PyCFunction) ACIS_GeometricAtoms_method_get_resmch, METH_NOARGS, "Gets the resmch resolution" },
    { "get_resnor", (PyCFunction) ACIS_GeometricAtoms_method_get_resnor, METH_NOARGS, "Gets the SPAresnor resolution" },
    { "distance_to_point", (PyCFunction) ACIS_GeometricAtoms_method_distance_to_point, METH_VARARGS | METH_KEYWORDS, "Determines the distance between two points" },
    { "distance_to_point_squared", (PyCFunction) ACIS_GeometricAtoms_method_distance_to_point_squared, METH_VARARGS | METH_KEYWORDS, "\tComputes the squared distance between two positions" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "GeometricAtoms";
const char *module_documentation = "Contains 3D ACIS Modeler geometric atoms, e.g. SPAposition, SPApar_pos, etc.";

static struct PyModuleDef
  ACIS_GeometricAtoms_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_GeometricAtoms(void)
{
  PyObject *m;
  m = PyModule_Create(&ACIS_GeometricAtoms_module);
  if (m == NULL)
    return NULL;

  // SPAposition
  if (PyType_Ready(&ACIS_GeometricAtoms_type_SPAposition) < 0)
    return NULL;
  Py_INCREF(&ACIS_GeometricAtoms_type_SPAposition);
  PyModule_AddObject(m, "SPAposition", (PyObject *) &ACIS_GeometricAtoms_type_SPAposition);

  // SPAtransf
  if (PyType_Ready(&ACIS_GeometricAtoms_type_SPAtransf) < 0)
    return NULL;
  Py_INCREF(&ACIS_GeometricAtoms_type_SPAtransf);
  PyModule_AddObject(m, "SPAtransf", (PyObject *) &ACIS_GeometricAtoms_type_SPAtransf);

  // SPAmatrix
  if (PyType_Ready(&ACIS_GeometricAtoms_type_SPAmatrix) < 0)
    return NULL;
  Py_INCREF(&ACIS_GeometricAtoms_type_SPAmatrix);
  PyModule_AddObject(m, "SPAmatrix", (PyObject *) &ACIS_GeometricAtoms_type_SPAmatrix);

  // SPAvector
  if (PyType_Ready(&ACIS_GeometricAtoms_type_SPAvector) < 0)
    return NULL;
  Py_INCREF(&ACIS_GeometricAtoms_type_SPAvector);
  PyModule_AddObject(m, "SPAvector", (PyObject *) &ACIS_GeometricAtoms_type_SPAvector);

  // SPAunit_vector
  if (PyType_Ready(&ACIS_GeometricAtoms_type_SPAunit_vector) < 0)
    return NULL;
  Py_INCREF(&ACIS_GeometricAtoms_type_SPAunit_vector);
  PyModule_AddObject(m, "SPAunit_vector", (PyObject *) &ACIS_GeometricAtoms_type_SPAunit_vector);

  return m;
}

bool _ACIS_check_SPAposition(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_GeometricAtoms_type_SPAposition;
}

PyObject *_ACIS_new_SPAposition()
{
  return PyObject_CallObject((PyObject *) &ACIS_GeometricAtoms_type_SPAposition, NULL);
}

bool _ACIS_check_SPAvector(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_GeometricAtoms_type_SPAvector;
}

PyObject *_ACIS_new_SPAvector()
{
  return PyObject_CallObject((PyObject *) &ACIS_GeometricAtoms_type_SPAvector, NULL);
}

bool _ACIS_check_SPAunit_vector(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_GeometricAtoms_type_SPAunit_vector;
}

PyObject *_ACIS_new_SPAunit_vector()
{
  return PyObject_CallObject((PyObject *) &ACIS_GeometricAtoms_type_SPAunit_vector, NULL);
}

bool _ACIS_check_SPAmatrix(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_GeometricAtoms_type_SPAmatrix;
}

PyObject *_ACIS_new_SPAmatrix()
{
  return PyObject_CallObject((PyObject *) &ACIS_GeometricAtoms_type_SPAmatrix, NULL);
}

bool _ACIS_check_SPAtransf(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_GeometricAtoms_type_SPAtransf;
}

PyObject *_ACIS_new_SPAtransf()
{
  return PyObject_CallObject((PyObject *) &ACIS_GeometricAtoms_type_SPAtransf, NULL);
}
