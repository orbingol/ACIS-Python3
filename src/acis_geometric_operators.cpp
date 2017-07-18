#include "acis_geometric_operators.h"


static PyObject *
ACIS_GeometricOperators_method_translate_transf(PyObject *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef
  ACIS_GeometricOperators_methods[] =
  {
    { "translate_transf", (PyCFunction) ACIS_GeometricOperators_method_translate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a translation by a given vector" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_documentation = "Contains 3D ACIS Modeler geometric operators";

static struct PyModuleDef
  ACIS_GeometricOperators_module =
  {
    PyModuleDef_HEAD_INIT,
    "GeometricOperators", // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    ACIS_GeometricOperators_methods
  };

PyMODINIT_FUNC
PyInit_GeometricOperators(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_GeometricOperators_module);
  if (m == NULL)
    return NULL;

  return m;
}
