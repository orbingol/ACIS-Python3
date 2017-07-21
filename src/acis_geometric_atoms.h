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

#ifndef ACIS_GEOMETRIC_ATOMS_H
#define ACIS_GEOMETRIC_ATOMS_H

#include <Python.h>
#include <structmember.h>

#include <position.hxx>
#include <transf.hxx>
#include <matrix.hxx>
#include <vector.hxx>
#include <unitvec.hxx>
#include <param.hxx>
#include <geom_utl.hxx>
#include <acistol.hxx>

#include "acis_geometric_atoms_export.h"

#ifdef __cplusplus
extern "C" {
#endif

// Define SPAposition
typedef struct
{
  PyObject_HEAD
  SPAposition *_acis_obj;
} ACIS_GeometricAtoms_SPAposition;

PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPAposition();

bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPAposition(PyObject *ob);

// Define SPAvector
typedef struct
{
  PyObject_HEAD
  SPAvector *_acis_obj;
} ACIS_GeometricAtoms_SPAvector;

PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPAvector();

bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPAvector(PyObject *ob);

// Define SPAunit_vector
typedef struct
{
  PyObject_HEAD
  SPAunit_vector *_acis_obj;
} ACIS_GeometricAtoms_SPAunit_vector;

PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPAunit_vector();

bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPAunit_vector(PyObject *ob);

// Define SPAmatrix
typedef struct
{
  PyObject_HEAD
  SPAmatrix *_acis_obj;
} ACIS_GeometricAtoms_SPAmatrix;

PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPAmatrix();

bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPAmatrix(PyObject *ob);

// Define SPApar_pos
typedef struct
{
  PyObject_HEAD
  SPApar_pos *_acis_obj;
} ACIS_GeometricAtoms_SPApar_pos;

//PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPApar_pos();

//bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPApar_pos(PyObject *ob);

// Define SPAtransf
typedef struct
{
  PyObject_HEAD
  SPAtransf *_acis_obj;
} ACIS_GeometricAtoms_SPAtransf;

PyObject ACIS_GEOMETRIC_ATOMS_EXPORT *_ACIS_new_SPAtransf();

bool ACIS_GEOMETRIC_ATOMS_EXPORT _ACIS_check_SPAtransf(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_GEOMETRIC_ATOMS_H
