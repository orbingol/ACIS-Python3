#include "acis_api2.h"


PyObject *
a3dp_is_modeler_started(PyObject *self)
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

PyObject *
a3dp_get_owner_transf(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_ent = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "entity",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_ent))
    return NULL;

  if (!_PyCheck_ENTITY(input_ent))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY object");
    return NULL;
  }

  // Get the ACIS object from the user input
  ENTITY *&_ent = ((a3dp_ENTITY *) input_ent)->_acis_obj;

  // Execute ACIS function
  SPAtransf retval = get_owner_transf(_ent);

  // Generate a new SPAtransf python object and set its ACIS object value
  PyObject *retobj = _PyNew_SPAtransf();
  *((a3dp_SPAtransf *) retobj)->_acis_obj = retval;

  // Return SPAtransf python object
  return retobj;
}

PyObject *
a3dp_get_face_box(PyObject *self, PyObject *args, PyObject *kwargs)
{
  return NULL;
}
