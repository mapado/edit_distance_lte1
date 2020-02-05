#include <Python.h>
#include "_edit_distance_lte1.h"

/* Me thinks the second argument of PyArg_UnpackTuple() should be const.
 * Anyway I habitually pass a constant string.
 * A cast to placate the compiler. */
#define PYARGCFIX(x) (char*)(x)
#define INFINITE_DISTANCE 7

/**
 * Un-pack Python objects and call core function
 */
static long int
levenshtein_common(PyObject *args, const char *name)
{
  PyObject *arg1, *arg2;
  size_t len1, len2;

  if (!PyArg_UnpackTuple(args, PYARGCFIX(name), 2, 2, &arg1, &arg2))
    return -1;

  if (PyObject_TypeCheck(arg1, &PyUnicode_Type)
      && PyObject_TypeCheck(arg2, &PyUnicode_Type)) {

    Py_UNICODE *string1, *string2;
    len1 = PyUnicode_GET_SIZE(arg1);
    len2 = PyUnicode_GET_SIZE(arg2);
    string1 = PyUnicode_AS_UNICODE(arg1);
    string2 = PyUnicode_AS_UNICODE(arg2);
    {
      size_t d = lev_u_edit_distance(len1, string1, len2, string2);
      if (d == (size_t)(-1)) {
        PyErr_NoMemory();
        return -1;
      }
      return d;
    }
  }
  else {
    PyErr_Format(PyExc_TypeError, "%s expected two Unicodes", name);
    return -1;
  }
}


/**
 * Python entry point
 */
static PyObject*
distance_py(PyObject *self, PyObject *args)
{
  long int ldist;

  if ((ldist = levenshtein_common(args, "distance")) < 0)
    return NULL;

  return PyLong_FromLong((long)ldist);
}


/**
 * lev_u_edit_distance:
 * @len1: The length of @string1.
 * @string1: A sequence of Unicode characters of length @len1, may contain NUL
 *           characters.
 * @len2: The length of @string2.
 * @string2: A sequence of Unicode characters of length @len2, may contain NUL
 *           characters.
 *
 * Computes Levenshtein edit distance of two Unicode strings.
 *
 * Returns: The edit distance.
 **/
static size_t
lev_u_edit_distance(size_t len1, const Py_UNICODE *string1,
                    size_t len2, const Py_UNICODE *string2)
{
  /* strip common prefix */
  while (len1 > 0 && len2 > 0 && *string1 == *string2) {
    len1--;
    len2--;
    string1++;
    string2++;
  }

  /* strip common suffix */
  while (len1 > 0 && len2 > 0 && string1[len1-1] == string2[len2-1]) {
    len1--;
    len2--;
  }

  if (len1 > 1 || len2 > 1) {
    return INFINITE_DISTANCE;
  }

  if (len1 == 1 || len2 == 1) {
    return 1;
  }

  return 0;
}


/******************************
*     Python module set-up    *
******************************/

static PyMethodDef methods[] = {
  { "distance", distance_py, METH_VARARGS, "Compute LTE-1 edit distance" },
  { NULL, NULL, 0, NULL },
};


static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "_edit_distance_lte1",
    NULL,
    -1,
    methods
};


PyMODINIT_FUNC
PyInit__edit_distance_lte1(void)
{
    return PyModule_Create(&module);
}
