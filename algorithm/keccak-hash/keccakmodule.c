#include <Python.h>

#include "keccak.h"

static PyObject *keccak_getpowhash(PyObject *self, PyObject *args)
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
    keccak_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    keccak_hash((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef keccakMethods[] = {
    { "getPoWHash", keccak_getpowhash, METH_VARARGS, "Returns the proof of work hash using keccak hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef keccakModule = {
    PyModuleDef_HEAD_INIT,
    "keccak_hash",
    "...",
    -1,
    keccakMethods
};

PyMODINIT_FUNC PyInit_keccak_hash(void) {
    return PyModule_Create(&keccakModule);
}

#else

PyMODINIT_FUNC initkeccak_hash(void) {
    (void) Py_InitModule("keccak_hash", keccakMethods);
}
#endif
