#include "acis_lists.h"


/**
 * 3D ACIS Modeler - ENTITY_LIST wrapper
 */

static void
ACIS_Lists_dealloc_ENTITY_LIST(ACIS_Lists_ENTITY_LIST *self)
{
  // First, clear the contents of the ENTITY_LIST instance
  self->_acis_obj->clear();

  // Use ACIS_DELETE macro for ENTITY_LIST
  ACIS_DELETE self->_acis_obj;

  // Delete the python object itself
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_Lists_new_ENTITY_LIST(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_Lists_ENTITY_LIST *self;

  self = (ACIS_Lists_ENTITY_LIST *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_Lists_init_ENTITY_LIST(ACIS_Lists_ENTITY_LIST *self)
{
  // ENTITY_LIST takes no arguments, so parsing is necessary
  self->_acis_obj = ACIS_NEW ENTITY_LIST();
  return 0;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_init(ACIS_Lists_ENTITY_LIST *self)
{
  self->_acis_obj->init();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_clear(ACIS_Lists_ENTITY_LIST *self)
{
  self->_acis_obj->clear();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_add(ACIS_Lists_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  int index = -1;

  if (!_ACIS_check_ENTITY(arg))
  {
    if (!_ACIS_check_ENTITY_LIST(arg))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY or ENTITY_LIST object");
      return NULL;
    }
    else
    {
      // This function returns void
      self->_acis_obj->add(*((ACIS_Lists_ENTITY_LIST *) arg)->_acis_obj);
    }
  }
  else
  {
    // This function returns the added ENTITY's index number
    index = self->_acis_obj->add(((ACIS_Topology_ENTITY *) arg)->_acis_obj);
  }

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Prepare return values
  if (index != -1)
  {
    return PyLong_FromLong(index);
  }
  else
  {
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_remove(ACIS_Lists_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  int index = -1;

  if (!_ACIS_check_ENTITY(arg))
  {
    if (!_ACIS_check_ENTITY_LIST(arg))
    {
      if (!PyLong_Check(arg))
      {
        PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY, an ENTITY_LIST or an integer object");
        return NULL;
      }
      else
      {
        // This function returns the index number
        index = self->_acis_obj->remove((int) PyLong_AsLong(arg));
      }
    }
    else
    {
      // This function returns void
      self->_acis_obj->remove(*((ACIS_Lists_ENTITY_LIST *) arg)->_acis_obj);
    }
  }
  else
  {
    // This function returns the removed ENTITY's index number
    index = self->_acis_obj->remove(((ACIS_Topology_ENTITY *) arg)->_acis_obj);
  }

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Prepare return values
  if (index != -1)
  {
    return PyLong_FromLong(index);
  }
  else
  {
    Py_RETURN_NONE;
  }
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_count(ACIS_Lists_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->count());
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_iteration_count(ACIS_Lists_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->iteration_count());
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_reverse(ACIS_Lists_ENTITY_LIST *self)
{
  self->_acis_obj->reverse();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_lookup(ACIS_Lists_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  if (!_ACIS_check_ENTITY(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY object");
    return NULL;
  }

  int index = self->_acis_obj->lookup(((ACIS_Topology_ENTITY *) arg)->_acis_obj);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Prepare return values
  return PyLong_FromLong(index);
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_byte_count(ACIS_Lists_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->byte_count());
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_first(ACIS_Lists_ENTITY_LIST *self)
{
  PyObject *retobj = _ACIS_new_ENTITY();
  ENTITY *_elem = self->_acis_obj->first();
  ((ACIS_Topology_ENTITY *) retobj)->_acis_obj = _elem;
  return retobj;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_next(ACIS_Lists_ENTITY_LIST *self)
{
  PyObject *retobj = _ACIS_new_ENTITY();
  ENTITY *_elem = self->_acis_obj->next();
  ((ACIS_Topology_ENTITY *) retobj)->_acis_obj = _elem;
  return retobj;
}

static PyObject *
ACIS_Lists_method_ENTITY_LIST_next_from(ACIS_Lists_ENTITY_LIST *self, PyObject *arg)
{
  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting an integer object");
    return NULL;
  }

  Py_INCREF(arg);
  int _from_index = (int) PyLong_AsLong(arg);

  PyObject *retobj = _ACIS_new_ENTITY();
  ENTITY *_elem = self->_acis_obj->next_from(_from_index);
  ((ACIS_Topology_ENTITY *) retobj)->_acis_obj = _elem;

  Py_DECREF(arg);

  return retobj;
}

/* TO-DO: Implement ENTITY_LIST::array as a Python iterator */

static PyGetSetDef
  ACIS_Lists_getseters_ENTITY_LIST[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMemberDef
  ACIS_Lists_members_ENTITY_LIST[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_Lists_methods_ENTITY_LIST[] =
  {
    { "add", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_add, METH_O, "Adds an entity or entities to the list" },
    { "remove", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_remove, METH_O, "Removes an entity or entities from the list" },
    { "count", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_count, METH_NOARGS, "Returns the number of entries in the list including the deleted ones (tombstones)" },
    { "iteration_count", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_iteration_count, METH_NOARGS, "Returns the number of live entities in the list not including deleted entries" },
    { "init", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_init, METH_NOARGS, "Adds an entity or entities to the list" },
    { "lookup", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_lookup, METH_O, "Adds an entity or entities to the list" },
    { "reverse", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_reverse, METH_NOARGS, "Adds an entity or entities to the list" },
    { "byte_count", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_byte_count, METH_NOARGS, "Returns the size in bytes of this class" },
    { "first", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_first, METH_NOARGS, "Initializes the iterator, which is used by the next method, to the beginning of the list" },
    { "next", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_next, METH_NOARGS, "Returns the next undeleted (live) entry" },
    { "next_from", (PyCFunction) ACIS_Lists_method_ENTITY_LIST_next_from, METH_O, "Returns the next non deleted entry after the index given without affecting the member variables used by init and next" },
    //{ "array", (PyCFunction)ACIS_Lists_method_ENTITY_LIST_array, METH_VARARGS | METH_KEYWORDS, "Gets an array of the entities in the list" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_Lists_type_ENTITY_LIST =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.ENTITY_LIST",        /* tp_name */
    sizeof(ACIS_Lists_ENTITY_LIST),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_Lists_dealloc_ENTITY_LIST,                         /* tp_dealloc */
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
    "ACIS ENTITY_LIST class",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_Lists_methods_ENTITY_LIST,             /* tp_methods */
    ACIS_Lists_members_ENTITY_LIST,             /* tp_members */
    ACIS_Lists_getseters_ENTITY_LIST,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_Lists_init_ENTITY_LIST,      /* tp_init */
    0,                         /* tp_alloc */
    ACIS_Lists_new_ENTITY_LIST,                 /* tp_new */
  };


/*
 * Python Module Definitions
 */

// Module documentation can be accessible via __doc__
const char *module_documentation = "Contains 3D ACIS Modeler lists and containers, such as ENTITY_LIST";

static PyModuleDef
  ACIS_Lists_module =
  {
    PyModuleDef_HEAD_INIT,
    "Lists",
    module_documentation,
    -1,
    NULL, NULL, NULL, NULL, NULL
  };

PyMODINIT_FUNC
PyInit_Lists(void)
{
  // Create a Python module, ACIS.Objects
  PyObject *m;
  m = PyModule_Create(&ACIS_Lists_module);
  if (m == NULL)
    return NULL;

  // Initialize ACIS ENTITY_LIST class as a Python type
  if (PyType_Ready(&ACIS_Lists_type_ENTITY_LIST) < 0)
    return NULL;

  // Increase the reference counter of the ENTITY_LIST type
  Py_INCREF(&ACIS_Lists_type_ENTITY_LIST);

  // Add ENTITY_LIST type to the Objects module
  PyModule_AddObject(m, "ENTITY_LIST", (PyObject *) &ACIS_Lists_type_ENTITY_LIST);

  // Return the module and all included objects
  return m;
}

PyObject *_ACIS_new_ENTITY_LIST()
{
  return PyObject_CallObject((PyObject *) &ACIS_Lists_type_ENTITY_LIST, NULL);
}

bool _ACIS_check_ENTITY_LIST(PyObject *ob)
{
  if (Py_TYPE(ob) == &ACIS_Lists_type_ENTITY_LIST)
    return true;
  else
    return false;
}
