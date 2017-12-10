#include "acis_enums.h"


PyObject *_PyNew_NDBOOL_KEEP()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_NDBOOLKEEP, NULL);
}

bool _PyCheck_NDBOOL_KEEP(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_NDBOOLKEEP;
}

PyObject *_PyNew_sweep_bool_type()
{
  return PyObject_CallObject((PyObject *) &a3dp_type_sweepbooltype, NULL);
}

bool _PyCheck_sweep_bool_type(PyObject *ob)
{
  return Py_TYPE(ob) == &a3dp_type_sweepbooltype;
}
