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

#ifndef A3DPY_CLASSES_H
#define A3DPY_CLASSES_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "utilities.h"


// Define SPAposition
typedef struct
{
  PyObject_HEAD
  SPAposition *_acis_obj;
} a3dp_SPAposition;

// Define SPAvector
typedef struct
{
  PyObject_HEAD
  SPAvector *_acis_obj;
} a3dp_SPAvector;

// Define SPAunit_vector
typedef struct
{
  PyObject_HEAD
  SPAunit_vector *_acis_obj;
} a3dp_SPAunit_vector;

// Define SPAmatrix
typedef struct
{
  PyObject_HEAD
  SPAmatrix *_acis_obj;
} a3dp_SPAmatrix;

// Define SPAtransf
typedef struct
{
  PyObject_HEAD
  SPAtransf *_acis_obj;
} a3dp_SPAtransf;

// Define SPApar_pos
typedef struct
{
  PyObject_HEAD
  SPApar_pos *_acis_obj;
} a3dp_SPApar_pos;

// Define SPApar_vec
typedef struct
{
  PyObject_HEAD
  SPApar_vec *_acis_obj;
} a3dp_SPApar_vec;

// Define FileInfo
typedef struct
{
  PyObject_HEAD
  FileInfo *_acis_obj;
} a3dp_FileInfo;

// Define sweep_options
typedef struct
{
  PyObject_HEAD
  sweep_options *_acis_obj;
} a3dp_sweep_options;

// Define make_sweep_path_options
typedef struct
{
  PyObject_HEAD
  make_sweep_path_options *_acis_obj;
} a3dp_make_sweep_path_options;

// Define BoolOptions
typedef struct
{
  PyObject_HEAD
  BoolOptions *_acis_obj;
} a3dp_BoolOptions;

extern PyTypeObject a3dp_type_SPAposition;
extern PyTypeObject a3dp_type_SPAvector;
extern PyTypeObject a3dp_type_SPAunit_vector;
extern PyTypeObject a3dp_type_SPAmatrix;
extern PyTypeObject a3dp_type_SPAtransf;
extern PyTypeObject a3dp_type_SPApar_pos;
extern PyTypeObject a3dp_type_SPApar_vec;
extern PyTypeObject a3dp_type_FileInfo;
extern PyTypeObject a3dp_type_sweep_options;
extern PyTypeObject a3dp_type_make_sweep_path_options;
extern PyTypeObject a3dp_type_BoolOptions;

#ifdef __cplusplus
extern "C" {
#endif

PyObject *_PyNew_SPAposition();
bool _PyCheck_SPAposition(PyObject *ob);

PyObject *_PyNew_SPAvector();
bool _PyCheck_SPAvector(PyObject *ob);

PyObject *_PyNew_SPAunit_vector();
bool _PyCheck_SPAunit_vector(PyObject *ob);

PyObject *_PyNew_SPAmatrix();
bool _PyCheck_SPAmatrix(PyObject *ob);

PyObject *_PyNew_SPAtransf();
bool _PyCheck_SPAtransf(PyObject *ob);

PyObject *_PyNew_SPApar_pos();
bool _PyCheck_SPApar_pos(PyObject *ob);

PyObject *_PyNew_SPApar_vec();
bool _PyCheck_SPApar_vec(PyObject *ob);

bool _PyCheck_FileInfo(PyObject *ob);

PyObject *_PyNew_sweep_options();
bool _PyCheck_sweep_options(PyObject *ob);

PyObject *_PyNew_make_sweep_path_options();
bool _PyCheck_make_sweep_path_options(PyObject *ob);

PyObject *_PyNew_BoolOptions();
bool _PyCheck_BoolOptions(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_CLASSES_H
