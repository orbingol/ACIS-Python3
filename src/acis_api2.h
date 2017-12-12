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

#ifndef A3DPY_API2_H
#define A3DPY_API2_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "acis_entity.h"
#include "acis_operators.h"
#include "acis_classes.h"
#include "acis_enums.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

PyObject *a3dp_is_modeler_started(PyObject *self);
PyObject *a3dp_spa_unlock_products(PyObject *self, PyObject *arg);
PyObject *a3dp_get_owner_transf(PyObject *self, PyObject *args, PyObject *kwargs);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_API2_H
