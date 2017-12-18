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

#ifndef A3DPY_API_H
#define A3DPY_API_H

#include <Python.h>
#include <structmember.h>

#include "acis_includes.h"
#include "acis_entity.h"
#include "acis_operators.h"
#include "acis_classes.h"
#include "acis_enums.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

PyObject *a3dp_api_start_modeller(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_stop_modeller(PyObject *self);
PyObject *a3dp_api_set_dbl_option(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_set_int_option(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_set_str_option(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_solid_block(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_cuboid(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_frustum(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_prism(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_pyramid(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_sphere(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_torus(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_apply_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_remove_transf(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_sheet_from_ff(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_unite(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_intersect(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_subtract(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_imprint(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_boolean_chop_body(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_save_entity_list(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_restore_entity_list(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_set_file_info(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_file_info(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_save_version(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_make_sweep_path(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_sweep_with_options(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_faces(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_edges(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_loops(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_logging(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_body_to_1d(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_body_to_2d(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_entity_id(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_get_entity_box(PyObject *self, PyObject *args, PyObject *kwargs);
PyObject *a3dp_api_closed_wire(PyObject *self, PyObject *args, PyObject *kwargs);

#ifdef __cplusplus
}
#endif

#endif // !A3DPY_API_H
