#include "acis_operators.h"


PyObject *
a3dp_coordinate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_origin = NULL, *input_x_axis = NULL, *input_y_axis = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (!_PyCheck_SPAposition(input_origin))
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (new_origin) must be a SPAposition object");
    return NULL;
  }

  if (!_PyCheck_SPAunit_vector(input_x_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Second parameter (new_x_axis) must be a SPAunit_vector object");
    return NULL;
  }

  if (!_PyCheck_SPAunit_vector(input_y_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Third parameter (new_y_axis) must be a SPAunit_vector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAposition *&_new_origin = ((a3dp_SPAposition *) input_origin)->_acis_obj;
  SPAunit_vector *&_new_x_axis = ((a3dp_SPAunit_vector *) input_x_axis)->_acis_obj;
  SPAunit_vector *&_new_y_axis = ((a3dp_SPAunit_vector *) input_y_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = coordinate_transf(*_new_origin, *_new_x_axis, *_new_y_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_make_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_affine = NULL, *input_translation = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "affine",
      (char *) "translation",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_affine, &input_translation))
    return NULL;

  // Check inputs
  if (!_PyCheck_SPAmatrix(input_affine))
  {
    PyErr_SetString(PyExc_TypeError, "First parameter (affine) must be a SPAmatrix object");
    return NULL;
  }

  if (!_PyCheck_SPAvector(input_translation))
  {
    PyErr_SetString(PyExc_TypeError, "Second parameter (translate) must be a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAmatrix *&_affine = ((a3dp_SPAmatrix *) input_affine)->_acis_obj;
  SPAvector *&_translation = ((a3dp_SPAvector *) input_translation)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = make_transf(*_affine, *_translation);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_reflect_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_axis = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "axis",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_axis))
    return NULL;

  // Check inputs
  if (!_PyCheck_SPAvector(input_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_axis = ((a3dp_SPAvector *) input_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = reflect_transf(*_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_rotate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_axis = NULL;
  double input_angle;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "angle",
      (char *) "axis",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "dO", kwlist, &input_angle, &input_axis))
    return NULL;

  // Check inputs
  if (!_PyCheck_SPAvector(input_axis))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_axis = ((a3dp_SPAvector *) input_axis)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = rotate_transf(input_angle, *_axis);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_scale_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_arg1 = NULL, *input_arg2 = NULL, *input_arg3 = NULL, *input_arg4 = NULL, *input_arg5 = NULL, *input_arg6 = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_shear_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double _shear_xy, _shear_xz, _shear_yz;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_translate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_disp = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "disp",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_disp))
    return NULL;

  // "disp" must be a SPAvector object
  if (!_PyCheck_SPAvector(input_disp))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting SPAvector object");
    return NULL;
  }

  // Get the ACIS object from the user input
  SPAvector *&_disp = ((a3dp_SPAvector *) input_disp)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = translate_transf(*_disp);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_angle_between(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL, *input_z = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (_PyCheck_SPAvector(input_v1))
  {
    if (!_PyCheck_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((a3dp_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((a3dp_SPAvector *) input_v2)->_acis_obj;

    if (input_z != NULL)
    {
      if (!_PyCheck_SPAvector(input_z))
      {
        PyErr_SetString(PyExc_TypeError, "Third parameter (z) should be a SPAunit_vector object");
        return NULL;
      }

      SPAunit_vector *&_z = ((a3dp_SPAunit_vector *) input_z)->_acis_obj;

      _retval = angle_between(*_v1, *_v2, *_z);
    }
    else
    {
      _retval = angle_between(*_v1, *_v2);
    }
  }
  else if (_PyCheck_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_PyCheck_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((a3dp_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((a3dp_SPAunit_vector *) input_v2)->_acis_obj;

    if (input_z != NULL)
    {
      if (!_PyCheck_SPAunit_vector(input_z))
      {
        PyErr_SetString(PyExc_TypeError, "Third parameter (z) should be a SPAunit_vector object");
        return NULL;
      }

      SPAunit_vector *&_z = ((a3dp_SPAunit_vector *) input_z)->_acis_obj;

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

PyObject *
a3dp_antiparallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  double input_res = -1.0;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (_PyCheck_SPAvector(input_v1))
  {
    if (!_PyCheck_SPAvector(input_v2) || !_PyCheck_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector or SPAunit_vector object");
      return NULL;
    }

    SPAvector *&_v1 = ((a3dp_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((a3dp_SPAvector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = antiparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = antiparallel(*_v1, *_v2);
    }
  }
  else if (_PyCheck_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_PyCheck_SPAunit_vector(input_v2) || !_PyCheck_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector or SPAvector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((a3dp_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((a3dp_SPAunit_vector *) input_v2)->_acis_obj;

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

PyObject *
a3dp_are_parallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  int input_same_dir = 0;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (_PyCheck_SPAvector(input_v1))
  {
    if (!_PyCheck_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((a3dp_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((a3dp_SPAvector *) input_v2)->_acis_obj;

    _retval = are_parallel(*_v1, *_v2, input_same_dir);
  }
  else if (_PyCheck_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_PyCheck_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((a3dp_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((a3dp_SPAunit_vector *) input_v2)->_acis_obj;

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

PyObject *
a3dp_are_perpendicular(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (_PyCheck_SPAvector(input_v1))
  {
    if (!_PyCheck_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((a3dp_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((a3dp_SPAvector *) input_v2)->_acis_obj;

    _retval = are_perpendicular(*_v1, *_v2);
  }
  else if (_PyCheck_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_PyCheck_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((a3dp_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((a3dp_SPAunit_vector *) input_v2)->_acis_obj;

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

PyObject *
a3dp_biparallel(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_v1 = NULL, *input_v2 = NULL;
  double input_res = -1.0;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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
  if (_PyCheck_SPAvector(input_v1))
  {
    if (!_PyCheck_SPAvector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAvector object");
      return NULL;
    }

    SPAvector *&_v1 = ((a3dp_SPAvector *) input_v1)->_acis_obj;
    SPAvector *&_v2 = ((a3dp_SPAvector *) input_v2)->_acis_obj;

    if (input_res >= 0.0)
    {
      _retval = biparallel(*_v1, *_v2, input_res);
    }
    else
    {
      _retval = biparallel(*_v1, *_v2);
    }
  }
  else if (_PyCheck_SPAunit_vector(input_v1))
  {
    // SPAunit_vector scenario
    if (!_PyCheck_SPAunit_vector(input_v2))
    {
      PyErr_SetString(PyExc_TypeError, "Second parameter (v2) should be a SPAunit_vector object");
      return NULL;
    }

    SPAunit_vector *&_v1 = ((a3dp_SPAunit_vector *) input_v1)->_acis_obj;
    SPAunit_vector *&_v2 = ((a3dp_SPAunit_vector *) input_v2)->_acis_obj;

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

PyObject *
a3dp_degrees_to_radians(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_ang;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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

PyObject *
a3dp_radians_to_degrees(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_ang;

  // List of keyword arguments that this function can take
  char *kwlist[] =
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

PyObject *
a3dp_get_resabs(PyObject *self)
{
  return PyFloat_FromDouble(get_resabs());
}

PyObject *
a3dp_get_resfit(PyObject *self)
{
  return PyFloat_FromDouble(get_resfit());
}

PyObject *
a3dp_get_resmch(PyObject *self)
{
  return PyFloat_FromDouble(get_resmch());
}

PyObject *
a3dp_get_resnor(PyObject *self)
{
  return PyFloat_FromDouble(get_resnor());
}

PyObject *
a3dp_distance_to_point(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "pt1",
      (char *) "pt2",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pt1, &input_pt2))
    return NULL;

  if (!_PyCheck_SPAposition(input_pt1) || !_PyCheck_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "Input values should be SPAposition objects");
    return NULL;
  }

  SPAposition *&_pt1 = ((a3dp_SPAposition *) input_pt1)->_acis_obj;
  SPAposition *&_pt2 = ((a3dp_SPAposition *) input_pt2)->_acis_obj;

  // Return double
  return PyFloat_FromDouble(distance_to_point(*_pt1, *_pt2));
}

PyObject *
a3dp_distance_to_point_squared(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "pt1",
      (char *) "pt2",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pt1, &input_pt2))
    return NULL;

  if (!_PyCheck_SPAposition(input_pt1) || !_PyCheck_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "Input values should be SPAposition objects");
    return NULL;
  }

  SPAposition *&_pt1 = ((a3dp_SPAposition *) input_pt1)->_acis_obj;
  SPAposition *&_pt2 = ((a3dp_SPAposition *) input_pt2)->_acis_obj;

  // Return double
  return PyFloat_FromDouble(distance_to_point_squared(*_pt1, *_pt2));
}
