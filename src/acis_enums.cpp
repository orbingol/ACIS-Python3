#include "acis_enums.h"

/**
 * NDBOOL_KEEP enum
 */
PyTypeObject
  a3dp_type_NDBOOL_KEEP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.NDBOOL_KEEP",             /* tp_name */
    sizeof(a3dp_NDBOOL_KEEP), /* tp_basicsize */
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

PyObject *_PyNew_NDBOOL_KEEP()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_NDBOOL_KEEP, NULL);
}

bool _PyCheck_NDBOOL_KEEP(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_NDBOOL_KEEP;
}


/**
 * sweep_bool_type enum
 */

PyTypeObject
  a3dp_type_sweep_bool_type =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.sweep_bool_type",             /* tp_name */
    sizeof(a3dp_sweep_bool_type), /* tp_basicsize */
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
    "Sweep to body boolean operation type",           /* tp_doc */
  };

PyObject *_PyNew_sweep_bool_type()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_sweep_bool_type, NULL);
}

bool _PyCheck_sweep_bool_type(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_sweep_bool_type;
}
