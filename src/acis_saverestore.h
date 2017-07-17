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

#ifndef ACIS_SAVERESTORE_H
#define ACIS_SAVERESTORE_H

#include <Python.h>
#include <structmember.h>

#include <kernapi.hxx>
#include <fileinfo.hxx>

#include "acis_lists.h"
#include "utilities.h"

#include "acis_saverestore_export.h"


#ifdef __cplusplus
extern "C" {
#endif

// Define FileInfo
typedef struct
{
  PyObject_HEAD
  FileInfo *_acis_obj;
} ACIS_SaveRestore_FileInfo;

bool ACIS_SAVERESTORE_EXPORT _ACIS_check_FileInfo(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_SAVERESTORE_H
