#include <Python.h>


#include "pentablake.h"


static PyObject *pentablake_getpowhash(PyObject *self, PyObject *args)
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
    pentablake_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    pentablake_hash((char *)PyString_AsString((PyObject*) input), output);
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


static PyMethodDef pentablakeMethods[] = {
    { "getPoWHash", pentablake_getpowhash, METH_VARARGS, "Returns the proof of work hash using pentablake hash" },
    { NULL, NULL, 0, NULL }
};


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef pentablakeModule = {
    PyModuleDef_HEAD_INIT,
    "pentablake_hash",
    "...",
    -1,
    pentablakeMethods
};


PyMODINIT_FUNC PyInit_pentablake_hash(void) {
    return PyModule_Create(&pentablakeModule);
}


#else


PyMODINIT_FUNC initpentablake_hash(void) {
    (void) Py_InitModule("pentablake_hash", pentablakeMethods);
}
#endif
