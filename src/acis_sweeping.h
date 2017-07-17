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

#ifndef ACIS_SWEEPING_H
#define ACIS_SWEEPING_H

#include <Python.h>
#include <structmember.h>

#include <sweepapi.hxx>
#include <swp_opts.hxx>
#include <swp_enum.hxx>
#include <container_utils.hxx>

#include "acis_topology.h"
#include "acis_geometric_atoms.h"
#include "utilities.h"

#include "acis_sweeping_export.h"


#ifdef __cplusplus
extern "C" {
#endif

// Define sweep_bool_type enum
typedef struct {
  PyObject_HEAD
} ACIS_Sweeping_SweepBoolType;

PyObject ACIS_SWEEPING_EXPORT *_ACIS_new_SweepBoolType();

bool ACIS_SWEEPING_EXPORT _ACIS_check_SweepBoolType(PyObject *ob);

// Define sweep_options
typedef struct
{
  PyObject_HEAD
  sweep_options *_acis_obj;
} ACIS_Sweeping_SweepOptions;

PyObject ACIS_SWEEPING_EXPORT *_ACIS_new_SweepOptions();

bool ACIS_SWEEPING_EXPORT _ACIS_check_SweepOptions(PyObject *ob);

// Define make_sweep_path_options
typedef struct
{
  PyObject_HEAD
  make_sweep_path_options *_acis_obj;
} ACIS_Sweeping_SweepPathOptions;

PyObject ACIS_SWEEPING_EXPORT *_ACIS_new_SweepPathOptions();

bool ACIS_SWEEPING_EXPORT _ACIS_check_SweepPathOptions(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_SWEEPING_H
