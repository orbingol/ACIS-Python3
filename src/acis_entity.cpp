#include "acis_entity.h"


/**
 * ENTITY class
 */

int
a3dp_ENTITY_traverse(a3dp_ENTITY *self, visitproc visit, void *arg)
{
  // Use Py_VISIT macro for PyObject-type variables
  Py_VISIT(self->attrib_name);
  Py_VISIT(self->attrib_object_id);

  return 0;
}

int
a3dp_ENTITY_clear(a3dp_ENTITY *self)
{
  // Set ACIS object to NULL to allow it automatically deleted by ACIS memory manager
  //self->_acis_obj = NULL;

  // Use Py_CLEAR macro for PyObject variables
  Py_CLEAR(self->attrib_name);
  Py_CLEAR(self->attrib_object_id);

  return 0;
}

void
a3dp_ENTITY_dealloc(a3dp_ENTITY *self)
{
  a3dp_ENTITY_clear(self);
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
a3dp_ENTITY_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  // First check if the modeler has been started
  if (!is_modeler_started())
  {
    PyErr_SetString(PyExc_RuntimeError, "ACIS is not running!");
    return NULL;
  }

  a3dp_ENTITY *self;

  self = (a3dp_ENTITY *) type->tp_alloc(type, 0);
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
a3dp_ENTITY_init(a3dp_ENTITY *self, PyObject *args, PyObject *kwargs)
{
//  PyObject *input_name = NULL;
//  PyObject *input_id = NULL;
//  PyObject *tmp;
//
//  char *kwlist[] =
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
a3dp_ENTITY_repr(a3dp_ENTITY *self)
{
  const char *_name = PyUnicode_AsUTF8(self->attrib_name);
  int _id = (int) PyLong_AsLong(self->attrib_object_id);
  return PyUnicode_FromFormat("ENTITY object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_ENTITY_str(a3dp_ENTITY *self)
{
  const char *acis_obj_status = NULL;
  if (self->_acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("ENTITY object (%s)", acis_obj_status);
}

PyObject *
a3dp_ENTITY_get_attrib_name(a3dp_ENTITY *self, PyObject *value, void *closure)
{
  Py_INCREF(self->attrib_name);
  return self->attrib_name;
}

int
a3dp_ENTITY_set_attrib_name(a3dp_ENTITY *self, PyObject *value, void *closure)
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
a3dp_ENTITY_type_name(PyObject *self)
{
	const char *_retval = ((a3dp_ENTITY *)self)->_acis_obj->type_name();
	return PyUnicode_FromString(_retval);
}

PyObject *
a3dp_ENTITY_get_attrib_obj_id(a3dp_ENTITY *self, PyObject *value, void *closure)
{
  Py_INCREF(self->attrib_object_id);
  return self->attrib_object_id;
}

int
a3dp_ENTITY_set_attrib_obj_id(a3dp_ENTITY *self, PyObject *value, void *closure)
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
 * BODY class
 */

int
a3dp_BODY_init(a3dp_BODY *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_BODY_repr(a3dp_BODY *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("BODY object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_BODY_str(a3dp_BODY *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("BODY object (%s)", acis_obj_status);
}


/**
 * FACE class
 */

int
a3dp_FACE_init(a3dp_FACE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_FACE_repr(a3dp_FACE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("FACE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_FACE_str(a3dp_FACE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("FACE object (%s)", acis_obj_status);
}

PyObject *
a3dp_FACE__sense(a3dp_FACE *self)
{
  logical _revbit;
  _revbit = ((FACE *) self->base_obj._acis_obj)->sense();

  // If REVBIT is true or reversed, the directions are opposite (reversed)
  if (_revbit)
    Py_RETURN_TRUE;
  // If REVBIT is false or forward, the directions are the same
  Py_RETURN_FALSE;
}

PyObject *
a3dp_FACE__geometry(a3dp_FACE *self)
{
  PyObject *_retobj = _PyNew_SURFACE();
  // Store everything as ENTITY
  ((a3dp_SURFACE *) _retobj)->base_obj._acis_obj = (ENTITY *) ((FACE *) self->base_obj._acis_obj)->geometry();
  return _retobj;
}


/**
 * EDGE class
 */

int
a3dp_EDGE_init(a3dp_EDGE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_EDGE_repr(a3dp_EDGE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("EDGE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_EDGE_str(a3dp_EDGE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("EDGE object (%s)", acis_obj_status);
}


/**
 * WIRE class
 */

int
a3dp_WIRE_init(a3dp_WIRE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_WIRE_repr(a3dp_WIRE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("WIRE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_WIRE_str(a3dp_WIRE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("WIRE object (%s)", acis_obj_status);
}

/**
 * LUMP class
 */

int
a3dp_LUMP_init(a3dp_LUMP *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_LUMP_repr(a3dp_LUMP *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("LUMP object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_LUMP_str(a3dp_LUMP *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("LUMP object (%s)", acis_obj_status);
}

/**
 * SHELL class
 */

int
a3dp_SHELL_init(a3dp_SHELL *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_SHELL_repr(a3dp_SHELL *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("SHELL object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_SHELL_str(a3dp_SHELL *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("SHELL object (%s)", acis_obj_status);
}

/**
 * SUBSHELL class
 */

int
a3dp_SUBSHELL_init(a3dp_SUBSHELL *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_SUBSHELL_repr(a3dp_SUBSHELL *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("SUBSHELL object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_SUBSHELL_str(a3dp_SUBSHELL *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("SUBSHELL object (%s)", acis_obj_status);
}

/**
 * COEDGE class
 */

int
a3dp_COEDGE_init(a3dp_COEDGE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_COEDGE_repr(a3dp_COEDGE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("COEDGE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_COEDGE_str(a3dp_COEDGE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("COEDGE object (%s)", acis_obj_status);
}


/**
 * LOOP class
 */

int
a3dp_LOOP_init(a3dp_LOOP *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_LOOP_repr(a3dp_LOOP *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("LOOP object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_LOOP_str(a3dp_LOOP *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("LOOP object (%s)", acis_obj_status);
}

/**
 * VERTEX class
 */

int
a3dp_VERTEX_init(a3dp_VERTEX *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_VERTEX_repr(a3dp_VERTEX *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("VERTEX object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_VERTEX_str(a3dp_VERTEX *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("VERTEX object (%s)", acis_obj_status);
}

/**
 * SURFACE class
 */

int
a3dp_SURFACE_init(a3dp_SURFACE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_SURFACE_repr(a3dp_SURFACE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("SURFACE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_SURFACE_str(a3dp_SURFACE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("SURFACE object (%s)", acis_obj_status);
}

PyObject *
a3dp_SURFACE__equation(a3dp_SURFACE *self)
{
  PyObject *_retobj = _PyNew_surface();
  *((a3dp_surface *) _retobj)->_acis_obj = ((SURFACE *)(self->base_obj._acis_obj))->equation();
  return _retobj;
}

PyObject *
a3dp_SURFACE__trans_surface(a3dp_SURFACE *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_t = NULL, *input_reverse = NULL;

  // List of keyword arguments that this function can take
  char *kwlist[] =
    {
      (char *) "t",
      (char *) "reverse",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|Oi", kwlist, &input_t, &input_reverse))
    return NULL;

  SPAtransf _t = *(SPAtransf *) NULL_REF;
  if (input_t != NULL)
  {
    // Validate input
    if (!_PyCheck_SPAtransf(input_t))
    {
      PyErr_SetString(PyExc_TypeError, "The first argument (t) must be a SPAtransf object");
      return NULL;
    }

    _t = *((a3dp_SPAtransf *) input_t)->_acis_obj;
  }

  logical _reverse = FALSE;
  if (input_reverse != NULL)
  {
    long _py_inp_reverse = PyLong_AsLong(input_reverse);
    _reverse = (_py_inp_reverse == 0) ? FALSE : TRUE;
  }

  PyObject *_retobj = _PyNew_surface();
  ((a3dp_surface *) _retobj)->_acis_obj = ((SURFACE *)(self->base_obj._acis_obj))->trans_surface(_t, _reverse);
  return _retobj;
}

/**
 * CONE class
 */

int
a3dp_CONE_init(a3dp_CONE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_CONE_repr(a3dp_CONE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("CONE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_CONE_str(a3dp_CONE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("CONE object (%s)", acis_obj_status);
}

/**
 * PLANE class
 */

int
a3dp_PLANE_init(a3dp_PLANE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_PLANE_repr(a3dp_PLANE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("PLANE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_PLANE_str(a3dp_PLANE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("PLANE object (%s)", acis_obj_status);
}

/**
 * SPHERE class
 */

int
a3dp_SPHERE_init(a3dp_SPHERE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_SPHERE_repr(a3dp_SPHERE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("SPHERE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_SPHERE_str(a3dp_SPHERE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("SPHERE object (%s)", acis_obj_status);
}

/**
 * SPLINE class
 */

int
a3dp_SPLINE_init(a3dp_SPLINE *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_SPLINE_repr(a3dp_SPLINE *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("SPLINE object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_SPLINE_str(a3dp_SPLINE *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("SPLINE object (%s)", acis_obj_status);
}

/**
 * TORUS class
 */

int
a3dp_TORUS_init(a3dp_TORUS *self, PyObject *args, PyObject *kwargs)
{
  // Initialize the base class
  if (a3dp_type_ENTITY.tp_init((PyObject *) self, args, kwargs) < 0)
    return -1;

  return 0;
}

PyObject *
a3dp_TORUS_repr(a3dp_TORUS *self)
{
  const char *_name = PyUnicode_AsUTF8(self->base_obj.attrib_name);
  int _id = (int) PyLong_AsLong(self->base_obj.attrib_object_id);
  return PyUnicode_FromFormat("TORUS object with name '%s' and ID '%i'", _name, _id);
}

PyObject *
a3dp_TORUS_str(a3dp_TORUS *self)
{
  const char *acis_obj_status = NULL;
  if (self->base_obj._acis_obj == NULL)
    acis_obj_status = "Empty";
  else
    acis_obj_status = "Valid";

  return PyUnicode_FromFormat("TORUS object (%s)", acis_obj_status);
}

/**
 * surface class
 */

void
a3dp_surface_dealloc(a3dp_surface *self)
{
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
a3dp_surface_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  // First check if the modeler has been started
  if (!is_modeler_started())
  {
    PyErr_SetString(PyExc_RuntimeError, "ACIS is not running!");
    return NULL;
  }

  a3dp_surface *self;

  self = (a3dp_surface *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

int
a3dp_surface_init(a3dp_surface *self, PyObject *args, PyObject *kwargs)
{
  return 0;
}

PyObject *
a3dp_surface__eval_normal(a3dp_surface *self, PyObject *arg)
{
  if (!_PyCheck_SPApar_pos(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPApar_pos object");
    return NULL;
  }

  Py_INCREF(arg);

  SPApar_pos *&_pos = ((a3dp_SPApar_pos *) arg)->_acis_obj;

  SPAunit_vector _retval = self->_acis_obj->eval_normal(*_pos);

  PyObject *_retobj = _PyNew_SPAunit_vector();
  *((a3dp_SPAunit_vector *) _retobj)->_acis_obj = _retval;

  Py_DECREF(arg);

  return _retobj;
}

PyObject *
a3dp_surface__eval_position(a3dp_surface *self, PyObject *arg)
{
  if (!_PyCheck_SPApar_pos(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting a SPApar_pos object");
    return NULL;
  }

  Py_INCREF(arg);

  SPApar_pos *&_pos = ((a3dp_SPApar_pos *) arg)->_acis_obj;

  SPAposition _retval = self->_acis_obj->eval_position(*_pos);

  PyObject *_retobj = _PyNew_SPAposition();
  *((a3dp_SPAposition *) _retobj)->_acis_obj = _retval;

  Py_DECREF(arg);

  return _retobj;
}

PyObject *_PyNew_ENTITY()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_ENTITY, NULL);
}

bool _PyCheck_ENTITY(PyObject *ob)
{
  int retval = PyObject_IsInstance(ob, (PyObject *) &a3dp_type_ENTITY);
  if (retval < 0)
  {
    PyErr_SetString(PyExc_TypeError, "Problem with ENTITY type cheking");
    return false;
  }
  return retval != 0;
}

PyObject *_PyNew_BODY()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_BODY, NULL);
}

bool _PyCheck_BODY(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_BODY;
}

PyObject *_PyNew_FACE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_FACE, NULL);
}

bool _PyCheck_FACE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_FACE;
}

PyObject *_PyNew_EDGE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_EDGE, NULL);
}

bool _PyCheck_EDGE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_EDGE;
}

PyObject *_PyNew_WIRE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_WIRE, NULL);
}

bool _PyCheck_WIRE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_WIRE;
}

PyObject *_PyNew_LUMP()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_LUMP, NULL);
}

bool _PyCheck_LUMP(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_LUMP;
}

PyObject *_PyNew_SHELL()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SHELL, NULL);
}

bool _PyCheck_SHELL(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SHELL;
}

PyObject *_PyNew_SUBSHELL()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SUBSHELL, NULL);
}

bool _PyCheck_SUBSHELL(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SUBSHELL;
}

PyObject *_PyNew_COEDGE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_COEDGE, NULL);
}

bool _PyCheck_COEDGE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_COEDGE;
}

PyObject *_PyNew_LOOP()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_LOOP, NULL);
}

bool _PyCheck_LOOP(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_LOOP;
}

PyObject *_PyNew_VERTEX()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_VERTEX, NULL);
}

bool _PyCheck_VERTEX(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_VERTEX;
}

PyObject *_PyNew_SURFACE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SURFACE, NULL);
}

bool _PyCheck_SURFACE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SURFACE;
}

PyObject *_PyNew_CONE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_CONE, NULL);
}

bool _PyCheck_CONE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_CONE;
}

PyObject *_PyNew_PLANE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_PLANE, NULL);
}

bool _PyCheck_PLANE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_PLANE;
}

PyObject *_PyNew_SPHERE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPHERE, NULL);
}

bool _PyCheck_SPHERE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPHERE;
}

PyObject *_PyNew_SPLINE()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_SPLINE, NULL);
}

bool _PyCheck_SPLINE(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_SPLINE;
}

PyObject *_PyNew_TORUS()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_TORUS, NULL);
}

bool _PyCheck_TORUS(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_TORUS;
}

PyObject *_PyNew_surface()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_surface, NULL);
}

bool _PyCheck_surface(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_surface;
}

void _a3dp_make_null(PyObject *ob)
{
  if (_PyCheck_ENTITY(ob))
  {
    ((a3dp_ENTITY *) ob)->_acis_obj = NULL;
  }
}

void _a3dp_set_entity(PyObject *ob, ENTITY *ent)
{
	((a3dp_ENTITY *)ob)->_acis_obj = ent;
}

/**
 * ENTITY_LIST class
 */

void
a3dp_ENTITYLIST_dealloc(a3dp_ENTITY_LIST *self)
{
  // First, clear the contents of the ENTITY_LIST instance
  self->_acis_obj->clear();

  // Use ACIS_DELETE macro for ENTITY_LIST
  ACIS_DELETE self->_acis_obj;

  // Delete the python object itself
  Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
a3dp_ENTITYLIST_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  a3dp_ENTITY_LIST *self;

  self = (a3dp_ENTITY_LIST *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

int
a3dp_ENTITYLIST_init(a3dp_ENTITY_LIST *self)
{
  // ENTITY_LIST takes no arguments, so parsing is necessary
  self->_acis_obj = ACIS_NEW ENTITY_LIST();
  return 0;
}

PyObject *
a3dp_ENTITYLIST__init(a3dp_ENTITY_LIST *self)
{
  self->_acis_obj->init();
  Py_RETURN_NONE;
}

PyObject *
a3dp_ENTITYLIST__clear(a3dp_ENTITY_LIST *self)
{
  self->_acis_obj->clear();
  Py_RETURN_NONE;
}

PyObject *
a3dp_ENTITYLIST__add(a3dp_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  int index = -1;

  if (!_PyCheck_ENTITY(arg))
  {
    if (!_PyCheck_ENTITY_LIST(arg))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY or ENTITY_LIST object");
      return NULL;
    }
    else
    {
      // This function returns void
      self->_acis_obj->add(*((a3dp_ENTITY_LIST *) arg)->_acis_obj);
    }
  }
  else
  {
    // This function returns the added ENTITY's index number
    index = self->_acis_obj->add(((a3dp_ENTITY *) arg)->_acis_obj);
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

PyObject *
a3dp_ENTITYLIST__remove(a3dp_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  int index = -1;

  if (!_PyCheck_ENTITY(arg))
  {
    if (!_PyCheck_ENTITY_LIST(arg))
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
      self->_acis_obj->remove(*((a3dp_ENTITY_LIST *) arg)->_acis_obj);
    }
  }
  else
  {
    // This function returns the removed ENTITY's index number
    index = self->_acis_obj->remove(((a3dp_ENTITY *) arg)->_acis_obj);
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

PyObject *
a3dp_ENTITYLIST__count(a3dp_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->count());
}

PyObject *
a3dp_ENTITYLIST__iteration_count(a3dp_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->iteration_count());
}

PyObject *
a3dp_ENTITYLIST__reverse(a3dp_ENTITY_LIST *self)
{
  self->_acis_obj->reverse();
  Py_RETURN_NONE;
}

PyObject *
a3dp_ENTITYLIST__lookup(a3dp_ENTITY_LIST *self, PyObject *arg)
{
  // Treat arg as a borrowed reference
  Py_INCREF(arg);

  if (!_PyCheck_ENTITY(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting an ENTITY object");
    return NULL;
  }

  int index = self->_acis_obj->lookup(((a3dp_ENTITY *) arg)->_acis_obj);

  // Treat arg as a borrowed reference
  Py_DECREF(arg);

  // Prepare return values
  return PyLong_FromLong(index);
}

PyObject *
a3dp_ENTITYLIST__byte_count(a3dp_ENTITY_LIST *self)
{
  return PyLong_FromLong(self->_acis_obj->byte_count());
}

PyObject *
a3dp_ENTITYLIST__first(a3dp_ENTITY_LIST *self)
{
  ENTITY *_elem = self->_acis_obj->first();
  PyObject *retobj = __convert_entity(_elem);
  return retobj;
}

PyObject *
a3dp_ENTITYLIST__next(a3dp_ENTITY_LIST *self)
{
  PyObject *retobj;
  ENTITY *_elem = self->_acis_obj->next();

  if (_elem)
  {
    retobj = __convert_entity(_elem);
  }
  else
  {
    // This is a requirement for iterator/generator to stop. Otherwise, you will observe an infinite loop.
    PyErr_SetNone(PyExc_StopIteration);
    return NULL;
  }

  return retobj;
}

PyObject *
a3dp_ENTITYLIST__next_from(a3dp_ENTITY_LIST *self, PyObject *arg)
{
  if (!PyLong_Check(arg))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting an integer object");
    return NULL;
  }

  Py_INCREF(arg);
  int _from_index = (int) PyLong_AsLong(arg);
  Py_DECREF(arg);

  PyObject *retobj;
  ENTITY *_elem = self->_acis_obj->next_from(_from_index);

  if (_elem)
  {
    retobj = __convert_entity(_elem);
  }
  else
  {
    // This is a requirement for iterator/generator to stop. Otherwise, you will observe an infinite loop.
    PyErr_SetNone(PyExc_StopIteration);
    return NULL;
  }

  return retobj;
}

PyObject *
a3dp_ENTITYLIST__array(a3dp_ENTITY_LIST *self)
{
  /* This function will create a Python generator/iterator */

  // Reference increment is necessary, otherwise this ENTITY_LIST will be garbage collected
  Py_INCREF(self);

  // Iterator/Generator creation functions always return self!
  return (PyObject *) self;
}

PyObject *
a3dp_ENTITYLIST_iter(PyObject *self)
{
  /* Must have the same signature as PyObject_GetIter() */

  // Move the ENTITY_LIST pointer to the beginning
  a3dp_ENTITYLIST__init((a3dp_ENTITY_LIST *) self);

  Py_INCREF(self);
  return self;
}

PyObject *
a3dp_ENTITYLIST_iter_next(PyObject *self)
{
  /* Must have the same signature as PyIter_Next() */

  // Convert the input argument to a ENTITY_LIST object
  a3dp_ENTITY_LIST *_ent_list = (a3dp_ENTITY_LIST *) self;

  // Return the next element
  return a3dp_ENTITYLIST__next(_ent_list);
}


PyObject *
_PyNew_ENTITY_LIST()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_ENTITYLIST, NULL);
}

bool
_PyCheck_ENTITY_LIST(PyObject *ob)
{
  if (Py_TYPE(ob) == &a3dp_type_ENTITYLIST)
    return true;
  else
    return false;
}

PyObject *
__convert_entity(ENTITY *ent)
{
  // Find the type name of the entity
  const char *_type_name = ent->type_name();

  // We could use a hashing function here...
  PyObject *_retobj;
  if (strcmp("body", _type_name) == 0)
  {
    _retobj = _PyNew_BODY();
    _a3dp_set_entity(_retobj, ent);
  }
  else if (strcmp("face", _type_name) == 0)
  {
    _retobj = _PyNew_FACE();
    _a3dp_set_entity(_retobj, ent);
  }
  else if (strcmp("surface", _type_name) == 0)
  {
    _retobj = _PyNew_SURFACE();
    _a3dp_set_entity(_retobj, ent);
  }

  return _retobj;
}
