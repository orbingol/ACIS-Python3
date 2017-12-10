#include "acis_classes.h"



/**
 * SPAposition wrapper
 */

void
a3dp_SPAposition_dealloc(a3dp_SPAposition *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
a3dp_SPAposition__x(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

PyObject *
a3dp_SPAposition__y(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

PyObject *
a3dp_SPAposition__z(a3dp_SPAposition *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

PyObject *
a3dp_SPAposition_x_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__x(self);
}

PyObject *
a3dp_SPAposition_y_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__y(self);
}

PyObject *
a3dp_SPAposition_z_getter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  return a3dp_SPAposition__z(self);
}

int
a3dp_SPAposition_x_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_x(self, value);
  return 0;
}

int
a3dp_SPAposition_y_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_y(self, value);
  return 0;
}

int
a3dp_SPAposition_z_setter(a3dp_SPAposition *self, PyObject *value, void *closure)
{
  a3dp_SPAposition__set_z(self, value);
  return 0;
}

bool _PyCheck_SPAposition(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAposition;
}

PyObject *_PyNew_SPAposition()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAposition, NULL);
}

/**
 * SPAvector class
 */

void
a3dp_SPAvector_dealloc(a3dp_SPAvector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
a3dp_SPAvector__x(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

PyObject *
a3dp_SPAvector__y(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

PyObject *
a3dp_SPAvector__z(a3dp_SPAvector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

PyObject *
a3dp_SPAvector_x_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__x(self);
}

PyObject *
a3dp_SPAvector_y_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__y(self);
}

PyObject *
a3dp_SPAvector_z_getter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  return a3dp_SPAvector__z(self);
}

int
a3dp_SPAvector_x_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_x(self, value);
  return 0;
}

int
a3dp_SPAvector_y_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_y(self, value);
  return 0;
}

int
a3dp_SPAvector_z_setter(a3dp_SPAvector *self, PyObject *value, void *closure)
{
  a3dp_SPAvector__set_z(self, value);
  return 0;
}

bool _PyCheck_SPAvector(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAvector;
}

PyObject *_PyNew_SPAvector()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAvector, NULL);
}

/**
 * SPAunit_vector wrapper
 */

void
a3dp_SPAunitvector_dealloc(a3dp_SPAunit_vector *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
a3dp_SPAunitvector__x(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->x());
}

PyObject *
a3dp_SPAunitvector__y(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->y());
}

PyObject *
a3dp_SPAunitvector__z(a3dp_SPAunit_vector *self)
{
  return PyFloat_FromDouble(self->_acis_obj->z());
}

PyObject *
a3dp_SPAunitvector_x_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__x(self);
}

PyObject *
a3dp_SPAunitvector_y_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__y(self);
}

PyObject *
a3dp_SPAunitvector_z_getter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  return a3dp_SPAunitvector__z(self);
}

int
a3dp_SPAunitvector_x_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_x(self, value);
  return 0;
}

int
a3dp_SPAunitvector_y_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_y(self, value);
  return 0;
}

int
a3dp_SPAunitvector_z_setter(a3dp_SPAunit_vector *self, PyObject *value, void *closure)
{
  a3dp_SPAunitvector__set_z(self, value);
  return 0;
}

bool _PyCheck_SPAunit_vector(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAunitvector;
}

PyObject *_PyNew_SPAunit_vector()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAunitvector, NULL);
}

/**
 * SPAmatrix wrapper
 */

void
a3dp_SPAmatrix_dealloc(a3dp_SPAmatrix *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_SPAmatrix_init(a3dp_SPAmatrix *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAmatrix();

  return 0;
}

PyObject *
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

PyObject *
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

PyObject *
a3dp_SPAmatrix__inverse(a3dp_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _PyNew_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->inverse();

  // Return the updated python object
  return _python_ret;
}

PyObject *
a3dp_SPAmatrix__transpose(a3dp_SPAmatrix *self)
{
  // Create a new SPAmatrix python object
  PyObject *_python_ret = _PyNew_SPAmatrix();

  // Execute the ACIS function and set ACIS variable inside the new python object
  *((a3dp_SPAmatrix *) _python_ret)->_acis_obj = self->_acis_obj->transpose();

  // Return the updated python object
  return _python_ret;
}

PyObject *
a3dp_SPAmatrix__determinant(a3dp_SPAmatrix *self)
{
  // Execute the ACIS function and return the value as a python object
  return PyFloat_FromDouble(self->_acis_obj->determinant());
}

PyObject *
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

PyObject *
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

PyObject *
a3dp_SPAmatrix__is_identity(a3dp_SPAmatrix *self)
{
  logical _ret_val = self->_acis_obj->is_identity();

  if (_ret_val)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

bool _PyCheck_SPAmatrix(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAmatrix;
}

PyObject *_PyNew_SPAmatrix()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAmatrix, NULL);
}

/**
 * SPAtransf wrapper
 */

void
a3dp_SPAtransf_dealloc(a3dp_SPAtransf *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_SPAtransf_init(a3dp_SPAtransf *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPAtransf();

  return 0;
}

PyObject *
a3dp_SPAtransf__affine(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAmatrix();

  *((a3dp_SPAmatrix *) _ret)->_acis_obj = self->_acis_obj->affine();

  return _ret;
}

PyObject *
a3dp_SPAtransf__inverse(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAtransf();

  *((a3dp_SPAtransf *) _ret)->_acis_obj = self->_acis_obj->inverse();

  return _ret;
}

PyObject *
a3dp_SPAtransf__translation(a3dp_SPAtransf *self)
{
  PyObject *_ret = _PyNew_SPAvector();

  *((a3dp_SPAvector *) _ret)->_acis_obj = self->_acis_obj->translation();

  return _ret;
}

PyObject *
a3dp_SPAtransf__identity(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->identity();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

PyObject *
a3dp_SPAtransf__reflect(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->reflect();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

PyObject *
a3dp_SPAtransf__rotate(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->rotate();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

PyObject *
a3dp_SPAtransf__scaling(a3dp_SPAtransf *self)
{
  return PyFloat_FromDouble(self->_acis_obj->scaling());
}

PyObject *
a3dp_SPAtransf__shear(a3dp_SPAtransf *self)
{
  logical _check = self->_acis_obj->shear();

  if (_check)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}


bool _PyCheck_SPAtransf(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAtransf;
}

PyObject *_PyNew_SPAtransf()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAtransf, NULL);
}

/**
 * SPApar_pos wrapper
 */

void
a3dp_SPAparpos_dealloc(a3dp_SPApar_pos *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_SPAparpos_init(a3dp_SPApar_pos *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPApar_pos();

  return 0;
}

PyObject *
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

PyObject *
a3dp_SPAparpos_u_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->u);
}

int
a3dp_SPAparpos_u_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  self->_acis_obj->u = PyFloat_AsDouble(value);
  return 0;
}

PyObject *
a3dp_SPAparpos_v_getter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->v);
}

int
a3dp_SPAparpos_v_setter(a3dp_SPApar_pos *self, PyObject *value, void *closure)
{
  self->_acis_obj->v = PyFloat_AsDouble(value);
  return 0;
}

bool _PyCheck_SPApar_pos(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAparpos;
}

PyObject *_PyNew_SPApar_pos()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAparpos, NULL);
}

/**
 * SPApar_vec wrapper
 */

void
a3dp_SPAparvec_dealloc(a3dp_SPApar_vec *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_SPAparvec_init(a3dp_SPApar_vec *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW SPApar_vec();

  return 0;
}

PyObject *
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

PyObject *
a3dp_SPAparvec_du_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->du);
}

int
a3dp_SPAparvec_du_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  self->_acis_obj->du = PyFloat_AsDouble(value);
  return 0;
}

PyObject *
a3dp_SPAparvec_dv_getter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  return PyFloat_FromDouble(self->_acis_obj->dv);
}

int
a3dp_SPAparvec_dv_setter(a3dp_SPApar_vec *self, PyObject *value, void *closure)
{
  self->_acis_obj->dv = PyFloat_AsDouble(value);
  return 0;
}

bool _PyCheck_SPApar_vec(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPAparvec;
}

PyObject *_PyNew_SPApar_vec()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPAparvec, NULL);
}


/**
 * FileInfo class
 */

void
a3dp_FileInfo_dealloc(a3dp_FileInfo *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object itself
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_FileInfo_init(a3dp_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  self->_acis_obj = ACIS_NEW FileInfo();
  return 0;
}

PyObject *
a3dp_FileInfo__acis_version(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->acis_version());
}

PyObject *
a3dp_FileInfo__date(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->date());
}

PyObject *
a3dp_FileInfo__file_version(a3dp_FileInfo *self)
{
  return PyLong_FromLong((long) self->_acis_obj->file_version());
}

PyObject *
a3dp_FileInfo__product_id(a3dp_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->product_id());
}

PyObject *
a3dp_FileInfo__reset(a3dp_FileInfo *self)
{
  self->_acis_obj->reset();
  Py_RETURN_NONE;
}

PyObject *
a3dp_FileInfo__reset_vars(a3dp_FileInfo *self)
{
  self->_acis_obj->reset_vars();
  Py_RETURN_NONE;
}

PyObject *
a3dp_FileInfo__restore(a3dp_FileInfo *self)
{
  self->_acis_obj->restore();
  Py_RETURN_NONE;
}

PyObject *
a3dp_FileInfo__save(a3dp_FileInfo *self)
{
  self->_acis_obj->save();
  Py_RETURN_NONE;
}

PyObject *
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

PyObject *
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

PyObject *
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

PyObject *
a3dp_FileInfo__tol_abs(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_abs());
}

PyObject *
a3dp_FileInfo__tol_nor(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_nor());
}

PyObject *
a3dp_FileInfo__units(a3dp_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->units());
}

PyObject *
a3dp_FileInfo__valid(a3dp_FileInfo *self)
{
  self->_acis_obj->valid();
  Py_RETURN_NONE;
}

bool
_PyCheck_FileInfo(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_FileInfo;
}

void
a3dp_makesweeppathoptions_dealloc(a3dp_make_sweep_path_options *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_makesweeppathoptions_init(a3dp_make_sweep_path_options *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW make_sweep_path_options();

  return 0;
}

void
a3dp_sweepoptions_dealloc(a3dp_sweep_options *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
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

int
a3dp_sweepoptions_init(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW sweep_options();

  return 0;
}

PyObject *
a3dp_sweepoptions__set_bool_type(a3dp_sweep_options *self, PyObject *args, PyObject *kwargs)
{
  // Just a testing...
  self->_acis_obj->set_bool_type(KEEP_BOTH);

  Py_RETURN_NONE;
}


PyObject *
_PyNew_make_sweep_path_options()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_make_sweep_path_options, NULL);
}

bool
_PyCheck_make_sweep_path_options(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_make_sweep_path_options;
}

PyObject *
_PyNew_sweep_options()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_sweep_options, NULL);
}

bool
_PyCheck_sweep_options(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_sweep_options;
}
