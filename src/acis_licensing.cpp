#include <Python.h>

#include <base.hxx>
#include <license.hxx>
#include <spa_unlock_result.hxx>


static PyObject *
ACIS_spa_unlock_products(PyObject *self, PyObject *arg)
{
  // Check if the input is a string
  if (!PyUnicode_Check(arg))
  {
    PyErr_SetString(PyExc_ValueError, "Expecting a string");
    return NULL;
  }

  // Convert PyObject to C-style string
  const char *unlock_str = PyUnicode_AsUTF8(arg);

  // Call ACIS Licensing API
  spa_unlock_result out = spa_unlock_products(unlock_str);

  // If license is good, then return True. Otherwise, return the licensing error message
  if (SPA_UNLOCK_PASS == out.get_state())
    Py_RETURN_TRUE;
  else
    return PyUnicode_FromString(out.get_message_text());
}

static PyMethodDef
  ACIS_Licensing_methods[] =
  {
    { "spa_unlock_products", (PyCFunction) ACIS_spa_unlock_products, METH_O, "Unlock the 3D ACIS Modeler using the license key" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_documentation = "Contains 3D ACIS Modeler licensing API related functions and classes";

static struct PyModuleDef
  ACIS_Licensing_module =
  {
    PyModuleDef_HEAD_INIT,
    "Licensing", // name of module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    ACIS_Licensing_methods
  };

PyMODINIT_FUNC
PyInit_Licensing(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_Licensing_module);
  if (m == NULL)
    return NULL;

  return m;
}
