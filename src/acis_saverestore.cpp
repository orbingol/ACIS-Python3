#include "acis_saverestore.h"


/**
 * Save & Restore - FileInfo wrapper
 */

static void
ACIS_SaveRestore_dealloc_FileInfo(ACIS_SaveRestore_FileInfo *self)
{
  // Delete ACIS object
  ACIS_DELETE self->_acis_obj;

  // Delete the python object itself
  Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ACIS_SaveRestore_new_FileInfo(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
  ACIS_SaveRestore_FileInfo *self;

  self = (ACIS_SaveRestore_FileInfo *) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    // Just getting rid of the dangling pointer
    self->_acis_obj = NULL;
  }

  return (PyObject *) self;
}

static int
ACIS_SaveRestore_init_FileInfo(ACIS_SaveRestore_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  self->_acis_obj = ACIS_NEW FileInfo();
  return 0;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_acis_version(ACIS_SaveRestore_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->acis_version());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_date(ACIS_SaveRestore_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->date());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_file_version(ACIS_SaveRestore_FileInfo *self)
{
  return PyLong_FromLong((long) self->_acis_obj->file_version());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_product_id(ACIS_SaveRestore_FileInfo *self)
{
  return PyUnicode_FromString(self->_acis_obj->product_id());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_reset(ACIS_SaveRestore_FileInfo *self)
{
  self->_acis_obj->reset();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_reset_vars(ACIS_SaveRestore_FileInfo *self)
{
  self->_acis_obj->reset_vars();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_restore(ACIS_SaveRestore_FileInfo *self)
{
  self->_acis_obj->restore();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_save(ACIS_SaveRestore_FileInfo *self)
{
  self->_acis_obj->save();
  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_set_masked(ACIS_SaveRestore_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  unsigned long input_field;
  PyObject *input_file = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "field",
      (char *) "file",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "lO", kwlist, &input_field, &input_file))
    return NULL;

  // Check if the user input is a FileInfo object
  if (_ACIS_check_FileInfo(input_file))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  // Convert PyObject to ENTITY_LIST
  FileInfo *_file = ((ACIS_SaveRestore_FileInfo *) input_file)->_acis_obj;

  // Execute ACIS function
  self->_acis_obj->set_masked(input_field, *_file);

  // Return None
  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_set_product_id(ACIS_SaveRestore_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  const char *input_id = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "id",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s", kwlist, &input_id))
    return NULL;

  self->_acis_obj->set_product_id(input_id);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_set_units(ACIS_SaveRestore_FileInfo *self, PyObject *args, PyObject *kwargs)
{
  double input_count;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "count",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "d", kwlist, &input_count))
    return NULL;

  self->_acis_obj->set_units(input_count);

  Py_RETURN_NONE;
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_tol_abs(ACIS_SaveRestore_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_abs());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_tol_nor(ACIS_SaveRestore_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->tol_nor());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_units(ACIS_SaveRestore_FileInfo *self)
{
  return PyFloat_FromDouble(self->_acis_obj->units());
}

static PyObject *
ACIS_SaveRestore_method_FileInfo_valid(ACIS_SaveRestore_FileInfo *self)
{
  self->_acis_obj->valid();
  Py_RETURN_NONE;
}

static PyMemberDef
  ACIS_SaveRestore_members_FileInfo[] =
  {
    { NULL }  /* Sentinel */
  };

static PyMethodDef
  ACIS_SaveRestore_methods_FileInfo[] =
  {
    { "acis_version", (PyCFunction) ACIS_SaveRestore_method_FileInfo_acis_version, METH_NOARGS, "Returns the ACIS version number used to save the model" },
    { "date", (PyCFunction) ACIS_SaveRestore_method_FileInfo_date, METH_NOARGS, "Returns the date on the save file" },
    { "file_version", (PyCFunction) ACIS_SaveRestore_method_FileInfo_file_version, METH_NOARGS, "Returns the save file version used in storing the file" },
    { "product_id", (PyCFunction) ACIS_SaveRestore_method_FileInfo_product_id, METH_NOARGS, "Returns the ID of the product" },
    { "reset", (PyCFunction) ACIS_SaveRestore_method_FileInfo_reset, METH_NOARGS, "Resets the values to the default settings for the file information" },
    { "reset_vars", (PyCFunction) ACIS_SaveRestore_method_FileInfo_reset_vars, METH_NOARGS, "Routine to reset the values for the file information to the default values" },
    { "restore", (PyCFunction) ACIS_SaveRestore_method_FileInfo_restore, METH_NOARGS, "Restores the file information from a save file" },
    { "save", (PyCFunction) ACIS_SaveRestore_method_FileInfo_save, METH_NOARGS, "Saves the product ID, version, time, units, SPAresabs and SPAresnor" },
    //{ "set_masked", (PyCFunction)ACIS_SaveRestore_method_FileInfo_set_masked,  METH_VARARGS | METH_KEYWORDS, "Copies selected fields from another instance" },
    { "set_product_id", (PyCFunction) ACIS_SaveRestore_method_FileInfo_set_product_id, METH_VARARGS | METH_KEYWORDS, "Sets the product ID" },
    { "set_units", (PyCFunction) ACIS_SaveRestore_method_FileInfo_set_units, METH_VARARGS | METH_KEYWORDS, "Sets the model units scale (in millimeters)" },
    { "tol_abs", (PyCFunction) ACIS_SaveRestore_method_FileInfo_tol_abs, METH_NOARGS, "Returns the value of the SPAresabs when the model was saved" },
    { "tol_nor", (PyCFunction) ACIS_SaveRestore_method_FileInfo_tol_nor, METH_NOARGS, "Returns the value of the SPAresnor when the model was saved" },
    { "units", (PyCFunction) ACIS_SaveRestore_method_FileInfo_units, METH_NOARGS, "Returns the value of the millimeters per model unit" },
    { "valid", (PyCFunction) ACIS_SaveRestore_method_FileInfo_valid, METH_NOARGS, "Checks the values of the units and product id" },
    { NULL }  /* Sentinel */
  };

static PyTypeObject
  ACIS_SaveRestore_type_FileInfo =
  {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ACIS.FileInfo",             /* tp_name */
    sizeof(ACIS_SaveRestore_FileInfo), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) ACIS_SaveRestore_dealloc_FileInfo, /* tp_dealloc */
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
    "FileInfo object contains additional required save file header information", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    ACIS_SaveRestore_methods_FileInfo, /* tp_methods */
    ACIS_SaveRestore_members_FileInfo, /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) ACIS_SaveRestore_init_FileInfo, /* tp_init */
    0,                         /* tp_alloc */
    ACIS_SaveRestore_new_FileInfo, /* tp_new */
  };


/**
 * Save & Restore Interface Functions
 */

static PyObject *
ACIS_api_save_entity_list(PyObject *self, PyObject *args, PyObject *kwargs)
{
  // According to the documentation, Python 3 doesn't do good with FILE* objects, so we take "file name" as an input
  const char *input_filename = NULL;
  int input_savemode;
  PyObject *input_entitylist = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "file_name",
      (char *) "text_mode",
      (char *) "entity_list_save",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "siO", kwlist, &input_filename, &input_savemode, &input_entitylist))
    return NULL;

  // Check if the input is an ENTITY_LIST
  if (!_ACIS_check_ENTITY_LIST(input_entitylist))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting ENTITY_LIST object");
    return NULL;
  }

  // Using the file name input as a string, create a file handle
  FILE *_file_handle = fopen(input_filename, "w");

  // Check if the file has been opened correctly
  if (_file_handle == NULL)
  {
    PyErr_SetString(PyExc_IOError, "Cannot open file for writing!");
    return NULL;
  }

  // Set file writing mode
  logical _text_mode = (input_savemode == 0) ? FALSE : TRUE;

  API_NOP_BEGIN

            // Convert PyObject to ENTITY_LIST
            ENTITY_LIST *_save_list = ((ACIS_Lists_ENTITY_LIST *) input_entitylist)->_acis_obj;


            // Call ACIS API and check outcome
            result = api_save_entity_list(_file_handle, _text_mode, *_save_list);

  API_NOP_END

  // Don't forget to close the file handle
  fclose(_file_handle);

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_set_file_info(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_product_id = 0;
  int input_units = 0;
  PyObject *input_info = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "info",
      (char *) "product_id",
      (char *) "units",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|ii", kwlist, &input_info, &input_product_id, &input_units))
    return NULL;

  // Check if we have a FileInfo object
  if (!_ACIS_check_FileInfo(input_info))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  // Set up the value of mask
  bool _product_id = input_product_id != 0;
  bool _units = input_units != 0;

  unsigned long _mask;
  if (_product_id && !_units)
  {
    _mask = FileIdent;
  }
  else if (!_product_id && _units)
  {
    _mask = FileUnits;
  }
  else
  {
    _mask = FileUnits | FileIdent;
  }

  API_BEGIN

            // Convert PyObject to FileInfo
            FileInfo *_info = ((ACIS_SaveRestore_FileInfo *) input_info)->_acis_obj;

            result = api_set_file_info(_mask, *_info);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_get_file_info(PyObject *self, PyObject *args, PyObject *kwargs)
{
  PyObject *input_info = NULL;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "info",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &input_info))
    return NULL;

  // Check if we have a FileInfo object
  if (_ACIS_check_FileInfo(input_info))
  {
    PyErr_SetString(PyExc_TypeError, "Expecting FileInfo object");
    return NULL;
  }

  API_BEGIN

            // Convert PyObject to FileInfo
            FileInfo *_info = ((ACIS_SaveRestore_FileInfo *) input_info)->_acis_obj;

            result = api_get_file_info(*_info);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}

static PyObject *
ACIS_api_save_version(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int input_major_version, input_minor_version;

  // List of keyword arguments that this function can take
  static char *kwlist[] =
    {
      (char *) "major_version",
      (char *) "minor_version",
      NULL
    };

  // Try to parse input arguments and/or keywords
  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii", kwlist, &input_major_version, &input_minor_version))
    return NULL;

  API_BEGIN

            result = api_save_version(input_major_version, input_minor_version);

  API_END

  // Check outcome
  if (!check_outcome(result))
    return NULL;
  else
    Py_RETURN_NONE;
}


static PyMethodDef
  module_methods[] =
  {
    { "api_save_entity_list", (PyCFunction) ACIS_api_save_entity_list, METH_VARARGS | METH_KEYWORDS, "Writes entities to a file in text or binary format" },
    { "api_set_file_info", (PyCFunction) ACIS_api_set_file_info, METH_VARARGS | METH_KEYWORDS, "Sets required header info to be written to ACIS save files" },
    { "api_get_file_info", (PyCFunction) ACIS_api_get_file_info, METH_O | METH_KEYWORDS, "Gets header info from the last restored file" },
    { "api_save_version", (PyCFunction) ACIS_api_save_version, METH_VARARGS | METH_KEYWORDS, "Sets the save file format" },
    { NULL, NULL, 0, NULL }
  };

// Module documentation can be accessible via __doc__
const char *module_name = "SaveRestore";
const char *module_documentation = "Contains 3D ACIS Modeler save & restore related classes and functions";

static PyModuleDef
  ACIS_SaveRestore_module =
  {
    PyModuleDef_HEAD_INIT,
    module_name,
    module_documentation,
    -1,
    module_methods
  };

PyMODINIT_FUNC
PyInit_SaveRestore(void)
{
  PyObject *m;
  m = PyModule_Create(&ACIS_SaveRestore_module);
  if (m == NULL)
    return NULL;

  if (PyType_Ready(&ACIS_SaveRestore_type_FileInfo) < 0)
    return NULL;

  Py_INCREF(&ACIS_SaveRestore_type_FileInfo);
  PyModule_AddObject(m, "FileInfo", (PyObject *) &ACIS_SaveRestore_type_FileInfo);

  return m;
}

bool _ACIS_check_FileInfo(PyObject *ob)
{
  return Py_TYPE(ob) == &ACIS_SaveRestore_type_FileInfo;
}
