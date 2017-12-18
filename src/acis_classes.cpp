#include "acis_classes.h"


/**
 * SPAposition wrapper
 */

static void
a3dp_SPAposition_dealloc(a3dp_SPAposition *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAposition_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAposition *self;

  self = (a3dp_SPAposition *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAposition_init(a3dp_SPAposition *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  char *kwlist[] =
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
a3dp_SPAposition_repr(a3dp_SPAposition *self)
{
  double x = self->_acis_obj->x(); double y = self->_acis_obj->y(); double z = self->_acis_obj->z();

  char *_x = PyOS_double_to_string(x, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_x)
    return PyErr_NoMemory();

  char *_y = PyOS_double_to_string(y, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_y)
    return PyErr_NoMemory();

  char *_z = PyOS_double_to_string(z, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_z)
    return PyErr_NoMemory();

  return PyUnicode_FromFormat("SPAposition object (%s, %s, %s)", _x, _y, _z);
}

static PyObject *
a3dp_SPAposition__coordinate(a3dp_SPAposition *self, PyObject *arg)
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
a3dp_SPAposition__set_coordinate(a3dp_SPAposition *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  char *kwlist[] =
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
a3dp_SPAposition__set_x(a3dp_SPAposition *self, PyObject *arg)
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
a3dp_SPAposition__set_y(a3dp_SPAposition *self, PyObject *arg)
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
a3dp_SPAposition__set_z(a3dp_SPAposition *self, PyObject *arg)
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
a3dp_SPAposition__x(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
a3dp_SPAposition__y(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
a3dp_SPAposition__z(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
a3dp_SPAposition_x_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__x(self);
}

static PyObject *
a3dp_SPAposition_y_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__y(self);
}

static PyObject *
a3dp_SPAposition_z_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__z(self);
}

static int
a3dp_SPAposition_x_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_x(self, value);
  return 0;
}

static int
a3dp_SPAposition_y_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_y(self, value);
  return 0;
}

static int
a3dp_SPAposition_z_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_z(self, value);
  return 0;
}

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

PyTypeObject
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

bool
_PyCheck_SPAposition(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAposition);
}

PyObject *
_PyNew_SPAposition()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAposition, NULL);
}

/**
 * SPAvector class
 */

static void
a3dp_SPAvector_dealloc(a3dp_SPAvector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAvector_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAvector *self;

  self = (a3dp_SPAvector *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAvector_init(a3dp_SPAvector *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  char *kwlist[] =
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
a3dp_SPAvector_repr(a3dp_SPAvector *self)
{
  double x = self->_acis_obj->x(); double y = self->_acis_obj->y(); double z = self->_acis_obj->z();

  char *_x = PyOS_double_to_string(x, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_x)
    return PyErr_NoMemory();

  char *_y = PyOS_double_to_string(y, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_y)
    return PyErr_NoMemory();

  char *_z = PyOS_double_to_string(z, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_z)
    return PyErr_NoMemory();

  return PyUnicode_FromFormat("SPAvector object (%s, %s, %s)", _x, _y, _z);
}

static PyObject *
a3dp_SPAvector__component(a3dp_SPAvector *self, PyObject *arg)
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
a3dp_SPAvector__set_component(a3dp_SPAvector *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  char *kwlist[] =
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
a3dp_SPAvector__set_x(a3dp_SPAvector *self, PyObject *arg)
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
a3dp_SPAvector__set_y(a3dp_SPAvector *self, PyObject *arg)
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
a3dp_SPAvector__set_z(a3dp_SPAvector *self, PyObject *arg)
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
a3dp_SPAvector__x(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
a3dp_SPAvector__y(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
a3dp_SPAvector__z(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
a3dp_SPAvector_x_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__x(self);
}

static PyObject *
a3dp_SPAvector_y_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__y(self);
}

static PyObject *
a3dp_SPAvector_z_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__z(self);
}

static int
a3dp_SPAvector_x_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_x(self, value);
  return 0;
}

static int
a3dp_SPAvector_y_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_y(self, value);
  return 0;
}

static int
a3dp_SPAvector_z_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_z(self, value);
  return 0;
}

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

PyTypeObject
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

bool
_PyCheck_SPAvector(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAvector);
}

PyObject *
_PyNew_SPAvector()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAvector, NULL);
}


/**
 * SPAunit_vector wrapper
 */

static void
a3dp_SPAunitvector_dealloc(a3dp_SPAunit_vector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAunitvector_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAunit_vector *self;

  self = (a3dp_SPAunit_vector *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAunitvector_init(a3dp_SPAunit_vector *self, PyObject *args, PyObject *kwargs)
{
  double input_x = 0.0, input_y = 0.0, input_z = 0.0;

  char *kwlist[] =
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
a3dp_SPAunitvector_repr(a3dp_SPAunit_vector *self)
{
  double x = self->_acis_obj->x(); double y = self->_acis_obj->y(); double z = self->_acis_obj->z();

  char *_x = PyOS_double_to_string(x, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_x)
    return PyErr_NoMemory();

  char *_y = PyOS_double_to_string(y, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_y)
    return PyErr_NoMemory();

  char *_z = PyOS_double_to_string(z, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_z)
    return PyErr_NoMemory();

  return PyUnicode_FromFormat("SPAunit_vector object (%s, %s, %s)", _x, _y, _z);
}

static PyObject *
a3dp_SPAunitvector__component(a3dp_SPAunit_vector *self, PyObject *arg)
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
a3dp_SPAunitvector__set_component(a3dp_SPAunit_vector *self, PyObject *args, PyObject *kwargs)
{
  int _i;
  double _new_c;

  char *kwlist[] =
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
a3dp_SPAunitvector__set_x(a3dp_SPAunit_vector *self, PyObject *arg)
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
a3dp_SPAunitvector__set_y(a3dp_SPAunit_vector *self, PyObject *arg)
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
a3dp_SPAunitvector__set_z(a3dp_SPAunit_vector *self, PyObject *arg)
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
a3dp_SPAunitvector__x(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

static PyObject *
a3dp_SPAunitvector__y(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

static PyObject *
a3dp_SPAunitvector__z(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

static PyObject *
a3dp_SPAunitvector_x_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__x(self);
}

static PyObject *
a3dp_SPAunitvector_y_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__y(self);
}

static PyObject *
a3dp_SPAunitvector_z_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__z(self);
}

static int
a3dp_SPAunitvector_x_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_x(self, value);
  return 0;
}

static int
a3dp_SPAunitvector_y_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_y(self, value);
  return 0;
}

static int
a3dp_SPAunitvector_z_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_z(self, value);
  return 0;
}

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

PyTypeObject
  a3dp_type_SPAunit_vector =
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

bool
_PyCheck_SPAunit_vector(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAunit_vector);
}

PyObject *
_PyNew_SPAunit_vector()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAunit_vector, NULL);
}

/**
 * SPAmatrix wrapper
 */

static void
a3dp_SPAmatrix_dealloc(a3dp_SPAmatrix *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAmatrix_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAmatrix *self;

  self = (a3dp_SPAmatrix *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAmatrix_init(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAmatrix();

  return 0;
}

static PyObject *
a3dp_SPAmatrix__column(a3dp_SPAmatrix *self, PyObject *arg)
{
  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  // Create a new SPAvector python object
  PyObject *_python_ret = _PyNew_SPAvector();

  // Convert python input argument into a C variable
  int _in_col = (int) PyLong_AsLong(arg);

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAvector *) _python_ret)->_acis_obj = self->_acis_obj->column(_in_col);

  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  // Return the updated python object
  return _python_ret;
}

static PyObject *
a3dp_SPAmatrix__row(a3dp_SPAmatrix *self, PyObject *arg)
{
  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "The input argument must be an integer");
    return NULL;
  }

  // Create a new SPAvector python object
  PyObject *_python_ret = _PyNew_SPAvector();

  // Convert python input argument into a C variable
  int _in_row = (int) PyLong_AsLong(arg);

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAvector *) _python_ret)->_acis_obj = self->_acis_obj->row(_in_row);

  // Treat the input argument as a borrowed reference
  Py_INCREF(arg);

  // Return the updated python object
  return _python_ret;
}

static PyObject *
a3dp_SPAmatrix__inverse(a3dp_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _PyNew_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->inverse();

  // Return the updated python object
  return _python_ret;
}

static PyObject *
a3dp_SPAmatrix__transpose(a3dp_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _PyNew_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->transpose();

  // Return the updated python object
  return _python_ret;
}

static PyObject *
a3dp_SPAmatrix__determinant(a3dp_SPAmatrix *self)
{
  // Execute the ACIS function and return the value as a python object
  return PyFloat_FromDouble(self->_acis_obj->determinant());
}

static PyObject *
a3dp_SPAmatrix__element(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  int input_row, input_col;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
a3dp_SPAmatrix__set_element(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  int input_row, input_col;
  double input_new_e;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
a3dp_SPAmatrix__is_identity(a3dp_SPAmatrix *self)
{
  logical _ret_val = self->_acis_obj->is_identity();

  if (_ret_val)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

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

PyTypeObject
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

bool
_PyCheck_SPAmatrix(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAmatrix);
}

PyObject
*_PyNew_SPAmatrix()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAmatrix, NULL);
}

/**
 * SPAtransf wrapper
 */

static void
a3dp_SPAtransf_dealloc(a3dp_SPAtransf *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAtransf_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAtransf *self;

  self = (a3dp_SPAtransf *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAtransf_init(a3dp_SPAtransf *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAtransf();

  return 0;
}

static PyObject *
a3dp_SPAtransf__affine(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAmatrix();

  *((a3dp_SPAmatrix *) _ret)->_acis_obj = self->_acis_obj->affine();

  return _ret;
}

static PyObject *
a3dp_SPAtransf__inverse(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAtransf();

  *((a3dp_SPAtransf *) _ret)->_acis_obj = self->_acis_obj->inverse();

  return _ret;
}

static PyObject *
a3dp_SPAtransf__translation(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAvector();

  *((a3dp_SPAvector *) _ret)->_acis_obj = self->_acis_obj->translation();

  return _ret;
}

static PyObject *
a3dp_SPAtransf__identity(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->identity();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
a3dp_SPAtransf__reflect(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->reflect();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
a3dp_SPAtransf__rotate(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->rotate();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
a3dp_SPAtransf__scaling(a3dp_SPAtransf *self)
{
  return PyFloat_FromDouble(self->_acis_obj->scaling());
}

static PyObject *
a3dp_SPAtransf__shear(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->shear();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

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

PyTypeObject
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

bool
_PyCheck_SPAtransf(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAtransf);
}

PyObject *
_PyNew_SPAtransf()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAtransf, NULL);
}

/**
 * SPApar_pos wrapper
 */

static void
a3dp_SPAparpos_dealloc(a3dp_SPApar_pos *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAparpos_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPApar_pos *self;

  self = (a3dp_SPApar_pos *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAparpos_init(a3dp_SPApar_pos *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPApar_pos();

  return 0;
}

static PyObject *
a3dp_SPAparpos_repr(a3dp_SPApar_pos *self)
{
  double u = self->_acis_obj->u; double v = self->_acis_obj->v;

  char *_u = PyOS_double_to_string(u, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_u)
    return PyErr_NoMemory();

  char *_v = PyOS_double_to_string(v, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_v)
    return PyErr_NoMemory();

  return PyUnicode_FromFormat("SPApar_pos object (%s, %s)", _u, _v);
}

static PyObject *
a3dp_SPAparpos_u_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->u);
}

static int
a3dp_SPAparpos_u_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  self->_acis_obj->u = PyFloat_AsDouble(value);
  return 0;
}

static PyObject *
a3dp_SPAparpos_v_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->v);
}

static int
a3dp_SPAparpos_v_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  self->_acis_obj->v = PyFloat_AsDouble(value);
  return 0;
}

static PyGetSetDef
  a3dp_getseters_SPAparpos[] =
  {
    { (char *) "u", (getter) a3dp_SPAparpos_u_getter, (setter) a3dp_SPAparpos_u_setter, (char *) "value of the u parameter", NULL },
    { (char *) "v", (getter) a3dp_SPAparpos_v_getter, (setter) a3dp_SPAparpos_v_setter, (char *) "value of the v parameter", NULL },
    { NULL }  /* Sentinel */
  };

PyTypeObject
  a3dp_type_SPApar_pos =
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

bool
_PyCheck_SPApar_pos(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPApar_pos);
}

PyObject *
_PyNew_SPApar_pos()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPApar_pos, NULL);
}

/**
 * SPApar_vec wrapper
 */

static void
a3dp_SPAparvec_dealloc(a3dp_SPApar_vec *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAparvec_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPApar_vec *self;

  self = (a3dp_SPApar_vec *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAparvec_init(a3dp_SPApar_vec *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPApar_vec();

  return 0;
}

static PyObject *
a3dp_SPAparvec_repr(a3dp_SPApar_vec *self)
{
  double du = self->_acis_obj->du; double dv = self->_acis_obj->dv;

  char *_du = PyOS_double_to_string(du, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_du)
    return PyErr_NoMemory();

  char *_dv = PyOS_double_to_string(dv, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
  if (!_dv)
    return PyErr_NoMemory();

  return PyUnicode_FromFormat("SPApar_vec object (%s, %s)", _du, _dv);
}

static PyObject *
a3dp_SPAparvec_du_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->du);
}

static int
a3dp_SPAparvec_du_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  self->_acis_obj->du = PyFloat_AsDouble(value);
  return 0;
}

static PyObject *
a3dp_SPAparvec_dv_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->dv);
}

static int
a3dp_SPAparvec_dv_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  self->_acis_obj->dv = PyFloat_AsDouble(value);
  return 0;
}

static PyGetSetDef
  a3dp_getseters_SPAparvec[] =
  {
    { (char *) "du", (getter) a3dp_SPAparvec_du_getter, (setter) a3dp_SPAparvec_du_setter, (char *) "value of the u parameter", NULL },
    { (char *) "dv", (getter) a3dp_SPAparvec_dv_getter, (setter) a3dp_SPAparvec_dv_setter, (char *) "value of the v parameter", NULL },
    { NULL }  /* Sentinel */
  };

PyTypeObject
  a3dp_type_SPApar_vec =
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

bool
_PyCheck_SPApar_vec(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPApar_vec);
}

PyObject *
_PyNew_SPApar_vec()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPApar_vec, NULL);
}

/**
 * FileInfo class
 */

static void
a3dp_FileInfo_dealloc(a3dp_FileInfo *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object itself
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_FileInfo_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_FileInfo *self;

  self = (a3dp_FileInfo *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_FileInfo_init(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  self->_acis_obj = ACIS_NEW FileInfo();
  return 0;
}

static PyObject *
a3dp_FileInfo__acis_version(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->acis_version());
}

static PyObject *
a3dp_FileInfo__date(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->date());
}

static PyObject *
a3dp_FileInfo__file_version(a3dp_FileInfo *self)
{
  return PyLong_FromLong((long) self->_acis_obj->file_version());
}

static PyObject *
a3dp_FileInfo__product_id(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->product_id());
}

static PyObject *
a3dp_FileInfo__reset(a3dp_FileInfo *self)
{
  self->_acis_obj->reset();
  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__reset_vars(a3dp_FileInfo *self)
{
  self->_acis_obj->reset_vars();
  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__restore(a3dp_FileInfo *self)
{
  self->_acis_obj->restore();
  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__save(a3dp_FileInfo *self)
{
  self->_acis_obj->save();
  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__set_masked(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  unsigned long input_field;
  PyObject *input_file = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "field",
      (char *) "file",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "lO", kwlist, &input_field, &input_file))
    return NULL;

  // Check if the user input is a FileInfo object
  if (_PyCheck_FileInfo(input_file))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  // Convert PyObject to ENTITY_LIST
  FileInfo *_file = ((a3dp_FileInfo *) input_file)->_acis_obj;

  // Execute ACIS function
  self->_acis_obj->set_masked(input_field, *_file);

  // Return None
  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__set_product_id(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  const char *input_id = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "id",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s", kwlist, &input_id))
    return NULL;

  self->_acis_obj->set_product_id(input_id);

  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__set_units(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  double input_count;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "count",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "d", kwlist, &input_count))
    return NULL;

  self->_acis_obj->set_units(input_count);

  Py_RETURN_NONE;
}

static PyObject *
a3dp_FileInfo__tol_abs(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_abs());
}

static PyObject *
a3dp_FileInfo__tol_nor(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_nor());
}

static PyObject *
a3dp_FileInfo__units(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->units());
}

static PyObject *
a3dp_FileInfo__valid(a3dp_FileInfo *self)
{
  self->_acis_obj->valid();
  Py_RETURN_NONE;
}

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

PyTypeObject
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
    0, /* tp_members */
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

bool
_PyCheck_FileInfo(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_FileInfo);
}

/**
 * make_sweep_path_options
 */

static void
a3dp_makesweeppathoptions_dealloc(a3dp_make_sweep_path_options *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_makesweeppathoptions_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_make_sweep_path_options *self;

  self = (a3dp_make_sweep_path_options *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_makesweeppathoptions_init(a3dp_make_sweep_path_options *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW make_sweep_path_options();

  return 0;
}

PyTypeObject
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

PyObject *
_PyNew_make_sweep_path_options()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_make_sweep_path_options, NULL);
}

bool
_PyCheck_make_sweep_path_options(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_make_sweep_path_options);
}


/**
 * sweep_options
 */

static void
a3dp_sweepoptions_dealloc(a3dp_sweep_options *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_sweepoptions_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_sweep_options *self;

  self = (a3dp_sweep_options *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_sweepoptions_init(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW sweep_options();

  return 0;
}

static PyObject *
a3dp_sweepoptions__set_bool_type(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs)
{
  // Just a testing...
  self->_acis_obj->set_bool_type(KEEP_BOTH);

  Py_RETURN_NONE;
}

static PyMethodDef
  a3dp_methods_sweepoptions[] =
  {
    { "set_bool_type", (PyCFunction) a3dp_sweepoptions__set_bool_type, METH_VARARGS | METH_KEYWORDS, "Sets the option for the Boolean operation type with the to_body" },
    { NULL }  /* Sentinel */
  };

PyTypeObject
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

PyObject *
_PyNew_sweep_options()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_sweep_options, NULL);
}

bool
_PyCheck_sweep_options(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_sweep_options);
}


/**
 * BoolOptions
 */

static void
a3dp_BoolOptions_dealloc(a3dp_BoolOptions *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_BoolOptions_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_BoolOptions *self;

  self = (a3dp_BoolOptions *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_BoolOptions_init(a3dp_BoolOptions *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW BoolOptions();

  return 0;
}

PyTypeObject
  a3dp_type_BoolOptions =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.BoolOptions", /* tp_name */
    sizeof(a3dp_BoolOptions), /* tp_basicsize */
    0, /* tp_itemsize */
    (destructor) a3dp_BoolOptions_dealloc, /* tp_dealloc */
    0, /* tp_print */
    0, /* tp_getattr */
    0, /* tp_setattr */
    0, /* tp_reserved */
    0, /* tp_repr */
    0, /* tp_as_number */
    0, /* tp_as_sequence */
    0, /* tp_as_mapping */
    0, /* tp_hash  */
    0, /* tp_call */
    0, /* tp_str */
    0, /* tp_getattro */
    0, /* tp_setattro */
    0, /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT, /* tp_flags */
    "BoolOptions class holds information and options for a Boolean operation", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0, /* tp_richcompare */
    0, /* tp_weaklistoffset */
    0, /* tp_iter */
    0, /* tp_iternext */
    0, /* tp_methods */
    0, /* tp_members */
    0, /* tp_getset */
    0, /* tp_base */
    0, /* tp_dict */
    0, /* tp_descr_get */
    0, /* tp_descr_set */
    0, /* tp_dictoffset */
    (initproc) a3dp_BoolOptions_init, /* tp_init */
    0, /* tp_alloc */
    a3dp_BoolOptions_new, /* tp_new */
  };

PyObject *
_PyNew_BoolOptions()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_BoolOptions, NULL);
}

bool
_PyCheck_BoolOptions(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_BoolOptions);
}


/**
 * SPAboxing_options
 */

static void
a3dp_SPAboxing_options_dealloc(a3dp_BoolOptions *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
a3dp_SPAboxing_options_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_SPAboxing_options *self;

  self = (a3dp_SPAboxing_options *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
a3dp_SPAboxing_options_init(a3dp_SPAboxing_options *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAboxing_options();

  return 0;
}

PyTypeObject
  a3dp_type_SPAboxing_options =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPAboxing_options", /* tp_name */
    sizeof(a3dp_BoolOptions), /* tp_basicsize */
    0, /* tp_itemsize */
    (destructor) a3dp_SPAboxing_options_dealloc, /* tp_dealloc */
    0, /* tp_print */
    0, /* tp_getattr */
    0, /* tp_setattr */
    0, /* tp_reserved */
    0, /* tp_repr */
    0, /* tp_as_number */
    0, /* tp_as_sequence */
    0, /* tp_as_mapping */
    0, /* tp_hash  */
    0, /* tp_call */
    0, /* tp_str */
    0, /* tp_getattro */
    0, /* tp_setattro */
    0, /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT, /* tp_flags */
    "BoolOptions class represents common data and functionality for all boxing options", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0, /* tp_richcompare */
    0, /* tp_weaklistoffset */
    0, /* tp_iter */
    0, /* tp_iternext */
    0, /* tp_methods */
    0, /* tp_members */
    0, /* tp_getset */
    0, /* tp_base */
    0, /* tp_dict */
    0, /* tp_descr_get */
    0, /* tp_descr_set */
    0, /* tp_dictoffset */
    (initproc) a3dp_SPAboxing_options_init, /* tp_init */
    0, /* tp_alloc */
    a3dp_SPAboxing_options_new, /* tp_new */
  };

PyObject *
_PyNew_SPAboxing_options()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAboxing_options, NULL);
}

bool
_PyCheck_SPAboxing_options(PyObject *ob)
{
  return PyObject_TypeCheck(ob, &a3dp_type_SPAboxing_options);
}
