#include <Python.h>

#include "blake_sfr.h"

static PyObject *blake_sfr_getpowhash(PyObject *self, PyObject *args)
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
    blake_sfr_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    blake_sfr_hash((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef blake_sfrMethods[] = {
    { "getPoWHash", blake_sfr_getpowhash, METH_VARARGS, "Returns the proof of work hash using blake_sfr hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef blake_sfrModule = {
    PyModuleDef_HEAD_INIT,
    "blake_sfr_hash",
    "...",
    -1,
    blake_sfrMethods
};

PyMODINIT_FUNC PyInit_blake_sfr_hash(void) {
    return PyModule_Create(&blake_sfrModule);
}

#else

PyMODINIT_FUNC initblake_sfr_hash(void) {
    (void) Py_InitModule("blake_sfr_hash", blake_sfrMethods);
}
#endif
