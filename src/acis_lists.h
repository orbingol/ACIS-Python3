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

#ifndef ACIS_LISTS_H
#define ACIS_LISTS_H

#include <Python.h>
#include <structmember.h>

#include <lists.hxx>

#include "acis_entity.h"

#include "acis_lists_export.h"


#ifdef __cplusplus
extern "C" {
#endif

// Define ENTITY_LIST
typedef struct
{
  PyObject_HEAD
  ENTITY_LIST *_acis_obj;
} ACIS_Lists_ENTITY_LIST;

PyObject ACIS_LISTS_EXPORT *_ACIS_new_ENTITY_LIST();

bool ACIS_LISTS_EXPORT _ACIS_check_ENTITY_LIST(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_LISTS_H
