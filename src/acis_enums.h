/**
 *
 * Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler
 *
 * ACIS and SAT are registered trademarks of Spatial Corporation.
 *
 * The Python module is developed by Onur R. Bingol and released under MIT license.
 * Please see the LICENSE file for details.
 *
 */

#ifndef A3DPY_ENUMS_H
#define A3DPY_ENUMS_H

#include <Python.h>
#include <structmember.h>

#ifdef __cplusplus
extern "C" {
#endif

// Define NDBOOL_KEEP enum
typedef struct {
    PyObject_HEAD
} a3dp_NDBOOL_KEEP;

/**
 * NDBOOL_KEEP enum
 */

static PyTypeObject
  a3dp_type_NDBOOLKEEP =
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

PyObject *_PyNew_NDBOOL_KEEP();
bool _PyCheck_NDBOOL_KEEP(PyObject *ob);

// Define sweep_bool_type enum
typedef struct {
    PyObject_HEAD
} a3dp_sweep_bool_type;

/**
 * sweep_bool_type enum
 */

static PyTypeObject
  a3dp_type_sweepbooltype =
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

PyObject *_PyNew_sweep_bool_type();
bool _PyCheck_sweep_bool_type(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_ENUMS_H
