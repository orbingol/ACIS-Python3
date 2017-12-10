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


// Define NDBOOL_KEEP enum
typedef struct {
    PyObject_HEAD
} a3dp_NDBOOL_KEEP;

// Define sweep_bool_type enum
typedef struct {
    PyObject_HEAD
} a3dp_sweep_bool_type;

extern PyTypeObject a3dp_type_NDBOOL_KEEP;
extern PyTypeObject a3dp_type_sweep_bool_type;

#ifdef __cplusplus
extern "C" {
#endif

PyObject *_PyNew_NDBOOL_KEEP();
bool _PyCheck_NDBOOL_KEEP(PyObject *ob);

PyObject *_PyNew_sweep_bool_type();
bool _PyCheck_sweep_bool_type(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_ENUMS_H
