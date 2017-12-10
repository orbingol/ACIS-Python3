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

#ifndef A3DPY_UTILITIES_H
#define A3DPY_UTILITIES_H

#include <Python.h>

#include "acis_includes.h"

#ifdef __cplusplus
extern "C" {
#endif

bool check_outcome(outcome &_retval);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_UTILITIES_H
