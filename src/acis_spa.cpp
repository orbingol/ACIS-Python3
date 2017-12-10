#include "acis_spa.h"


PyObject *
a3dp_spa_unlock_products(PyObject *self, PyObject *arg)
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
