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

#ifndef ACIS_GEOMETRY_H
#define ACIS_GEOMETRY_H

#include <Python.h>
#include <structmember.h>

#include <surface.hxx>
#include <cone.hxx>
#include <plane.hxx>
#include <sphere.hxx>
#include <spline.hxx>
#include <torus.hxx>

#include "acis_topology.h"

#include "acis_geometry_export.h"


#ifdef __cplusplus
extern "C" {
#endif

// Types and their functions

// Define SURFACE
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_SURFACE;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_SURFACE();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_SURFACE(PyObject *ob);

// Define CONE
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_CONE;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_CONE();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_CONE(PyObject *ob);

// Define PLANE
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_PLANE;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_PLANE();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_PLANE(PyObject *ob);

// Define SPHERE
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_SPHERE;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_SPHERE();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_SPHERE(PyObject *ob);

// Define SPLINE
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_SPLINE;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_SPLINE();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_SPLINE(PyObject *ob);

// Define TORUS
typedef struct
{
  ACIS_Topology_ENTITY base_obj;
} ACIS_Geometry_TORUS;

PyObject ACIS_GEOMETRY_EXPORT *_ACIS_new_TORUS();

bool ACIS_GEOMETRY_EXPORT _ACIS_check_TORUS(PyObject *ob);

#ifdef __cplusplus
}
#endif

#endif // !ACIS_GEOMETRY_H
