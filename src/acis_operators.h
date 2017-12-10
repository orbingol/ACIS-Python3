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

#ifndef A3DPY_OPERATORS_H
#define A3DPY_OPERATORS_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "acis_classes.h"

#ifdef __cplusplus
extern "C" {
#endif

PyObject *a3dp_distance_to_point_squared(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_distance_to_point(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_get_resnor(PyObject *self);
PyObject *a3dp_get_resmch(PyObject *self);
PyObject *a3dp_get_resfit(PyObject *self);
PyObject *a3dp_get_resabs(PyObject *self);
PyObject *a3dp_radians_to_degrees(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_degrees_to_radians(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_biparallel(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_are_perpendicular(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_are_parallel(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_antiparallel(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_angle_between(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_translate_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_shear_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_scale_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_rotate_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_reflect_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_make_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_coordinate_transf(PyObject *self, PyObject *args, PyObject *kwargs);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_OPERATORS_H
