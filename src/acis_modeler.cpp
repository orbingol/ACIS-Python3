#include "acis_modeler.h"


const char *module_name = "Modeler";
const char *module_documentation = "3D ACIS Modeler";

static PyMethodDef
    module_methods[] =
    {
        { "spa_unlock_products", (PyCFunction) a3dp_spa_unlock_products, METH_O, "Unlock the 3D ACIS Modeler using the license key" },
        { "api_start_modeller", (PyCFunction) a3dp_api_start_modeller, METH_VARARGS | METH_KEYWORDS, "Starts the 3D ACIS Modeler" },
        { "api_stop_modeller", (PyCFunction) a3dp_api_stop_modeller, METH_NOARGS, "Stops the 3D ACIS Modeler" },
        { "is_modeler_started", (PyCFunction) a3dp_is_modeler_started, METH_NOARGS, "Checks if the 3D ACIS Modeler started" },
        { "api_start_modeler", (PyCFunction) a3dp_api_start_modeller, METH_VARARGS | METH_KEYWORDS, "Alternative way to call api_start_modeller()" },
        { "api_stop_modeler", (PyCFunction) a3dp_api_stop_modeller, METH_NOARGS, "Alternative way to call api_stop_modeller()" },
        { "api_save_entity_list", (PyCFunction) a3dp_api_save_entity_list, METH_VARARGS | METH_KEYWORDS, "Writes entities to a file in text or binary format" },
        { "api_set_file_info", (PyCFunction) a3dp_api_set_file_info, METH_VARARGS | METH_KEYWORDS, "Sets required header info to be written to ACIS save files" },
        { "api_get_file_info", (PyCFunction) a3dp_api_get_file_info, METH_O | METH_KEYWORDS, "Gets header info from the last restored file" },
        { "api_save_version", (PyCFunction) a3dp_api_save_version, METH_VARARGS | METH_KEYWORDS, "Sets the save file format" },
        { "api_set_dbl_option", (PyCFunction) a3dp_api_set_dbl_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given double" },
        { "api_set_int_option", (PyCFunction) a3dp_api_set_int_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given integer" },
        { "api_set_str_option", (PyCFunction) a3dp_api_set_str_option, METH_VARARGS | METH_KEYWORDS, "Sets the value of the specified option to the given string" },
        { "api_solid_block", (PyCFunction) a3dp_api_solid_block, METH_VARARGS | METH_KEYWORDS, "Creates a solid block given two positions on a diagonal of the block" },
        { "api_make_cuboid", (PyCFunction) a3dp_api_make_cuboid, METH_VARARGS | METH_KEYWORDS, "Creates cuboid of given width (x), depth (y) and height (z)" },
        { "api_make_frustum", (PyCFunction) a3dp_api_make_frustum, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical cone or cylinder of given height and radii" },
        { "api_make_prism", (PyCFunction) a3dp_api_make_prism, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical prism of given height, radii, and number of sides" },
        { "api_make_pyramid", (PyCFunction) a3dp_api_make_pyramid, METH_VARARGS | METH_KEYWORDS, "Creates an elliptical pyramid of given height, radii, and number of sides" },
        { "api_make_sphere", (PyCFunction) a3dp_api_make_sphere, METH_VARARGS | METH_KEYWORDS, "Creates a sphere of given radius, centered at the origin" },
        { "api_make_torus", (PyCFunction) a3dp_api_make_torus, METH_VARARGS | METH_KEYWORDS, "Creates a torus of given major and minor radii centered at the origin" },
        { "api_apply_transf", (PyCFunction) a3dp_api_apply_transf, METH_VARARGS | METH_KEYWORDS, "Changes the transform entity attached to a body" },
        { "api_remove_transf", (PyCFunction) a3dp_api_remove_transf, METH_VARARGS | METH_KEYWORDS, "Removes (discards) the transformation of a body" },
        { "api_sheet_from_ff", (PyCFunction) a3dp_api_sheet_from_ff, METH_VARARGS | METH_KEYWORDS, "Creates a sheet body as a copy of a face" },
        { "api_unite", (PyCFunction) a3dp_api_unite, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean unite operation" },
        { "api_intersect", (PyCFunction) a3dp_api_intersect, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean intersect operation on two bodies" },
        { "api_subtract", (PyCFunction) a3dp_api_subtract, METH_VARARGS | METH_KEYWORDS, "Executes a Boolean subtract operation" },
        { "api_imprint", (PyCFunction) a3dp_api_imprint, METH_VARARGS | METH_KEYWORDS, "Intersects two bodies and imprints the intersection graph on both bodies" },
        { "api_boolean_chop_body", (PyCFunction) a3dp_api_boolean_chop_body, METH_VARARGS | METH_KEYWORDS, "Executes simultaneous Boolean intersect and subtract operations on two bodies" },
        { "api_make_sweep_path", (PyCFunction) a3dp_api_make_sweep_path, METH_VARARGS | METH_KEYWORDS, "Constructs a path useful for creating a swept surface" },
        { "api_sweep_with_options", (PyCFunction) a3dp_api_sweep_with_options, METH_VARARGS | METH_KEYWORDS, "Sweeps the given profile along an edge, a distance, a vector or an axis" },
        { "get_owner_transf", (PyCFunction) a3dp_get_owner_transf, METH_VARARGS | METH_KEYWORDS, "Gets a copy of the SPAtransf from the owner of an ENTITY" },
        { "api_get_faces", (PyCFunction) a3dp_api_get_faces, METH_VARARGS | METH_KEYWORDS, "Gets all faces related to an entity" },
        { "api_get_edges", (PyCFunction) a3dp_api_get_edges, METH_VARARGS | METH_KEYWORDS, "Gets all the edges related to an entity" },
        { "coordinate_transf", (PyCFunction) a3dp_coordinate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a coordinate transformation" },
        { "make_transf", (PyCFunction) a3dp_make_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation retrieving the needed information from the provided transformation matrix and the scaling vector" },
        { "reflect_transf", (PyCFunction) a3dp_reflect_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a reflection through a plane, specified by its normal" },
        { "rotate_transf", (PyCFunction) a3dp_rotate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a simple rotation by an angle about a given axis" },
        { "scale_transf", (PyCFunction) a3dp_scale_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a scale transformation (uniform, non-uniform and shear)" },
        { "shear_transf", (PyCFunction) a3dp_shear_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a shear transformation" },
        { "translate_transf", (PyCFunction) a3dp_translate_transf, METH_VARARGS | METH_KEYWORDS, "Constructs a transformation corresponding to a translation by a given vector" },
        { "angle_between", (PyCFunction) a3dp_angle_between, METH_VARARGS | METH_KEYWORDS, "Calculates the angle between two vectors or unit vectors" },
        { "antiparallel", (PyCFunction) a3dp_antiparallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are anti-parallel" },
        { "are_parallel", (PyCFunction) a3dp_are_parallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are parallel" },
        { "are_perpendicular", (PyCFunction) a3dp_are_perpendicular, METH_VARARGS | METH_KEYWORDS, "	Determines if two vectors or unit vectors are perpendicular" },
        { "biparallel", (PyCFunction) a3dp_biparallel, METH_VARARGS | METH_KEYWORDS, "Determines if two vectors or unit vectors are bi-parallel" },
        { "degrees_to_radians", (PyCFunction) a3dp_degrees_to_radians, METH_VARARGS | METH_KEYWORDS, "Converts an angle from degrees to radians" },
        { "radians_to_degrees", (PyCFunction) a3dp_radians_to_degrees, METH_VARARGS | METH_KEYWORDS, "Converts an angle from radians to degrees" },
        { "get_resabs", (PyCFunction) a3dp_get_resabs, METH_NOARGS, "Gets the SPAresabs resolution" },
        { "get_resfit", (PyCFunction) a3dp_get_resfit, METH_NOARGS, "Gets the SPAresfit resolution" },
        { "get_resmch", (PyCFunction) a3dp_get_resmch, METH_NOARGS, "Gets the resmch resolution" },
        { "get_resnor", (PyCFunction) a3dp_get_resnor, METH_NOARGS, "Gets the SPAresnor resolution" },
        { "distance_to_point", (PyCFunction) a3dp_distance_to_point, METH_VARARGS | METH_KEYWORDS, "Determines the distance between two points" },
        { "distance_to_point_squared", (PyCFunction) a3dp_distance_to_point_squared, METH_VARARGS | METH_KEYWORDS, "\tComputes the squared distance between two positions" },
        { NULL, NULL, 0, NULL }
    };

struct PyModuleDef
  a3dp_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_Modeler(void)
{
  PyObject *m;

  m = PyModule_Create(&a3dp_module);
  if (m == NULL)
    return NULL;

  // SPAposition
  if (PyType_Ready(&a3dp_type_SPAposition) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAposition);
  PyModule_AddObject(m, "SPAposition", (PyObject *) &a3dp_type_SPAposition);

  // SPAtransf
  if (PyType_Ready(&a3dp_type_SPAtransf) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAtransf);
  PyModule_AddObject(m, "SPAtransf", (PyObject *) &a3dp_type_SPAtransf);

  // SPAmatrix
  if (PyType_Ready(&a3dp_type_SPAmatrix) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAmatrix);
  PyModule_AddObject(m, "SPAmatrix", (PyObject *) &a3dp_type_SPAmatrix);

  // SPAvector
  if (PyType_Ready(&a3dp_type_SPAvector) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAvector);
  PyModule_AddObject(m, "SPAvector", (PyObject *) &a3dp_type_SPAvector);

  // SPAunit_vector
  if (PyType_Ready(&a3dp_type_SPAunitvector) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAunitvector);
  PyModule_AddObject(m, "SPAunit_vector", (PyObject *) &a3dp_type_SPAunitvector);

  // SPApar_pos
  if (PyType_Ready(&a3dp_type_SPAparpos) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAparpos);
  PyModule_AddObject(m, "SPApar_pos", (PyObject *) &a3dp_type_SPAparpos);

  // SPApar_vec
  if (PyType_Ready(&a3dp_type_SPAparvec) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPAparvec);
  PyModule_AddObject(m, "SPApar_vec", (PyObject *) &a3dp_type_SPAparvec);

  if (PyType_Ready(&a3dp_type_FileInfo) < 0)
    return NULL;

  Py_INCREF(&a3dp_type_FileInfo);
  PyModule_AddObject(m, "FileInfo", (PyObject *) &a3dp_type_FileInfo);

  // Create a dictionary object for NDBOOL_KEEP enum
  PyObject *_ndbk_dict;
  _ndbk_dict = PyDict_New();
  if (_ndbk_dict != NULL)
  {
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_NEITHER", PyLong_FromLong(0L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_TOOL", PyLong_FromLong(1L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_BLANK", PyLong_FromLong(2L));
    PyDict_SetItemString(_ndbk_dict, "NDBOOL_KEEP_BOTH", PyLong_FromLong(3L));
  }

  // NDBOOL_KEEP
  a3dp_type_NDBOOLKEEP.tp_dict = _ndbk_dict;
  if (PyType_Ready(&a3dp_type_NDBOOLKEEP) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_NDBOOLKEEP);
  PyModule_AddObject(m, "NDBOOL_KEEP", (PyObject *) &a3dp_type_NDBOOLKEEP);

  // Create a dictionary object for sweep_bool_type enum
  PyObject *_sbt_dict;
  _sbt_dict = PyDict_New();
  if (_sbt_dict != NULL)
  {
    PyDict_SetItemString(_sbt_dict, "UNITE", PyLong_FromLong(0L));
    PyDict_SetItemString(_sbt_dict, "INTERSECT", PyLong_FromLong(1L));
    PyDict_SetItemString(_sbt_dict, "SUBTRACT", PyLong_FromLong(2L));
    PyDict_SetItemString(_sbt_dict, "LIMIT", PyLong_FromLong(3L));
    PyDict_SetItemString(_sbt_dict, "KEEP_BOTH", PyLong_FromLong(4L));
  }

  // sweep_bool_type
  a3dp_type_sweepbooltype.tp_dict = _sbt_dict;
  if (PyType_Ready(&a3dp_type_sweepbooltype) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_sweepbooltype);
  PyModule_AddObject(m, "sweep_bool_type", (PyObject *) &a3dp_type_sweepbooltype);

  // sweep_options
  if (PyType_Ready(&a3dp_type_sweep_options) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_sweep_options);
  PyModule_AddObject(m, "sweep_options", (PyObject *) &a3dp_type_sweep_options);

  // make_sweep_path_options
  if (PyType_Ready(&a3dp_type_make_sweep_path_options) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_make_sweep_path_options);
  PyModule_AddObject(m, "make_sweep_path_options", (PyObject *) &a3dp_type_make_sweep_path_options);

  // Add ENTITY to the module
  if (PyType_Ready(&a3dp_type_ENTITY) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_ENTITY);
  PyModule_AddObject(m, "ENTITY", (PyObject *) &a3dp_type_ENTITY);

  // Add BODY to the module
  a3dp_type_BODY.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_BODY) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_BODY);
  PyModule_AddObject(m, "BODY", (PyObject *) &a3dp_type_BODY);

  // Add FACE to the module
  a3dp_type_FACE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_FACE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_FACE);
  PyModule_AddObject(m, "FACE", (PyObject *) &a3dp_type_FACE);

  // Add EDGE to the module
  a3dp_type_EDGE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_EDGE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_EDGE);
  PyModule_AddObject(m, "EDGE", (PyObject *) &a3dp_type_EDGE);

  // Add WIRE to the module
  a3dp_type_WIRE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_WIRE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_WIRE);
  PyModule_AddObject(m, "WIRE", (PyObject *) &a3dp_type_WIRE);

  // Add LUMP to the module
  a3dp_type_LUMP.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_LUMP) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_LUMP);
  PyModule_AddObject(m, "LUMP", (PyObject *) &a3dp_type_LUMP);

  // Add SHELL to the module
  a3dp_type_SHELL.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_SHELL) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SHELL);
  PyModule_AddObject(m, "SHELL", (PyObject *) &a3dp_type_SHELL);

  // Add SUBSHELL to the module
  a3dp_type_SUBSHELL.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_SUBSHELL) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SUBSHELL);
  PyModule_AddObject(m, "SUBSHELL", (PyObject *) &a3dp_type_SUBSHELL);

  // Add COEDGE to the module
  a3dp_type_COEDGE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_COEDGE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_COEDGE);
  PyModule_AddObject(m, "COEDGE", (PyObject *) &a3dp_type_COEDGE);

  // Add LOOP to the module
  a3dp_type_LOOP.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_LOOP) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_LOOP);
  PyModule_AddObject(m, "LOOP", (PyObject *) &a3dp_type_LOOP);

  // Add VERTEX to the module
  a3dp_type_VERTEX.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_VERTEX) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_VERTEX);
  PyModule_AddObject(m, "VERTEX", (PyObject *) &a3dp_type_VERTEX);

  // Add SURFACE to the module
  a3dp_type_SURFACE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_SURFACE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SURFACE);
  PyModule_AddObject(m, "SURFACE", (PyObject *) &a3dp_type_SURFACE);

  // Add CONE to the module
  a3dp_type_CONE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_CONE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_CONE);
  PyModule_AddObject(m, "CONE", (PyObject *) &a3dp_type_CONE);

  // Add PLANE to the module
  a3dp_type_PLANE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_PLANE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_PLANE);
  PyModule_AddObject(m, "PLANE", (PyObject *) &a3dp_type_PLANE);

  // Add SPHERE to the module
  a3dp_type_SPHERE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_SPHERE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPHERE);
  PyModule_AddObject(m, "SPHERE", (PyObject *) &a3dp_type_SPHERE);

  // Add SPLINE to the module
  a3dp_type_SPLINE.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_SPLINE) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_SPLINE);
  PyModule_AddObject(m, "SPLINE", (PyObject *) &a3dp_type_SPLINE);

  // Add TORUS to the module
  a3dp_type_TORUS.tp_base = &a3dp_type_ENTITY;
  if (PyType_Ready(&a3dp_type_TORUS) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_TORUS);
  PyModule_AddObject(m, "TORUS", (PyObject *) &a3dp_type_TORUS);

  // Add surface to the module
  if (PyType_Ready(&a3dp_type_surface) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_surface);
  PyModule_AddObject(m, "surface", (PyObject *) &a3dp_type_surface);

  // Initialize ACIS ENTITY_LIST class as a Python type
  if (PyType_Ready(&a3dp_type_ENTITYLIST) < 0)
    return NULL;
  Py_INCREF(&a3dp_type_ENTITYLIST);
  PyModule_AddObject(m, "ENTITY_LIST", (PyObject *) &a3dp_type_ENTITYLIST);

  return m;
}
