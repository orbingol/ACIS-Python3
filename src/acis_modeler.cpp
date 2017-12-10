#include "acis_modeler.h"


bool disabled_acis_freelisting = false;

static PyObject *
ACIS_api_start_modeller(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_n = 0;
  int input_freelisting = 1;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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

static PyObject *
ACIS_api_stop_modeller(PyObject *self)
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

static PyObject *
ACIS_is_modeler_started(PyObject *self)
{
  // Initialize variables
  logical check_modeler;

  // Call ACIS API
  check_modeler = is_modeler_started();

  // Return Python value
  if (check_modeler)
    Py_RETURN_TRUE;
  else
    Py_RETURN_FALSE;
}

static PyObject *
ACIS_api_set_dbl_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  double input_value;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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

static PyObject *
ACIS_api_set_int_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  int input_value;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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

static PyObject *
ACIS_api_set_str_option(PyObject *self, PyObject *args, PyObject *kwargs)
{
  const char *input_name = NULL;
  const char *input_value = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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

static PyObject *
ACIS_api_solid_block(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pt1 = NULL, *input_pt2 = NULL, *input_block = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_SPAposition(input_pt1))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a SPAposition object");
    return NULL;
  }

  if (!_ACIS_check_SPAposition(input_pt2))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a SPAposition object");
    return NULL;
  }

  if (!_ACIS_check_BODY(input_block))
  {
    PyErr_SetString(PyExc_TypeError, "The third argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            SPAposition *_pt1 = ((ACIS_GeometricAtoms_SPAposition *) input_pt1)->_acis_obj;
            SPAposition *_pt2 = ((ACIS_GeometricAtoms_SPAposition *) input_pt2)->_acis_obj;
            BODY *&_block = (BODY *&) ((ACIS_Entity_BODY *) input_block)->base_obj._acis_obj;

            // Call ACIS API
            result = api_solid_block(*_pt1, *_pt2, _block);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_cuboid(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_x, input_y, input_z;
  PyObject *input_body = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_BODY(input_body))
  {
    PyErr_SetString(PyExc_TypeError, "The fourth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_body = (BODY *&) ((ACIS_Entity_BODY *) input_body)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_cuboid(input_x, input_y, input_z, _body);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_frustum(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2, input_top;
  PyObject *input_frust = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_BODY(input_frust))
  {
    PyErr_SetString(PyExc_TypeError, "The fifth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_frust = (BODY *&) ((ACIS_Entity_BODY *) input_frust)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_frustum(input_height, input_radius1, input_radius2, input_top, _frust);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_prism(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2;
  int input_nsides;
  PyObject *input_prism = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_BODY(input_prism))
  {
    PyErr_SetString(PyExc_TypeError, "The fifth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_prism = (BODY *&) ((ACIS_Entity_BODY *) input_prism)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_prism(input_height, input_radius1, input_radius2, input_nsides, _prism);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_pyramid(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_height, input_radius1, input_radius2, input_top;
  int input_nsides;
  PyObject *input_pyramid = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_BODY(input_pyramid))
  {
    PyErr_SetString(PyExc_TypeError, "The sixth argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_pyramid = (BODY *&) ((ACIS_Entity_BODY *) input_pyramid)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_pyramid(input_height, input_radius1, input_radius2, input_top, input_nsides, _pyramid);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_sphere(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_radius;
  PyObject *input_sph = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "radius",
      (char *) "sph",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddddiO", kwlist, &input_radius, &input_sph))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_sph))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_sph = (BODY *&) ((ACIS_Entity_BODY *) input_sph)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_sphere(input_radius, _sph);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_make_torus(PyObject *self, PyObject *args, PyObject *kwargs)
{
  double input_major_r, input_minor_r;
  PyObject *input_tor = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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
  if (!_ACIS_check_BODY(input_tor))
  {
    PyErr_SetString(PyExc_TypeError, "The third argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            BODY *&_tor = (BODY *&) ((ACIS_Entity_BODY *) input_tor)->base_obj._acis_obj;

            // Call ACIS API
            result = api_make_torus(input_major_r, input_minor_r, _tor);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_apply_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_entity = NULL, *input_trans = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "entity",
      (char *) "trans",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_entity, &input_trans))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_entity))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a BODY object");
    return NULL;
  }

  if (!_ACIS_check_SPAtransf(input_trans))
  {
    PyErr_SetString(PyExc_TypeError, "The second argument must be a SPAtransf object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            ENTITY *&_entity = ((ACIS_Entity_BODY *) input_entity)->base_obj._acis_obj;
            SPAtransf *&_trans = ((ACIS_GeometricAtoms_SPAtransf *) input_trans)->_acis_obj;

            // Call ACIS API
            result = api_apply_transf(_entity, *_trans);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_remove_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_entity = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "entity",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_entity))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_entity))
  {
    PyErr_SetString(PyExc_TypeError, "The first argument must be a BODY object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to ACIS objects
            ENTITY *&_entity = ((ACIS_Entity_BODY *) input_entity)->base_obj._acis_obj;

            // Call ACIS API
            result = api_remove_transf(_entity);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_sheet_from_ff(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_faces = NULL, *input_body = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
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

            FACE *&_face = (FACE *&) ((ACIS_Entity_FACE *) faceobj)->base_obj._acis_obj;

            FACE *_faces[1];
            _faces[0] = _face;

            BODY *&_body = (BODY *&) ((ACIS_Entity_BODY *) input_body)->base_obj._acis_obj;

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



static PyMethodDef
  module_methods[] =
  {
    { "api_start_modeller", (PyCFunction) ACIS_api_start_modeller, METH_VARARGS | METH_KEYWORDS, "Starts the 3D ACIS Modeler" },
    { "api_stop_modeller", (PyCFunction) ACIS_api_stop_modeller, METH_NOARGS, "Stops the 3D ACIS Modeler" },
    { "is_modeler_started", (PyCFunction) ACIS_is_modeler_started, METH_NOARGS, "Checks if the 3D ACIS Modeler started" },
    { "api_start_modeler", (PyCFunction) ACIS_api_start_modeller, METH_VARARGS | METH_KEYWORDS, "Alternative way to call api_start_modeller()" },
    { "api_stop_modeler", (PyCFunction) ACIS_api_stop_modeller, METH_NOARGS, "Alternative way to call api_stop_modeller()" },
    { "api_set_dbl_option", (PyCFunction) ACIS_api_set_dbl_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given double" },
    { "api_set_int_option", (PyCFunction) ACIS_api_set_int_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given integer" },
    { "api_set_str_option", (PyCFunction) ACIS_api_set_str_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given string" },
    { "api_solid_block", (PyCFunction) ACIS_api_solid_block, METH_VARARGS | METH_KEYWORDS, "Creates a solid block given two positions on a diagonal of the block" },
    { "api_make_cuboid", (PyCFunction) ACIS_api_make_cuboid, METH_VARARGS | METH_KEYWORDS, "Creates cuboid of given width (x), depth (y) and height (z)" },
    { "api_make_frustum", (PyCFunction) ACIS_api_make_frustum, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical cone or cylinder of given height and radii" },
    { "api_make_prism", (PyCFunction) ACIS_api_make_prism, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical prism of given height, radii, and number of sides" },
    { "api_make_pyramid", (PyCFunction) ACIS_api_make_pyramid, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical pyramid of given height, radii, and number of sides" },
    { "api_make_sphere", (PyCFunction) ACIS_api_make_sphere, METH_VARARGS | METH_KEYWORDS, "Creates a sphere of given radius, centered at the origin" },
    { "api_make_torus", (PyCFunction) ACIS_api_make_torus, METH_VARARGS | METH_KEYWORDS, "Creates a torus of given major and minor radii centered at the origin" },
    { "api_apply_transf", (PyCFunction) ACIS_api_apply_transf, METH_VARARGS | METH_KEYWORDS, "Changes the transform entity attached to a body" },
    { "api_remove_transf", (PyCFunction) ACIS_api_remove_transf, METH_VARARGS | METH_KEYWORDS, "Removes (discards) the transformation of a body" },
    { "api_sheet_from_ff", (PyCFunction) ACIS_api_sheet_from_ff, METH_VARARGS | METH_KEYWORDS, "Creates a sheet body as a copy of a face" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "Modeler";
const char *module_documentation = "3D ACIS Modeler main modeling component";

static struct PyModuleDef
  ACIS_Modeler_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_Modeler(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_Modeler_module);
  if (m == NULL)
    return NULL;

  return m;
}
