#include "acis_geometry.h"


/**
 * 3D ACIS Modeler - SURFACE wrapper
 */

static int
ACIS_Geometry_init_SURFACE(ACIS_Geometry_SURFACE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_SURFACE(ACIS_Geometry_SURFACE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS SURFACE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_SURFACE(ACIS_Geometry_SURFACE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS SURFACE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_SURFACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_SURFACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_SURFACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_SURFACE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SURFACE",        /* tp_name */
    sizeof(ACIS_Geometry_SURFACE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_SURFACE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_SURFACE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SURFACE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_SURFACE,             /* tp_methods */
    ACIS_Geometry_members_SURFACE,             /* tp_members */
    ACIS_Geometry_getseters_SURFACE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_SURFACE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - CONE wrapper
 */

static int
ACIS_Geometry_init_CONE(ACIS_Geometry_CONE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_CONE(ACIS_Geometry_CONE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS CONE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_CONE(ACIS_Geometry_CONE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS CONE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_CONE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_CONE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_CONE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_CONE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.CONE",        /* tp_name */
    sizeof(ACIS_Geometry_CONE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_CONE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_CONE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS CONE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_CONE,             /* tp_methods */
    ACIS_Geometry_members_CONE,             /* tp_members */
    ACIS_Geometry_getseters_CONE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_CONE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - PLANE wrapper
 */

static int
ACIS_Geometry_init_PLANE(ACIS_Geometry_PLANE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_PLANE(ACIS_Geometry_PLANE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS PLANE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_PLANE(ACIS_Geometry_PLANE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS PLANE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_PLANE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_PLANE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_PLANE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_PLANE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.PLANE",        /* tp_name */
    sizeof(ACIS_Geometry_PLANE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_PLANE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_PLANE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS PLANE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_PLANE,             /* tp_methods */
    ACIS_Geometry_members_PLANE,             /* tp_members */
    ACIS_Geometry_getseters_PLANE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_PLANE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - SPHERE wrapper
 */

static int
ACIS_Geometry_init_SPHERE(ACIS_Geometry_SPHERE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_SPHERE(ACIS_Geometry_SPHERE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS SPHERE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_SPHERE(ACIS_Geometry_SPHERE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS SPHERE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_SPHERE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_SPHERE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_SPHERE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_SPHERE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPHERE",        /* tp_name */
    sizeof(ACIS_Geometry_SPHERE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_SPHERE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_SPHERE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SPHERE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_SPHERE,             /* tp_methods */
    ACIS_Geometry_members_SPHERE,             /* tp_members */
    ACIS_Geometry_getseters_SPHERE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_SPHERE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - SPLINE wrapper
 */

static int
ACIS_Geometry_init_SPLINE(ACIS_Geometry_SPLINE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_SPLINE(ACIS_Geometry_SPLINE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS SPLINE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_SPLINE(ACIS_Geometry_SPLINE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS SPLINE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_SPLINE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_SPLINE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_SPLINE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_SPLINE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SPLINE",        /* tp_name */
    sizeof(ACIS_Geometry_SPLINE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_SPLINE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_SPLINE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SPLINE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_SPLINE,             /* tp_methods */
    ACIS_Geometry_members_SPLINE,             /* tp_members */
    ACIS_Geometry_getseters_SPLINE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_SPLINE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - TORUS wrapper
 */

static int
ACIS_Geometry_init_TORUS(ACIS_Geometry_TORUS *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Geometry_repr_TORUS(ACIS_Geometry_TORUS *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS TORUS object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Geometry_str_TORUS(ACIS_Geometry_TORUS *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS TORUS object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Geometry_getseters_TORUS[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Geometry_members_TORUS[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Geometry_methods_TORUS[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Geometry_type_TORUS =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.TORUS",        /* tp_name */
    sizeof(ACIS_Geometry_TORUS),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Geometry_repr_TORUS,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Geometry_str_TORUS,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS TORUS class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Geometry_methods_TORUS,             /* tp_methods */
    ACIS_Geometry_members_TORUS,             /* tp_members */
    ACIS_Geometry_getseters_TORUS,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Geometry_init_TORUS,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/*
 * Python Module Definitions
 */

// Module documentation can be accessible via __doc__
const char *module_documentation = "Contains  3D ACIS Modeler geometry objects, such as SURFACE, CONE, TORUS, etc.";

static PyModuleDef
  ACIS_Geometry_module =
  {
    PyModuleDef_HEAD_INIT,
    "Geometry",
    module_documentation,
    -1,
    NULL, NULL, NULL, NULL, NULL
  };

PyMODINIT_FUNC
PyInit_Geometry(void)
{
  // Create a Python module, ACIS.Geometry
  PyObject *m;
  m = PyModule_Create(&ACIS_Geometry_module);
  if (m == NULL)
    return NULL;

  // Add SURFACE to the Geometry module
  ACIS_Geometry_type_SURFACE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_SURFACE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_SURFACE);
  PyModule_AddObject(m, "SURFACE", (PyObject *) &ACIS_Geometry_type_SURFACE);

  // Add CONE to the Geometry module
  ACIS_Geometry_type_CONE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_CONE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_CONE);
  PyModule_AddObject(m, "CONE", (PyObject *) &ACIS_Geometry_type_CONE);

  // Add PLANE to the Geometry module
  ACIS_Geometry_type_PLANE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_PLANE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_PLANE);
  PyModule_AddObject(m, "PLANE", (PyObject *) &ACIS_Geometry_type_PLANE);

  // Add SPHERE to the Geometry module
  ACIS_Geometry_type_SPHERE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_SPHERE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_SPHERE);
  PyModule_AddObject(m, "SPHERE", (PyObject *) &ACIS_Geometry_type_SPHERE);

  // Add SPLINE to the Geometry module
  ACIS_Geometry_type_SPLINE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_SPLINE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_SPLINE);
  PyModule_AddObject(m, "SPLINE", (PyObject *) &ACIS_Geometry_type_SPLINE);

  // Add TORUS to the Geometry module
  ACIS_Geometry_type_TORUS.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Geometry_type_TORUS) < 0)
    return NULL;
  Py_INCREF(&ACIS_Geometry_type_TORUS);
  PyModule_AddObject(m, "TORUS", (PyObject *) &ACIS_Geometry_type_TORUS);

  // Return the module and all included objects
  return m;
}

PyObject *_ACIS_new_SURFACE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_SURFACE, NULL);
}

bool _ACIS_check_SURFACE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_SURFACE;
}

PyObject *_ACIS_new_CONE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_CONE, NULL);
}

bool _ACIS_check_CONE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_CONE;
}

PyObject *_ACIS_new_PLANE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_PLANE, NULL);
}

bool _ACIS_check_PLANE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_PLANE;
}

PyObject *_ACIS_new_SPHERE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_SPHERE, NULL);
}

bool _ACIS_check_SPHERE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_SPHERE;
}

PyObject *_ACIS_new_SPLINE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_SPLINE, NULL);
}

bool _ACIS_check_SPLINE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_SPLINE;
}

PyObject *_ACIS_new_TORUS()
{
  return PyObject_CallObject((PyObject *) &ACIS_Geometry_type_TORUS, NULL);
}

bool _ACIS_check_TORUS(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Geometry_type_TORUS;
}
