#include "acis_sweeping.h"


/**
 * make_sweep_path_options class
 */

static void
ACIS_Sweeping_dealloc_SweepPathOptions(ACIS_Sweeping_SweepPathOptions *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_Sweeping_new_SweepPathOptions(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_Sweeping_SweepPathOptions *self;

  self = (ACIS_Sweeping_SweepPathOptions *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_Sweeping_init_SweepPathOptions(ACIS_Sweeping_SweepPathOptions *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW make_sweep_path_options();

  return 0;
}

static PyMemberDef
  ACIS_Sweeping_members_SweepPathOptions[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Sweeping_methods_SweepPathOptions[] =
  {
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Sweeping_type_SweepPathOptions =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.make_sweep_path_options",             /* tp_name */
    sizeof(ACIS_Sweeping_SweepPathOptions), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_Sweeping_dealloc_SweepPathOptions, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "make_sweep_path_options class allows the user to exercise finer control over the construction of sweep path", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Sweeping_methods_SweepPathOptions, /* tp_methods */
    ACIS_Sweeping_members_SweepPathOptions, /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Sweeping_init_SweepPathOptions, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_Sweeping_new_SweepPathOptions, /* tp_new */
  };


/**
 * sweep_bool_type enum
 */

static PyTypeObject
  ACIS_Sweeping_type_SweepBoolType =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.sweep_bool_type",             /* tp_name */
    sizeof(ACIS_Sweeping_SweepBoolType), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Sweep to body boolean operation type",           /* tp_doc */
  };


/**
 * sweep_options class
 */

static void
ACIS_Sweeping_dealloc_SweepOptions(ACIS_Sweeping_SweepOptions *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_Sweeping_new_SweepOptions(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_Sweeping_SweepOptions *self;

  self = (ACIS_Sweeping_SweepOptions *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_Sweeping_init_SweepOptions(ACIS_Sweeping_SweepOptions *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the ACIS object
  self->_acis_obj = ACIS_NEW sweep_options();

  return 0;
}

static PyObject *
ACIS_Sweeping_method_SweepOptions_set_bool_type(ACIS_Sweeping_SweepOptions *self, PyObject *args, PyObject *kwargs)
{
  // Just a testing...
  self->_acis_obj->set_bool_type(KEEP_BOTH);

  Py_RETURN_NONE;
}

static PyGetSetDef
  ACIS_Sweeping_getseters_SweepOptions[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Sweeping_members_SweepOptions[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Sweeping_methods_SweepOptions[] =
  {
    { "set_bool_type", (PyCFunction) ACIS_Sweeping_method_SweepOptions_set_bool_type, METH_VARARGS | METH_KEYWORDS, "Sets the option for the Boolean operation type with the to_body" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Sweeping_type_SweepOptions =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.sweep_options",             /* tp_name */
    sizeof(ACIS_Sweeping_SweepOptions), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_Sweeping_dealloc_SweepOptions, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    "sweep_options class provides a data structure for sweeping operations to be used in the function api_sweep_with_options", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Sweeping_methods_SweepOptions, /* tp_methods */
    ACIS_Sweeping_members_SweepOptions, /* tp_members */
    ACIS_Sweeping_getseters_SweepOptions, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Sweeping_init_SweepOptions, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_Sweeping_new_SweepOptions, /* tp_new */
  };


/**
 * Sweeping API Interface Functions
 */

static PyObject *
ACIS_api_make_sweep_path(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_pts = NULL, *input_path = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "pts",
      (char *) "path",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &input_pts, &input_path))
    return NULL;

  // Type checks for ACIS objects
  if (!_ACIS_check_EDGE(input_path))
  {
    PyErr_SetString(PyExc_TypeError, "Second argument (path) must be an EDGE object");
    return NULL;
  }

  // The first object must be a python sequence containing SPAposition objects
  PyObject *seq = PySequence_Fast(input_pts, "First argument (pts) must be a sequence of SPAposition objects, such as a list or a tuple");

  Py_ssize_t position_vector_size = PySequence_Fast_GET_SIZE(seq);
  if (position_vector_size <= 0)
  {
    PyErr_SetString(PyExc_ValueError, "Sequence cannot be empty");
    Py_DECREF(seq);
    return NULL;
  }

  // It seems unnecessary to implement a SPAposition container as python itself provides a handful of containers for every purpose
  SPAposition_vector _pts;

  for (Py_ssize_t i = 0; i < position_vector_size; i++)
  {
    PyObject *pt_temp;
    pt_temp = PySequence_Fast_GET_ITEM(seq, i);
    if (!_ACIS_check_SPAposition(pt_temp))
    {
      PyErr_SetString(PyExc_TypeError, "Sequence must contain SPAposition objects");
      Py_DECREF(seq);
      return NULL;
    }
    _pts.push_back(*((ACIS_GeometricAtoms_SPAposition *) pt_temp)->_acis_obj);
  }

  API_BEGIN

            EDGE *&_path = (EDGE *&) ((ACIS_Entity_EDGE *) input_path)->base_obj._acis_obj;

            // Don't use make_sweep_path_options for now
            result = api_make_sweep_path(_pts, _path);

  API_END

  // PySequence_Fast returns a new reference
  Py_DECREF(seq);

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Clear SPAposition container
    _pts.clear();
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_api_sweep_with_options(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_arg1 = NULL, *input_arg2 = NULL, *input_arg3 = NULL, *input_arg4 = NULL, *input_arg5 = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "arg1",
      (char *) "arg2",
      (char *) "arg3",
      (char *) "arg4",
      (char *) "arg5",
      NULL
    };

  // Try to parse input arguments and/or keywords (hold sweep_options for now)
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOOO|O", kwlist, &input_arg1, &input_arg2, &input_arg3, &input_arg4, &input_arg5))
    return NULL;

  /*
   * IMPORTANT NOTE: This function wraps all 4 api_sweep_with_options overloads in one single Python function.
   * The reason is that Python doesn't allow overloading with same function names but different signatures.
   */

  // In all overloads, first argument is always an ENTITY object
  if (!_ACIS_check_ENTITY(input_arg1))
  {
    PyErr_SetString(PyExc_TypeError, "First argument must be an ENTITY object");
    return NULL;
  }

  API_BEGIN

            ENTITY *&_ent = (ENTITY *&) ((ACIS_Entity_ENTITY *) input_arg1)->_acis_obj;

            // Check if we are using the sweep along the axis overload
            if (input_arg5 != NULL)
            {
              if (!_ACIS_check_SPAposition(input_arg2))
              {
                PyErr_SetString(PyExc_TypeError, "Second argument must be a SPAposition object");
                return NULL;
              }

              if (!_ACIS_check_SPAvector(input_arg3))
              {
                PyErr_SetString(PyExc_TypeError, "Third argument must be a SPAvector object");
                return NULL;
              }

              if (!_ACIS_check_SweepOptions(input_arg4))
              {
                PyErr_SetString(PyExc_TypeError, "Fourth argument must be a sweep_options object");
                return NULL;
              }

              if (!_ACIS_check_BODY(input_arg5))
              {
                PyErr_SetString(PyExc_TypeError, "Fifth argument must be a BODY object");
                return NULL;
              }

              SPAposition *&_root = (SPAposition *&) ((ACIS_GeometricAtoms_SPAposition *) input_arg2)->_acis_obj;
              SPAvector *&_axis = (SPAvector *&) ((ACIS_GeometricAtoms_SPAvector *) input_arg3)->_acis_obj;
              sweep_options *&_opts = (sweep_options *&) ((ACIS_Sweeping_SweepOptions *) input_arg4)->_acis_obj;
              BODY *&_new_body = (BODY *&) ((ACIS_Entity_BODY *) input_arg5)->base_obj._acis_obj;

              // Call ACIS Sweeping API
              result = api_sweep_with_options(_ent, *_root, *_axis, _opts, _new_body);

            }
            else
            {
              // We must be using the other overloads, then the 3rd argument must be a sweep_options object
              if (!_ACIS_check_SweepOptions(input_arg3))
              {
                PyErr_SetString(PyExc_TypeError, "Third argument must be a sweep_options object");
                return NULL;
              }

              sweep_options *&_opts = (sweep_options *&) ((ACIS_Sweeping_SweepOptions *) input_arg3)->_acis_obj;

              // and the 4th argument must be a BODY object
              if (!_ACIS_check_BODY(input_arg4))
              {
                PyErr_SetString(PyExc_TypeError, "Fourth argument must be a BODY object");
                return NULL;
              }

              BODY *&_new_body = (BODY *&) ((ACIS_Entity_BODY *) input_arg4)->base_obj._acis_obj;

              // Check for sweeping along a given edge or a wire overload
              if (_ACIS_check_ENTITY(input_arg2))
              {
                ENTITY *&_path = (ENTITY *&) ((ACIS_Entity_ENTITY *) input_arg2)->_acis_obj;

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, _path, _opts, _new_body);
              }
              else if (PyFloat_Check(input_arg2))
              {
                // We must be using sweeping along a specified distance overload
                double _distance = PyFloat_AsDouble(input_arg2);

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, _distance, _opts, _new_body);
              }
              else if (_ACIS_check_SPAvector(input_arg2))
              {
                // We must be using sweeping along a specified vector overload
                SPAvector *&_vec = (SPAvector *&) ((ACIS_GeometricAtoms_SPAvector *) input_arg2)->_acis_obj;

                // Call ACIS Sweeping API
                result = api_sweep_with_options(_ent, *_vec, _opts, _new_body);
              }
              else
              {
                PyErr_SetString(PyExc_TypeError, "Second argument must be an ENTITY, float or SPAvector object");
                return NULL;
              }

            }

  API_END

  // Check outcome
  if (!check_outcome(result))
  {
    // Returning NULL means that we have an error
    return NULL;
  }
  else
  {
    // Returning none means that we have no errors
    Py_RETURN_NONE;
  }
}

static PyMethodDef
  module_methods[] =
  {
    { "api_make_sweep_path", (PyCFunction) ACIS_api_make_sweep_path, METH_VARARGS | METH_KEYWORDS, "Constructs a path useful for creating a swept surface" },
    { "api_sweep_with_options", (PyCFunction) ACIS_api_sweep_with_options, METH_VARARGS | METH_KEYWORDS, "Sweeps the given profile along an edge, a distance, a vector or an axis" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "Sweeping";
const char *module_documentation = "Contains 3D ACIS Modeler sweeping API related classes and functions";

static struct PyModuleDef
  ACIS_Sweeping_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name, // name of the module
    module_documentation, // module documentation, may be NULL
    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    module_methods
  };

PyMODINIT_FUNC
PyInit_Sweeping(void)
{
  PyObject *m;

  m = PyModule_Create(&ACIS_Sweeping_module);
  if (m == NULL)
    return NULL;

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
  ACIS_Sweeping_type_SweepBoolType.tp_dict = _sbt_dict;
  if (PyType_Ready(&ACIS_Sweeping_type_SweepBoolType) < 0)
    return NULL;
  Py_INCREF(&ACIS_Sweeping_type_SweepBoolType);
  PyModule_AddObject(m, "sweep_bool_type", (PyObject *) &ACIS_Sweeping_type_SweepBoolType);

  // sweep_options
  if (PyType_Ready(&ACIS_Sweeping_type_SweepOptions) < 0)
    return NULL;
  Py_INCREF(&ACIS_Sweeping_type_SweepOptions);
  PyModule_AddObject(m, "sweep_options", (PyObject *) &ACIS_Sweeping_type_SweepOptions);

  // make_sweep_path_options
  if (PyType_Ready(&ACIS_Sweeping_type_SweepPathOptions) < 0)
    return NULL;
  Py_INCREF(&ACIS_Sweeping_type_SweepPathOptions);
  PyModule_AddObject(m, "make_sweep_path_options", (PyObject *) &ACIS_Sweeping_type_SweepPathOptions);

  return m;
}

PyObject *_ACIS_new_SweepBoolType()
{
  return PyObject_CallObject((PyObject *) &ACIS_Sweeping_type_SweepBoolType, NULL);
}

bool _ACIS_check_SweepBoolType(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Sweeping_type_SweepBoolType;
}

PyObject *_ACIS_new_SweepOptions()
{
  return PyObject_CallObject((PyObject *) &ACIS_Sweeping_type_SweepOptions, NULL);
}

bool _ACIS_check_SweepOptions(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Sweeping_type_SweepOptions;
}

PyObject *_ACIS_new_SweepPathOptions()
{
  return PyObject_CallObject((PyObject *) &ACIS_Sweeping_type_SweepPathOptions, NULL);
}

bool _ACIS_check_SweepPathOptions(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_Sweeping_type_SweepPathOptions;
}
