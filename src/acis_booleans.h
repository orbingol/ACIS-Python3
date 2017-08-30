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

#ifndef ACIS_BOOLEANS_H
#define ACIS_BOOLEANS_H

#include <Python.h>
#include <structmember.h>

#include <boolapi.hxx>

#include "acis_entity.h"
#include "acis_geometric_atoms.h"
#include "utilities.h"

#include "acis_booleans_export.h"

// Define NDBOOL_KEEP enum
typedef struct {
  PyObject_HEAD
} ACIS_Booleans_NDBOOL_KEEP;

PyObject ACIS_BOOLEANS_EXPORT *_ACIS_new_NDBOOL_KEEP();

bool ACIS_BOOLEANS_EXPORT _ACIS_check_NDBOOL_KEEP(PyObject *ob);


#endif // !ACIS_BOOLEANS_H
