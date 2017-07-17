#include "utilities.h"


bool
check_outcome(outcome &_retval)
{
  // Check if the ACIS outcome is good
  if (!_retval.ok())
  {
    error_info *err_info = _retval.get_error_info();
    PyErr_SetString(PyExc_Exception, err_info->error_message());
    return false;
  }
  else
  {
    return true;
  }
}
