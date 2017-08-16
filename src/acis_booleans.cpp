#include "acis_booleans.h"


/**
 * NDBOOL_KEEP enum
 */

static PyTypeObject
  ACIS_Booleans_type_NDBOOL_KEEP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.NDBOOL_KEEP",             /* tp_name */
    sizeof(ACIS_Booleans_NDBOOL_KEEP), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
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
    "For a non-destructive Boolean operation, this optional flag may be used to specify the preservation of either or both input bodies",           /* tp_doc */
  };


/**
 * Booleans API Interface Functions
 */

static PyObject *
ACIS_api_unite(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_tool, &input_blank))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_ACIS_check_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  API_BEGIN

  // Convert PyObject to ACIS objects
  BODY *&_tool = (BODY *&) ((ACIS_Entity_BODY *) input_tool)->base_obj._acis_obj;
  BODY *&_blank = (BODY *&) ((ACIS_Entity_BODY *) input_blank)->base_obj._acis_obj;

  // Call ACIS API
  result = api_unite(_tool, _blank);

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
    _ACIS_make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_api_intersect(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_tool, &input_blank))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_ACIS_check_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  API_BEGIN

  // Convert PyObject to ACIS objects
  BODY *&_tool = (BODY *&) ((ACIS_Entity_BODY *) input_tool)->base_obj._acis_obj;
  BODY *&_blank = (BODY *&) ((ACIS_Entity_BODY *) input_blank)->base_obj._acis_obj;

  // Call ACIS API
  result = api_intersect(_tool, _blank);

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
    _ACIS_make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_api_subtract(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_tool, &input_blank))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_ACIS_check_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  API_BEGIN

  // Convert PyObject to ACIS objects
  BODY *&_tool = (BODY *&) ((ACIS_Entity_BODY *) input_tool)->base_obj._acis_obj;
  BODY *&_blank = (BODY *&) ((ACIS_Entity_BODY *) input_blank)->base_obj._acis_obj;

  // Call ACIS API
  result = api_subtract(_tool, _blank);

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
    _ACIS_make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_api_imprint(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_tool = NULL, *input_blank = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "tool",
      (char *) "blank",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_tool, &input_blank))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_BODY(input_tool))
  {
    PyErr_SetString(PyExc_TypeError, "Tool must be a BODY object");
    return NULL;
  }

  if (!_ACIS_check_BODY(input_blank))
  {
    PyErr_SetString(PyExc_TypeError, "Blank must be a BODY object");
    return NULL;
  }

  API_BEGIN

  // Convert PyObject to ACIS objects
  BODY *&_tool = (BODY *&) ((ACIS_Entity_BODY *) input_tool)->base_obj._acis_obj;
  BODY *&_blank = (BODY *&) ((ACIS_Entity_BODY *) input_blank)->base_obj._acis_obj;

  // Call ACIS API
  result = api_imprint(_tool, _blank);

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
    _ACIS_make_null(input_tool);
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_api_boolean_chop_body(PyObject *self, PyObject *args, PyObject *kwargs)
{
  /* TO-DO: Implement api_boolean_chop_body */
  return NULL;
}

static PyMethodDef
  module_methods[] =
  {
    { "api_unite", (PyCFunction) ACIS_api_unite, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean unite operation" },
    { "api_intersect", (PyCFunction) ACIS_api_intersect, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean intersect operation on two bodies" },
    { "api_subtract", (PyCFunction) ACIS_api_subtract, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean subtract operation" },
    { "api_imprint", (PyCFunction) ACIS_api_imprint, METH_VARARGS | METH_KEYWORDS, "Intersects two bodies and imprints the intersection graph on both bodies" },
    { "api_boolean_chop_body", (PyCFunction) ACIS_api_boolean_chop_body, METH_VARARGS | METH_KEYWORDS, "Executes simultaneous Boolean intersect and subtract operations on two bodies" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "Booleans";
const char *module_documentation = "Contains 3D ACIS Modeler booleans API related classes and functions";

static struct PyModuleDef
  ACIS_Booleans_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_Booleans(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_Booleans_module);
  if (m == NULL)
    return NULL;

  // Create a dictionary object for NDBOOL_KEEP enum
  PyObject *_ndbk_dict;
  _ndbk_dict = PyDict_New();
  if (_ndbk_dict != NULL)
  {
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_NEITHER", PyLong_FromLong(0L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_TOOL", PyLong_FromLong(1L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_BLANK", PyLong_FromLong(2L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_BOTH", PyLong_FromLong(3L));
  }

  // sweep_bool_type
  ACIS_Booleans_type_NDBOOL_KEEP.tp_dict = _ndbk_dict;
  if (PyType_Ready(&ACIS_Booleans_type_NDBOOL_KEEP) < 0)
    return NULL;
  Py_INCREF(&ACIS_Booleans_type_NDBOOL_KEEP);
  PyModule_AddObject(m, "NDBOOL_KEEP", (PyObject *) &ACIS_Booleans_type_NDBOOL_KEEP);

  return m;
}

PyObject *_ACIS_new_NDBOOL_KEEP()
{
  return PyObject_CallObject((PyObject *) &ACIS_Booleans_type_NDBOOL_KEEP, NULL);
}

bool _ACIS_check_NDBOOL_KEEP(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Booleans_type_NDBOOL_KEEP;
}