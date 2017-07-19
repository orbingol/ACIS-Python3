#include "acis_query.h"


static PyObject *
ACIS_Query_method_get_owner_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "entity",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_ent))
    return NULL;

  if (!_ACIS_check_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  // Get the ACIS object from the user input
  ENTITY *&_ent = ((ACIS_Entity_ENTITY *) input_ent)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = get_owner_transf(_ent);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _ACIS_new_SPAtransf();
  *((ACIS_GeometricAtoms_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

static PyObject *
ACIS_api_get_faces(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL, *input_ent_list = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "ent",
      (char *) "face_list",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_ent, &input_ent_list))
    return NULL;

  if (!_ACIS_check_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  if (!_ACIS_check_ENTITY_LIST(input_ent_list))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  API_BEGIN

            // Get the ACIS objects from the user input
            ENTITY *&_ent = ((ACIS_Entity_ENTITY *) input_ent)->_acis_obj;
            ENTITY_LIST *&_face_list = ((ACIS_Lists_ENTITY_LIST *) input_ent_list)->_acis_obj;

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

static PyObject *
ACIS_api_get_edges(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL, *input_ent_list = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "ent",
      (char *) "edge_list",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_ent, &input_ent_list))
    return NULL;

  if (!_ACIS_check_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  if (!_ACIS_check_ENTITY_LIST(input_ent_list))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  API_BEGIN

            // Get the ACIS objects from the user input
            ENTITY *&_ent = ((ACIS_Entity_ENTITY *) input_ent)->_acis_obj;
            ENTITY_LIST *&_edge_list = ((ACIS_Lists_ENTITY_LIST *) input_ent_list)->_acis_obj;

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

static PyMethodDef
  module_methods[] =
  {
    { "get_owner_transf", (PyCFunction) ACIS_Query_method_get_owner_transf, METH_VARARGS | METH_KEYWORDS, "Gets a copy of the SPAtransf from the owner of an ENTITY" },
    { "api_get_faces", (PyCFunction) ACIS_api_get_faces, METH_VARARGS | METH_KEYWORDS, "Gets all faces related to an entity" },
    { "api_get_edges", (PyCFunction) ACIS_api_get_edges, METH_VARARGS | METH_KEYWORDS, "Gets all the edges related to an entity" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "Query";
const char *module_documentation = "Contains 3D Modeler ACIS geometric and topological queries";

static struct PyModuleDef
  ACIS_Query_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_Query(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_Query_module);
  if (m == NULL)
    return NULL;

  return m;
}
