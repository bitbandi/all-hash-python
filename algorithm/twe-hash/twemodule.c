#include <Python.h>

#include "twe.h"

static PyObject *twe_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    twe_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    twe_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef tweMethods[] = {
    { "getPoWHash", twe_getpowhash, METH_VARARGS, "Returns the proof of work hash using twe hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef tweModule = {
    PyModuleDef_HEAD_INIT,
    "twe_hash",
    "...",
    -1,
    tweMethods
};

PyMODINIT_FUNC PyInit_twe_hash(void) {
    return PyModule_Create(&tweModule);
}

#else

PyMODINIT_FUNC inittwe_hash(void) {
    (void) Py_InitModule("twe_hash", tweMethods);
}
#endif
