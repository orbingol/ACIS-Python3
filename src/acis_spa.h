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

#ifndef A3D_SPA_H
#define A3D_SPA_H

#include <Python.h>

#include "acis_includes.h"

#ifdef __cplusplus
extern "C" {
#endif

PyObject *a3dp_spa_unlock_products(PyObject *self, PyObject *arg);

#ifdef __cplusplus
}
#endif

#endif // !A3D_SPA_H
