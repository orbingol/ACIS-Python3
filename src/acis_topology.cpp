#include "acis_topology.h"


/**
 * 3D ACIS Modeler - ENTITY wrapper
 */

int
ACIS_Topology_traverse_ENTITY(ACIS_Topology_ENTITY *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject-type variables
  Py_VISIT(self->attrib_name);
  Py_VISIT(self->attrib_object_id);

  return 0;
}

int
ACIS_Topology_clear_ENTITY(ACIS_Topology_ENTITY *self)
{
  // Set ACIS object to NULL to allow it automatically deleted by ACIS memory manager
  //self->_acis_obj = NULL;

  // Use Py_CLEAR macro for PyObject variables
  Py_CLEAR(self->attrib_name);
  Py_CLEAR(self->attrib_object_id);

  return 0;
}

void
ACIS_Topology_dealloc_ENTITY(ACIS_Topology_ENTITY *self)
{
  ACIS_Topology_clear_ENTITY(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
ACIS_Topology_new_ENTITY(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  // First check if the modeler has been started
  if(!is_modeler_started())
  {
    PyErr_SetString(PyExc_RuntimeError, "ACIS is not running!");
    return NULL;
  }

  ACIS_Topology_ENTITY *self;

  self = (ACIS_Topology_ENTITY *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    self->attrib_name = PyUnicode_FromString("");
    if (self->attrib_name == NULL)
    {
      Py_DECREF(self);
      return NULL;
    }

    self->attrib_object_id = PyLong_FromLong(-1L);
    if (self->attrib_object_id == NULL)
    {
      Py_DECREF(self);
      return NULL;
    }

    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

int
ACIS_Topology_init_ENTITY(ACIS_Topology_ENTITY *self, PyObject *args, PyObject *kwargs)
{
//  PyObject *input_name = NULL;
//  PyObject *input_id = NULL;
//  PyObject *tmp;
//
//  static char *kwlist[] =
//    {
//      (char *) "name",
//      (char *) "id",
//      NULL
//    };
//
//  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OO", kwlist, &input_name, &input_id))
//    return -1;
//
//  if (input_name != NULL)
//  {
//    if (!PyUnicode_Check(input_name))
//    {
//      PyErr_SetString(PyExc_ValueError, "The first argument (name) must be a string");
//      return -1;
//    }
//
//    tmp = self->attrib_name;
//    Py_INCREF(input_name);
//    self->attrib_name = input_name;
//    Py_XDECREF(tmp);
//  } else
//  {
//    // Set name to an empty string
//    self->attrib_name = PyUnicode_FromString("");
//  }
//
//  if (input_id != NULL)
//  {
//    if (!PyLong_Check(input_id))
//    {
//      PyErr_SetString(PyExc_ValueError, "The second argument (id) must be an integer");
//      return -1;
//    }
//
//    tmp = self->attrib_object_id;
//    Py_INCREF(input_id);
//    self->attrib_object_id = input_id;
//    Py_XDECREF(tmp);
//  } else
//  {
//    // Set object id to zero
//    self->attrib_object_id = PyLong_FromLong(-1L);
//  }

  return 0;
}

PyObject *
ACIS_Topology_repr_ENTITY(ACIS_Topology_ENTITY *self)
{
  const char *_name = PyUnicode_AsUTF8(self->attrib_name);
  int _id = (int)PyLong_AsLong(self->attrib_object_id);
  return PyUnicode_FromFormat("ACIS ENTITY object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
ACIS_Topology_str_ENTITY(ACIS_Topology_ENTITY *self)
{
  const char *acis_obj_status = NULL;
  if (self->_acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS ENTITY object (%s)", acis_obj_status);
}

PyObject *
ACIS_Topology_method_ENTITY_get_attrib_name(ACIS_Topology_ENTITY *self, PyObject *value, void *closure)
{
  Py_INCREF(self->attrib_name);
  return self->attrib_name;
}

int
ACIS_Topology_method_ENTITY_set_attrib_name(ACIS_Topology_ENTITY *self, PyObject *value, void *closure)
{
  if (value == NULL)
  {
    PyErr_SetString(PyExc_TypeError, "Cannot delete NAME attribute");
    return -1;
  }

  if (!PyUnicode_Check(value))
  {
    PyErr_SetString(PyExc_TypeError, "The NAME attribute value must be a str");
    return -1;
  }

  Py_DECREF(self->attrib_name);
  Py_INCREF(value);
  self->attrib_name = value;

  // Extract the C-style string from PyObject
  const char *_attrib_data = PyUnicode_AsUTF8(value);

  // Set the attribute of the ACIS object
  ATTRIB_GEN_NAME *my_att = (ATTRIB_GEN_NAME *) find_attrib((ENTITY *) self->_acis_obj);
  if (my_att != NULL)
  {
    my_att->lose();
  }
  ACIS_NEW ATTRIB_GEN_NAME(self->_acis_obj, _attrib_data);

  return 0;
}

PyObject *
ACIS_Topology_method_ENTITY_get_attrib_obj_id(ACIS_Topology_ENTITY *self, PyObject *value, void *closure)
{
  Py_INCREF(self->attrib_object_id);
  return self->attrib_object_id;
}

int
ACIS_Topology_method_ENTITY_set_attrib_obj_id(ACIS_Topology_ENTITY *self, PyObject *value, void *closure)
{
  if (value == NULL)
  {
    PyErr_SetString(PyExc_TypeError, "Cannot delete ID attribute");
    return -1;
  }

  if (!PyLong_Check(value))
  {
    PyErr_SetString(PyExc_TypeError, "The ID attribute value must be an integer");
    return -1;
  }

  Py_DECREF(self->attrib_object_id);
  Py_INCREF(value);
  self->attrib_object_id = value;

  // Extract the integer value from PyObject
  int _attrib_data = (int) PyLong_AsLong(value);

  // Extract the C-style string from PyObject
  const char *_attrib_data_name = PyUnicode_AsUTF8(self->attrib_name);

  // Set the attribute of the ACIS object (a named integer attribute)
  ATTRIB_GEN_INTEGER *my_att = (ATTRIB_GEN_INTEGER *) find_attrib((ENTITY *) self->_acis_obj);
  if (my_att != NULL)
  {
    my_att->lose();
  }
  ACIS_NEW ATTRIB_GEN_INTEGER(self->_acis_obj, _attrib_data_name, _attrib_data);

  return 0;
}


/**
 * 3D ACIS Modeler - BODY wrapper
 */

static int
ACIS_Topology_init_BODY(ACIS_Topology_BODY *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_BODY(ACIS_Topology_BODY *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS BODY object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_BODY(ACIS_Topology_BODY *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS BODY object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_BODY[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_BODY[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_BODY[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_BODY =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.BODY",        /* tp_name */
    sizeof(ACIS_Topology_BODY),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_BODY,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_BODY,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS BODY class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_BODY,             /* tp_methods */
    ACIS_Topology_members_BODY,             /* tp_members */
    ACIS_Topology_getseters_BODY,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_BODY,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - FACE wrapper
 */

static int
ACIS_Topology_init_FACE(ACIS_Topology_FACE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_FACE(ACIS_Topology_FACE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS FACE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_FACE(ACIS_Topology_FACE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS FACE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_FACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_FACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_FACE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_FACE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.FACE",        /* tp_name */
    sizeof(ACIS_Topology_FACE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_FACE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_FACE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS FACE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_FACE,             /* tp_methods */
    ACIS_Topology_members_FACE,             /* tp_members */
    ACIS_Topology_getseters_FACE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_FACE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - EDGE wrapper
 */

static int
ACIS_Topology_init_EDGE(ACIS_Topology_EDGE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_EDGE(ACIS_Topology_EDGE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS EDGE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_EDGE(ACIS_Topology_EDGE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS EDGE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_EDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_EDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_EDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_EDGE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.EDGE",        /* tp_name */
    sizeof(ACIS_Topology_EDGE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_EDGE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_EDGE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS EDGE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_EDGE,             /* tp_methods */
    ACIS_Topology_members_EDGE,             /* tp_members */
    ACIS_Topology_getseters_EDGE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_EDGE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - WIRE wrapper
 */

static int
ACIS_Topology_init_WIRE(ACIS_Topology_WIRE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_WIRE(ACIS_Topology_WIRE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS WIRE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_WIRE(ACIS_Topology_WIRE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS WIRE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_WIRE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_WIRE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_WIRE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_WIRE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.WIRE",        /* tp_name */
    sizeof(ACIS_Topology_WIRE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_WIRE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_WIRE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS WIRE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_WIRE,             /* tp_methods */
    ACIS_Topology_members_WIRE,             /* tp_members */
    ACIS_Topology_getseters_WIRE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_WIRE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - LUMP wrapper
 */

static int
ACIS_Topology_init_LUMP(ACIS_Topology_LUMP *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_LUMP(ACIS_Topology_LUMP *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS LUMP object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_LUMP(ACIS_Topology_LUMP *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS LUMP object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_LUMP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_LUMP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_LUMP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_LUMP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.LUMP",        /* tp_name */
    sizeof(ACIS_Topology_LUMP),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_LUMP,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_LUMP,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS LUMP class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_LUMP,             /* tp_methods */
    ACIS_Topology_members_LUMP,             /* tp_members */
    ACIS_Topology_getseters_LUMP,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_LUMP,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - SHELL wrapper
 */

static int
ACIS_Topology_init_SHELL(ACIS_Topology_SHELL *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_SHELL(ACIS_Topology_SHELL *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS SHELL object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_SHELL(ACIS_Topology_SHELL *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS SHELL object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_SHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_SHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_SHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_SHELL =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SHELL",        /* tp_name */
    sizeof(ACIS_Topology_SHELL),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_SHELL,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_SHELL,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SHELL class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_SHELL,             /* tp_methods */
    ACIS_Topology_members_SHELL,             /* tp_members */
    ACIS_Topology_getseters_SHELL,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_SHELL,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - SUBSHELL wrapper
 */

static int
ACIS_Topology_init_SUBSHELL(ACIS_Topology_SUBSHELL *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_SUBSHELL(ACIS_Topology_SUBSHELL *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS SUBSHELL object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_SUBSHELL(ACIS_Topology_SUBSHELL *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS SUBSHELL object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_SUBSHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_SUBSHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_SUBSHELL[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_SUBSHELL =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.SUBSHELL",        /* tp_name */
    sizeof(ACIS_Topology_SUBSHELL),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_SUBSHELL,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_SUBSHELL,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS SUBSHELL class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_SUBSHELL,             /* tp_methods */
    ACIS_Topology_members_SUBSHELL,             /* tp_members */
    ACIS_Topology_getseters_SUBSHELL,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_SUBSHELL,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - COEDGE wrapper
 */

static int
ACIS_Topology_init_COEDGE(ACIS_Topology_COEDGE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_COEDGE(ACIS_Topology_COEDGE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS COEDGE object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_COEDGE(ACIS_Topology_COEDGE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS COEDGE object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_COEDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_COEDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_COEDGE[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_COEDGE =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.COEDGE",        /* tp_name */
    sizeof(ACIS_Topology_COEDGE),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_COEDGE,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_COEDGE,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS COEDGE class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_COEDGE,             /* tp_methods */
    ACIS_Topology_members_COEDGE,             /* tp_members */
    ACIS_Topology_getseters_COEDGE,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_COEDGE,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - LOOP wrapper
 */

static int
ACIS_Topology_init_LOOP(ACIS_Topology_LOOP *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_LOOP(ACIS_Topology_LOOP *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS LOOP object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_LOOP(ACIS_Topology_LOOP *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS LOOP object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_LOOP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_LOOP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_LOOP[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_LOOP =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.LOOP",        /* tp_name */
    sizeof(ACIS_Topology_LOOP),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_LOOP,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_LOOP,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS LOOP class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_LOOP,             /* tp_methods */
    ACIS_Topology_members_LOOP,             /* tp_members */
    ACIS_Topology_getseters_LOOP,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_LOOP,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/**
 * 3D ACIS Modeler - VERTEX wrapper
 */

static int
ACIS_Topology_init_VERTEX(ACIS_Topology_VERTEX *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (ACIS_Topology_type_ENTITY.tp_init((PyObject *)self, args, kwargs) < 0)
    return -1;

  return 0;
}

static PyObject *
ACIS_Topology_repr_VERTEX(ACIS_Topology_VERTEX *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int)PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("ACIS VERTEX object with name '%s' and ID '%i'", _name, _id);
}

static PyObject *
ACIS_Topology_str_VERTEX(ACIS_Topology_VERTEX *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ACIS VERTEX object (%s)", acis_obj_status);
}

static PyGetSetDef
  ACIS_Topology_getseters_VERTEX[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Topology_members_VERTEX[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Topology_methods_VERTEX[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Topology_type_VERTEX =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.VERTEX",        /* tp_name */
    sizeof(ACIS_Topology_VERTEX),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    (reprfunc) ACIS_Topology_repr_VERTEX,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    (reprfunc) ACIS_Topology_str_VERTEX,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "ACIS VERTEX class",           /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Topology_methods_VERTEX,             /* tp_methods */
    ACIS_Topology_members_VERTEX,             /* tp_members */
    ACIS_Topology_getseters_VERTEX,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Topology_init_VERTEX,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
  };


/*
 * Python Module Definitions
 */

// Module documentation can be accessible via __doc__
const char *module_name = "Topology";
const char *module_documentation = "Contains 3D ACIS Modeler topology objects, such as BODY, FACE, WIRE, etc.";

static PyModuleDef
  ACIS_Topology_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name,
    module_documentation,
    -1,
    NULL, NULL, NULL, NULL, NULL
  };

PyMODINIT_FUNC
PyInit_Topology(void)
{
  // Create a Python module, ACIS.Topology
  PyObject *m;
  m = PyModule_Create(&ACIS_Topology_module);
  if (m == NULL)
    return NULL;

  // Add ENTITY to the Topology module
  if (PyType_Ready(&ACIS_Topology_type_ENTITY) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_ENTITY);
  PyModule_AddObject(m, "ENTITY", (PyObject *) &ACIS_Topology_type_ENTITY);

  // Add BODY to the Topology module
  ACIS_Topology_type_BODY.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_BODY) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_BODY);
  PyModule_AddObject(m, "BODY", (PyObject *) &ACIS_Topology_type_BODY);

  // Add FACE to the Topology module
  ACIS_Topology_type_FACE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_FACE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_FACE);
  PyModule_AddObject(m, "FACE", (PyObject *) &ACIS_Topology_type_FACE);

  // Add EDGE to the Topology module
  ACIS_Topology_type_EDGE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_EDGE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_EDGE);
  PyModule_AddObject(m, "EDGE", (PyObject *) &ACIS_Topology_type_EDGE);

  // Add WIRE to the Topology module
  ACIS_Topology_type_WIRE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_WIRE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_WIRE);
  PyModule_AddObject(m, "WIRE", (PyObject *) &ACIS_Topology_type_WIRE);

  // Add LUMP to the Topology module
  ACIS_Topology_type_LUMP.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_LUMP) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_LUMP);
  PyModule_AddObject(m, "LUMP", (PyObject *) &ACIS_Topology_type_LUMP);

  // Add SHELL to the Topology module
  ACIS_Topology_type_SHELL.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_SHELL) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_SHELL);
  PyModule_AddObject(m, "SHELL", (PyObject *) &ACIS_Topology_type_SHELL);

  // Add SUBSHELL to the Topology module
  ACIS_Topology_type_SUBSHELL.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_SUBSHELL) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_SUBSHELL);
  PyModule_AddObject(m, "SUBSHELL", (PyObject *) &ACIS_Topology_type_SUBSHELL);

  // Add COEDGE to the Topology module
  ACIS_Topology_type_COEDGE.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_COEDGE) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_COEDGE);
  PyModule_AddObject(m, "COEDGE", (PyObject *) &ACIS_Topology_type_COEDGE);

  // Add LOOP to the Topology module
  ACIS_Topology_type_LOOP.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_LOOP) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_LOOP);
  PyModule_AddObject(m, "LOOP", (PyObject *) &ACIS_Topology_type_LOOP);

  // Add VERTEX to the Topology module
  ACIS_Topology_type_VERTEX.tp_base = &ACIS_Topology_type_ENTITY;
  if (PyType_Ready(&ACIS_Topology_type_VERTEX) < 0)
    return NULL;
  Py_INCREF(&ACIS_Topology_type_VERTEX);
  PyModule_AddObject(m, "VERTEX", (PyObject *) &ACIS_Topology_type_VERTEX);

  // Return the module and all included objects
  return m;
}

PyObject *_ACIS_new_ENTITY()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_ENTITY, NULL);
}

bool _ACIS_check_ENTITY(PyObject *ob)
{
  int retval = PyObject_IsInstance(ob, (PyObject *)&ACIS_Topology_type_ENTITY);
  if (retval < 0)
  {
    PyErr_SetString(PyExc_TypeError, "Problem with ENTITY type cheking");
    return false;
  }
  return retval != 0;
}

PyObject *_ACIS_new_BODY()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_BODY, NULL);
}

bool _ACIS_check_BODY(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_BODY;
}

PyObject *_ACIS_new_FACE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_FACE, NULL);
}

bool _ACIS_check_FACE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_FACE;
}

PyObject *_ACIS_new_EDGE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_EDGE, NULL);
}

bool _ACIS_check_EDGE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_EDGE;
}

PyObject *_ACIS_new_WIRE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_WIRE, NULL);
}

bool _ACIS_check_WIRE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_WIRE;
}

PyObject *_ACIS_new_LUMP()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_LUMP, NULL);
}

bool _ACIS_check_LUMP(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_LUMP;
}

PyObject *_ACIS_new_SHELL()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_SHELL, NULL);
}

bool _ACIS_check_SHELL(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_SHELL;
}

PyObject *_ACIS_new_SUBSHELL()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_SUBSHELL, NULL);
}

bool _ACIS_check_SUBSHELL(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_SUBSHELL;
}

PyObject *_ACIS_new_COEDGE()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_COEDGE, NULL);
}

bool _ACIS_check_COEDGE(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_COEDGE;
}

PyObject *_ACIS_new_LOOP()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_LOOP, NULL);
}

bool _ACIS_check_LOOP(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_LOOP;
}

PyObject *_ACIS_new_VERTEX()
{
  return PyObject_CallObject((PyObject *) &ACIS_Topology_type_VERTEX, NULL);
}

bool _ACIS_check_VERTEX(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Topology_type_VERTEX;
}

void _ACIS_make_null(PyObject *ob)
{
  if (_ACIS_check_ENTITY(ob))
  {
    ((ACIS_Topology_ENTITY *) ob)->_acis_obj = NULL;
  }
}
