#include "acis_api.h"


bool disabled_acis_freelisting = false;

PyObject *
a3dp_api_start_modeller(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_n = 0;
  int input_freelisting = 1;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "n",
      (char *) "freelisting",
      NULL
    };

  // Try to parse input arguments and/or keywords
  // api_start_modeller does not utilize the "n" argument, but following the implementation but make it optional
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ii", kwlist, &input_n, &input_freelisting))
    return NULL;

  // Disable ACIS freelisting facility if freelisting=False
  if (!input_freelisting)
  {
    // Display a warning message
    PyErr_WarnEx(PyExc_Warning, "Disabling ACIS freelisting...", 0);
    // Disable ACIS freelisting
    base_configuration base_config;
    base_config.enable_freelists = FALSE;
    base_config.raw_allocator = malloc;
    base_config.raw_destructor = free;
    initialize_base(&base_config);
    // Set the global variable for terminate_nase
    disabled_acis_freelisting = true;
  }

  // Call ACIS API and check outcome
  outcome result;
  result = api_start_modeller(input_n);
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_stop_modeller(PyObject *self)
{
  // Call ACIS API and check outcome
  outcome result;
  result = api_stop_modeller();

  // If ACIS freelisting disabled, we need to call terminate_base()
  if (disabled_acis_freelisting)
  {
    // Display a warning message
    PyErr_WarnEx(PyExc_Warning, "Terminating ACIS...", 0);
    terminate_base();
  }

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_set_dbl_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  double input_value;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "name",
      (char *) "value",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sd", kwlist, &input_name, &input_value))
    return NULL;

  API_BEGIN

            result = api_set_dbl_option(input_name, input_value);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_set_int_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  int input_value;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "name",
      (char *) "value",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "si", kwlist, &input_name, &input_value))
    return NULL;

  API_BEGIN

            result = api_set_int_option(input_name, input_value);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_set_str_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  const char *input_value = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "name",
      (char *) "value",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ss", kwlist, &input_name, &input_value))
    return NULL;

  API_BEGIN

            result = api_set_str_option(input_name, input_value);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_solid_block(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL, *input_block = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "pt1",
      (char *) "pt2",
      (char *) "block",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO", kwlist, &input_pt1, &input_pt2, &input_block))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_SPAposition(input_pt1))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a SPAposition object");
    return NULL;
  }

  if (!_PyCheck_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a SPAposition object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_block))
  {
    PyErr_SetString(PyExc_TypeError, "The third argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            SPAposition *_pt1 = ((a3dp_SPAposition *) input_pt1)->_acis_obj;
            SPAposition *_pt2 = ((a3dp_SPAposition *) input_pt2)->_acis_obj;
            BODY * &_block = (BODY *&) ((a3dp_BODY *) input_block)->base_obj._acis_obj;

            // Call ACIS API
            result = api_solid_block(*_pt1, *_pt2, _block);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_cuboid(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_x, input_y, input_z;
  PyObject *input_body = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "x",
      (char *) "y",
      (char *) "z",
      (char *) "body",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "dddO", kwlist, &input_x, &input_y, &input_z, &input_body))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_body))
  {
    PyErr_SetString(PyExc_TypeError, "The fourth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_body = (BODY *&) ((a3dp_BODY *) input_body)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_cuboid(input_x, input_y, input_z, _body);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_frustum(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2, input_top;
  PyObject *input_frust = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "height",
      (char *) "radius1",
      (char *) "radius2",
      (char *) "top",
      (char *) "frust",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddddO", kwlist, &input_height, &input_radius1, &input_radius2, &input_top, &input_frust))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_frust))
  {
    PyErr_SetString(PyExc_TypeError, "The fifth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_frust = (BODY *&) ((a3dp_BODY *) input_frust)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_frustum(input_height, input_radius1, input_radius2, input_top, _frust);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_prism(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2;
  int input_nsides;
  PyObject *input_prism = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "height",
      (char *) "radius1",
      (char *) "radius2",
      (char *) "nsides",
      (char *) "frust",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "dddiO", kwlist, &input_height, &input_radius1, &input_radius2, &input_nsides, &input_prism))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_prism))
  {
    PyErr_SetString(PyExc_TypeError, "The fifth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_prism = (BODY *&) ((a3dp_BODY *) input_prism)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_prism(input_height, input_radius1, input_radius2, input_nsides, _prism);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_pyramid(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2, input_top;
  int input_nsides;
  PyObject *input_pyramid = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "height",
      (char *) "radius1",
      (char *) "radius2",
      (char *) "top",
      (char *) "nsides",
      (char *) "pyramid",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddddiO", kwlist, &input_height, &input_radius1, &input_radius2, &input_top, &input_nsides, &input_pyramid))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_pyramid))
  {
    PyErr_SetString(PyExc_TypeError, "The sixth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_pyramid = (BODY *&) ((a3dp_BODY *) input_pyramid)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_pyramid(input_height, input_radius1, input_radius2, input_top, input_nsides, _pyramid);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_sphere(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_radius;
  PyObject *input_sph = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "radius",
      (char *) "sph",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddddiO", kwlist, &input_radius, &input_sph))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_sph))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_sph = (BODY *&) ((a3dp_BODY *) input_sph)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_sphere(input_radius, _sph);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_make_torus(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_major_r, input_minor_r;
  PyObject *input_tor = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "major_radius",
      (char *) "minor_radius",
      (char *) "tor",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddddiO", kwlist, &input_major_r, &input_minor_r, &input_tor))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_tor))
  {
    PyErr_SetString(PyExc_TypeError, "The third argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tor = (BODY *&) ((a3dp_BODY *) input_tor)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_torus(input_major_r, input_minor_r, _tor);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_apply_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_entity = NULL, *input_trans = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "entity",
      (char *) "trans",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_entity, &input_trans))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_entity))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_SPAtransf(input_trans))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a SPAtransf object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            ENTITY * &_entity = ((a3dp_BODY *) input_entity)->base_obj._acis_obj;
            SPAtransf *&_trans = ((a3dp_SPAtransf *) input_trans)->_acis_obj;

            // Call ACIS API
            result = api_apply_transf(_entity, *_trans);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_remove_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_entity = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "entity",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_entity))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_entity))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            ENTITY * &_entity = ((a3dp_BODY *) input_entity)->base_obj._acis_obj;

            // Call ACIS API
            result = api_remove_transf(_entity);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_sheet_from_ff(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_faces = NULL, *input_body = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "faces",
      (char *) "body",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_faces, &input_body))
    return NULL;

  // First argument must be a tuple of faces
  PyObject *seq = PySequence_Fast(input_faces, "First argument must be a sequence of FACE objects");

  // ACIS API has a limitation in api_sheet_from_ff function: As of version R2017, it can handle only 1 face
  Py_ssize_t face_array_size = PySequence_Fast_GET_SIZE(seq);
  if (face_array_size <= 0)
  {
    PyErr_SetString(PyExc_ValueError, "Sequence cannot be empty");
    Py_DECREF(seq);
    return NULL;
  }
  else if (face_array_size > 1)
  {
    PyErr_WarnEx(PyExc_Warning, "ACIS API does not support generation of sheet bodies from multiple faces.", 0);
  }

  PyObject *faceobj = PySequence_Fast_GET_ITEM(seq, 0);

  API_BEGIN

            FACE * &_face = (FACE *&) ((a3dp_FACE *) faceobj)->base_obj._acis_obj;

            FACE * _faces[1];
            _faces[0] = _face;

            BODY * &_body = (BODY *&) ((a3dp_BODY *) input_body)->base_obj._acis_obj;

            result = api_sheet_from_ff(1, _faces, _body);

  API_END

  // PySequence_Fast generates a new reference
  Py_DECREF(seq);

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

/**
 * Booleans API Interface Functions
 */

PyObject *
a3dp_api_unite(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL, *input_boolopts = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      (char *) "boolopts",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_tool, &input_blank))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  if (input_boolopts != NULL)
  {
    if (!_PyCheck_BoolOptions(input_boolopts))
    {
      PyErr_SetString(PyExc_TypeError, "boolopts must be a BoolOptions object");
      return NULL;
    }
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tool = (BODY *&) ((a3dp_BODY *) input_tool)->base_obj._acis_obj;
            BODY * &_blank = (BODY *&) ((a3dp_BODY *) input_blank)->base_obj._acis_obj;

            if (input_boolopts)
            {
              BoolOptions *_boolopts = ((a3dp_BoolOptions *) input_boolopts)->_acis_obj;
              result = api_unite(_tool, _blank, _boolopts);
            }
            else
            {
              result = api_unite(_tool, _blank);
            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Boolean operations automatically delete tool bodies, but for python, we need to set reference to NULL too
    __make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_intersect(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL, *input_boolopts = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      (char *) "boolopts",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|O", kwlist, &input_tool, &input_blank, &input_boolopts))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  if (input_boolopts != NULL)
  {
    if (!_PyCheck_BoolOptions(input_boolopts))
    {
      PyErr_SetString(PyExc_TypeError, "boolopts must be a BoolOptions object");
      return NULL;
    }
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tool = (BODY *&) ((a3dp_BODY *) input_tool)->base_obj._acis_obj;
            BODY * &_blank = (BODY *&) ((a3dp_BODY *) input_blank)->base_obj._acis_obj;

            if (input_boolopts)
            {
              BoolOptions *_boolopts = ((a3dp_BoolOptions *) input_boolopts)->_acis_obj;
              result = api_intersect(_tool, _blank, _boolopts);
            }
            else
            {
              result = api_intersect(_tool, _blank);
            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Boolean operations automatically delete tool bodies, but for python, we need to set reference to NULL too
    __make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_subtract(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL, *input_boolopts = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      (char *) "boolopts",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|O", kwlist, &input_tool, &input_blank, &input_boolopts))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  if (input_boolopts != NULL)
  {
    if (!_PyCheck_BoolOptions(input_boolopts))
    {
      PyErr_SetString(PyExc_TypeError, "boolopts must be a BoolOptions object");
      return NULL;
    }
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tool = (BODY *&) ((a3dp_BODY *) input_tool)->base_obj._acis_obj;
            BODY * &_blank = (BODY *&) ((a3dp_BODY *) input_blank)->base_obj._acis_obj;

            if (input_boolopts)
            {
              BoolOptions *_boolopts = ((a3dp_BoolOptions *) input_boolopts)->_acis_obj;
              result = api_subtract(_tool, _blank, _boolopts);
            }
            else
            {
              result = api_subtract(_tool, _blank);
            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Boolean operations automatically delete tool bodies, but for python, we need to set reference to NULL too
    __make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_imprint(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL, *input_boolopts = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      (char *) "boolopts",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO|O", kwlist, &input_tool, &input_blank, &input_boolopts))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  if (input_boolopts != NULL)
  {
    if (!_PyCheck_BoolOptions(input_boolopts))
    {
      PyErr_SetString(PyExc_TypeError, "boolopts must be a BoolOptions object");
      return NULL;
    }
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tool = (BODY *&) ((a3dp_BODY *) input_tool)->base_obj._acis_obj;
            BODY * &_blank = (BODY *&) ((a3dp_BODY *) input_blank)->base_obj._acis_obj;

            if (input_boolopts)
            {
              BoolOptions *_boolopts = ((a3dp_BoolOptions *) input_boolopts)->_acis_obj;
              result = api_imprint(_tool, _blank, _boolopts);
            }
            else
            {
              result = api_imprint(_tool, _blank);
            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Boolean operations automatically delete tool bodies, but for python, we need to set reference to NULL too
    __make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_boolean_chop_body(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL;
  PyObject *input_outside = NULL, *input_leftovers = NULL, *input_result_body = NULL;
  PyObject *input_boolopts = NULL;
  int input_nonreg, input_ndbool_keep;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      (char *) "nonreg",
      (char *) "outside",
      (char *) "leftovers",
      (char *) "result_body",
      (char *) "ndbool_keep",
      (char *) "boolopts",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOiOOiO|O", kwlist,
                                   &input_tool, &input_blank, &input_nonreg, &input_outside, &input_leftovers, &input_ndbool_keep,
                                   &input_result_body, &input_boolopts))
    return NULL;

  // Type checks
  if (!_PyCheck_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_outside))
  {
    PyErr_SetString(PyExc_TypeError, "Outisde must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_leftovers))
  {
    PyErr_SetString(PyExc_TypeError, "Leftovers must be a BODY object");
    return NULL;
  }

  if (!_PyCheck_BODY(input_result_body))
  {
    PyErr_SetString(PyExc_TypeError, "Result body must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY * &_tool = (BODY *&) ((a3dp_BODY *) input_tool)->base_obj._acis_obj;
            BODY * &_blank = (BODY *&) ((a3dp_BODY *) input_blank)->base_obj._acis_obj;
            BODY * &_outside = (BODY *&) ((a3dp_BODY *) input_outside)->base_obj._acis_obj;
            BODY * &_leftovers = (BODY *&) ((a3dp_BODY *) input_leftovers)->base_obj._acis_obj;
            BODY * &_result_body = (BODY *&) ((a3dp_BODY *) input_result_body)->base_obj._acis_obj;
            NDBOOL_KEEP _ndbool_keep = NDBOOL_KEEP(input_ndbool_keep);
            logical _nonreg = (input_nonreg == 0) ? FALSE : TRUE;

            if (input_boolopts != NULL)
            {
              if (!_PyCheck_NDBOOL_KEEP(input_boolopts))
              {
                PyErr_SetString(PyExc_TypeError, "boolopts variable must be a BoolOptions object");
                return NULL;
              }

              BoolOptions *&_boolopts = (BoolOptions *&) ((a3dp_BoolOptions *) input_boolopts)->_acis_obj;

              result = api_boolean_chop_body(_tool, _blank, _nonreg, _outside, _leftovers, _ndbool_keep, _result_body, _boolopts);
            }
            else
            {
              result = api_boolean_chop_body(_tool, _blank, _nonreg, _outside, _leftovers, _ndbool_keep, _result_body);
            }

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_save_entity_list(PyObject *self, PyObject *args, PyObject *kwargs)
{
  // According to the documentation, Python 3 doesn't do good with FILE* objects, so we take "file name" as an input
  const char *input_filename = NULL;
  int input_savemode;
  PyObject *input_entitylist = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "file_name",
      (char *) "text_mode",
      (char *) "entity_list_save",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "siO", kwlist, &input_filename, &input_savemode, &input_entitylist))
    return NULL;

  // Check if the input is an ENTITY_LIST
  if (!_PyCheck_ENTITY_LIST(input_entitylist))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  // Using the file name input as a string, create a file handle
  FILE *_file_handle = fopen(input_filename, "w");

  // Check if the file has been opened correctly
  if (_file_handle == NULL)
  {
    PyErr_SetString(PyExc_IOError, "Cannot open file for writing!");
    return NULL;
  }

  // Set file writing mode
  logical _text_mode = (input_savemode == 0) ? FALSE : TRUE;

  API_NOP_BEGIN

            // Convert PyObject to ENTITY_LIST
            ENTITY_LIST *_save_list = ((a3dp_ENTITY_LIST *) input_entitylist)->_acis_obj;


            // Call ACIS API and check outcome
            result = api_save_entity_list(_file_handle, _text_mode, *_save_list);

  API_NOP_END

  // Don't forget to close the file handle
  fclose(_file_handle);

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_restore_entity_list(PyObject *self, PyObject *args, PyObject *kwargs)
{
  // According to the documentation, Python 3 doesn't do good with FILE* objects, so we take "file name" as an input
  const char *input_filename = NULL;
  int input_savemode;
  PyObject *input_entitylist = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "file_name",
      (char *) "text_mode",
      (char *) "entities",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "siO", kwlist, &input_filename, &input_savemode, &input_entitylist))
    return NULL;

  // Check if the input is an ENTITY_LIST
  if (!_PyCheck_ENTITY_LIST(input_entitylist))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  // Using the file name input as a string, create a file handle
  FILE *_file_handle = fopen(input_filename, "r");

  // Check if the file has been opened correctly
  if (_file_handle == NULL)
  {
    PyErr_SetString(PyExc_IOError, "Cannot open file for writing!");
    return NULL;
  }

  // Set file writing mode
  logical _text_mode = (input_savemode == 0) ? FALSE : TRUE;

  API_NOP_BEGIN

            // Convert PyObject to ENTITY_LIST
            ENTITY_LIST *_save_list = ((a3dp_ENTITY_LIST *) input_entitylist)->_acis_obj;


            // Call ACIS API and check outcome
            result = api_restore_entity_list(_file_handle, _text_mode, *_save_list);

  API_NOP_END

  // Don't forget to close the file handle
  fclose(_file_handle);

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_set_file_info(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_product_id = 0;
  int input_units = 0;
  PyObject *input_info = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "info",
      (char *) "product_id",
      (char *) "units",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|ii", kwlist, &input_info, &input_product_id, &input_units))
    return NULL;

  // Check if we have a FileInfo object
  if (!_PyCheck_FileInfo(input_info))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  // Set up the value of mask
  bool _product_id = input_product_id != 0;
  bool _units = input_units != 0;

  unsigned long _mask;
  if (_product_id && !_units)
  {
    _mask = FileIdent;
  }
  else if (!_product_id && _units)
  {
    _mask = FileUnits;
  }
  else
  {
    _mask = FileUnits | FileIdent;
  }

  API_BEGIN

            // Convert PyObject to FileInfo
            FileInfo *_info = ((a3dp_FileInfo *) input_info)->_acis_obj;

            result = api_set_file_info(_mask, *_info);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_get_file_info(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_info = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "info",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_info))
    return NULL;

  // Check if we have a FileInfo object
  if (_PyCheck_FileInfo(input_info))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to FileInfo
            FileInfo *_info = ((a3dp_FileInfo *) input_info)->_acis_obj;

            result = api_get_file_info(*_info);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_save_version(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_major_version, input_minor_version;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "major_version",
      (char *) "minor_version",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii", kwlist, &input_major_version, &input_minor_version))
    return NULL;

  API_BEGIN

            result = api_save_version(input_major_version, input_minor_version);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

/**
 * Sweeping API Interface Functions
 */

PyObject *
a3dp_api_make_sweep_path(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pts = NULL, *input_path = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "pts",
      (char *) "path",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pts, &input_path))
    return NULL;

  // Type checks for ACIS objects
  if (!_PyCheck_EDGE(input_path))
  {
    PyErr_SetString(PyExc_TypeError, "Second argument (path) must be an EDGE object");
    return NULL;
  }

  // The first object must be a python sequence containing SPAposition objects
  PyObject *seq = PySequence_Fast(input_pts, "First argument (pts) must be a sequence of SPAposition objects, such as a list or a tuple");

  Py_ssize_t position_vector_size = PySequence_Fast_GET_SIZE(seq);
  if (position_vector_size <= 0)
  {
    PyErr_SetString(PyExc_ValueError, "Sequence cannot be empty");
    Py_DECREF(seq);
    return NULL;
  }

  // It seems unnecessary to implement a SPAposition container as python itself provides a handful of containers for every purpose
  SPAposition_vector _pts;

  for (Py_ssize_t i = 0; i < position_vector_size; i++)
  {
    PyObject *pt_temp;
    pt_temp = PySequence_Fast_GET_ITEM(seq, i);
    if (!_PyCheck_SPAposition(pt_temp))
    {
      PyErr_SetString(PyExc_TypeError, "Sequence must contain SPAposition objects");
      Py_DECREF(seq);
      return NULL;
    }
    _pts.push_back(*((a3dp_SPAposition *) pt_temp)->_acis_obj);
  }

  API_BEGIN

            EDGE * &_path = (EDGE *&) ((a3dp_EDGE *) input_path)->base_obj._acis_obj;

            // Don't use make_sweep_path_options for now
            result = api_make_sweep_path(_pts, _path);

  API_END

  // PySequence_Fast returns a new reference
  Py_DECREF(seq);

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Clear SPAposition container
    _pts.clear();
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_sweep_with_options(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_arg1 = NULL, *input_arg2 = NULL, *input_arg3 = NULL, *input_arg4 = NULL, *input_arg5 = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "arg1",
      (char *) "arg2",
      (char *) "arg3",
      (char *) "arg4",
      (char *) "arg5",
      NULL
    };

  // Try to parse input arguments and/or keywords (hold sweep_options for now)
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOOO|O", kwlist, &input_arg1, &input_arg2, &input_arg3, &input_arg4, &input_arg5))
    return NULL;

  /*
   * IMPORTANT NOTE: This function wraps all 4 api_sweep_with_options overloads in one single Python function.
   * The reason is that Python doesn't allow overloading with same function names but different signatures.
   */

  // In all overloads, first argument is always an ENTITY object
  if (!_PyCheck_ENTITY(input_arg1))
  {
    PyErr_SetString(PyExc_TypeError, "First argument must be an ENTITY object");
    return NULL;
  }

  API_BEGIN

            ENTITY * &_ent = (ENTITY *&) ((a3dp_ENTITY *) input_arg1)->_acis_obj;

            // Check if we are using the sweep along the axis overload
            if (input_arg5 != NULL)
            {
              if (!_PyCheck_SPAposition(input_arg2))
              {
                PyErr_SetString(PyExc_TypeError, "Second argument must be a SPAposition object");
                return NULL;
              }

              if (!_PyCheck_SPAvector(input_arg3))
              {
                PyErr_SetString(PyExc_TypeError, "Third argument must be a SPAvector object");
                return NULL;
              }

              if (!_PyCheck_sweep_options(input_arg4))
              {
                PyErr_SetString(PyExc_TypeError, "Fourth argument must be a sweep_options object");
                return NULL;
              }

              if (!_PyCheck_BODY(input_arg5))
              {
                PyErr_SetString(PyExc_TypeError, "Fifth argument must be a BODY object");
                return NULL;
              }

              SPAposition *&_root = (SPAposition *&) ((a3dp_SPAposition *) input_arg2)->_acis_obj;
              SPAvector *&_axis = (SPAvector *&) ((a3dp_SPAvector *) input_arg3)->_acis_obj;
              sweep_options *&_opts = (sweep_options *&) ((a3dp_sweep_options *) input_arg4)->_acis_obj;
              BODY * &_new_body = (BODY *&) ((a3dp_BODY *) input_arg5)->base_obj._acis_obj;

              // Call ACIS Sweeping API
              result = api_sweep_with_options(_ent, *_root, *_axis, _opts, _new_body);

            }
            else
            {
              // We must be using the other overloads, then the 3rd argument must be a sweep_options object
              if (!_PyCheck_sweep_options(input_arg3))
              {
                PyErr_SetString(PyExc_TypeError, "Third argument must be a sweep_options object");
                return NULL;
              }

              sweep_options *&_opts = (sweep_options *&) ((a3dp_sweep_options *) input_arg3)->_acis_obj;

              // and the 4th argument must be a BODY object
              if (!_PyCheck_BODY(input_arg4))
              {
                PyErr_SetString(PyExc_TypeError, "Fourth argument must be a BODY object");
                return NULL;
              }

              BODY * &_new_body = (BODY *&) ((a3dp_BODY *) input_arg4)->base_obj._acis_obj;

              // Check for sweeping along a given edge or a wire overload
              if (_PyCheck_ENTITY(input_arg2))
              {
                ENTITY * &_path = (ENTITY *&) ((a3dp_ENTITY *) input_arg2)->_acis_obj;

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, _path, _opts, _new_body);
              }
              else if (PyFloat_Check(input_arg2))
              {
                // We must be using sweeping along a specified distance overload
                double _distance = PyFloat_AsDouble(input_arg2);

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, _distance, _opts, _new_body);
              }
              else if (_PyCheck_SPAvector(input_arg2))
              {
                // We must be using sweeping along a specified vector overload
                SPAvector *&_vec = (SPAvector *&) ((a3dp_SPAvector *) input_arg2)->_acis_obj;

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, *_vec, _opts, _new_body);
              }
              else
              {
                PyErr_SetString(PyExc_TypeError, "Second argument must be an ENTITY, float or SPAvector object");
                return NULL;
              }

            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

PyObject *
a3dp_api_get_faces(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL, *input_ent_list = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "ent",
      (char *) "face_list",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_ent, &input_ent_list))
    return NULL;

  if (!_PyCheck_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  if (!_PyCheck_ENTITY_LIST(input_ent_list))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  API_BEGIN

            // Get the ACIS objects from the user input
            ENTITY * &_ent = ((a3dp_ENTITY *) input_ent)->_acis_obj;
            ENTITY_LIST *&_face_list = ((a3dp_ENTITY_LIST *) input_ent_list)->_acis_obj;

            // Call ACIS function
            result = api_get_faces(_ent, *_face_list);

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }

}

PyObject *
a3dp_api_get_edges(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL, *input_ent_list = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "ent",
      (char *) "edge_list",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_ent, &input_ent_list))
    return NULL;

  if (!_PyCheck_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  if (!_PyCheck_ENTITY_LIST(input_ent_list))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  API_BEGIN

            // Get the ACIS objects from the user input
            ENTITY * &_ent = ((a3dp_ENTITY *) input_ent)->_acis_obj;
            ENTITY_LIST *&_edge_list = ((a3dp_ENTITY_LIST *) input_ent_list)->_acis_obj;

            // Call ACIS function
            result = api_get_edges(_ent, *_edge_list);

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }

}

PyObject *
a3dp_api_logging(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_on_off;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "on_off",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i", kwlist, &input_on_off))
    return NULL;

  logical _on_off = (input_on_off == 0) ? FALSE : TRUE;

  API_BEGIN

            result = api_logging(_on_off);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_body_to_1d(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_body = NULL, *input_ref_faces = NULL;
  int input_fix_normals;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "body",
      (char *) "fix_normals",
      (char *) "ref_faces",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi|O", kwlist, &input_body, &input_fix_normals, &input_ref_faces))
    return NULL;

  if (!_PyCheck_BODY(input_body))
  {
    PyErr_SetString(PyExc_TypeError, "Input body must be a BODY object");
    return NULL;
  }

  BODY * &_body = (BODY *&) ((a3dp_BODY *) input_body)->base_obj._acis_obj;
  logical _fix_normals = (input_fix_normals == 0) ? FALSE : TRUE;
  ENTITY_LIST _ref_faces = *(ENTITY_LIST *) NULL_REF;

  if (input_ref_faces != NULL)
  {
    if (!_PyCheck_BODY(input_body))
    {
      PyErr_SetString(PyExc_TypeError, "Input body must be a BODY object");
      return NULL;
    }

    _ref_faces = *((a3dp_ENTITY_LIST *) input_ref_faces)->_acis_obj;
  }

  API_BEGIN

            result = api_body_to_1d(_body, _fix_normals, _ref_faces);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_body_to_2d(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_body = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "body",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_body))
    return NULL;

  if (!_PyCheck_BODY(input_body))
  {
    PyErr_SetString(PyExc_TypeError, "Input body must be a BODY object");
    return NULL;
  }

  BODY * &_body = (BODY *&) ((a3dp_BODY *) input_body)->base_obj._acis_obj;

  API_BEGIN

            result = api_body_to_2d(_body);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

PyObject *
a3dp_api_get_entity_id(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "ent",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_ent))
    return NULL;

  if (!_PyCheck_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY object");
    return NULL;
  }

  ENTITY * _ent = ((a3dp_ENTITY *) input_ent)->_acis_obj;
  // tag_id_type is a typedef'd int
  tag_id_type _id;

  API_BEGIN

            result = api_get_entity_id(_ent, _id);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    return PyLong_FromLong((long) _id);
}
