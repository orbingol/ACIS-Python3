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

#ifndef ACIS_UTILITIES_H
#define ACIS_UTILITIES_H

#include <Python.h>

#include <api.hxx>
#include <err_info.hxx>

bool check_outcome(outcome &_retval);

#endif //ACIS_UTILITIES_H
