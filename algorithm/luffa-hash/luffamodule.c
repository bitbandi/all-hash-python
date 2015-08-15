#include <Python.h>

#include "luffa.h"

static PyObject *luffa_getpowhash(PyObject *self, PyObject *args)
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
    luffa_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    luffa_hash((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef LuffaMethods[] = {
    { "getPoWHash", luffa_getpowhash, METH_VARARGS, "Returns the proof of work hash using luffa hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef LuffaModule = {
    PyModuleDef_HEAD_INIT,
    "luffa_hash",
    "...",
    -1,
    LuffaMethods
};

PyMODINIT_FUNC PyInit_luffa_hash(void) {
    return PyModule_Create(&LuffaModule);
}

#else

PyMODINIT_FUNC initluffa_hash(void) {
    (void) Py_InitModule("luffa_hash", LuffaMethods);
}
#endif
