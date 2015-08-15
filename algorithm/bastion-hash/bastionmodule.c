#include <Python.h>

#include "bastion.h"

static PyObject *bastion_getpowhash(PyObject *self, PyObject *args)
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
    bastion_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    bastion_hash((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef bastionMethods[] = {
    { "getPoWHash", bastion_getpowhash, METH_VARARGS, "Returns the proof of work hash using bastion hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef bastionModule = {
    PyModuleDef_HEAD_INIT,
    "bastion_hash",
    "...",
    -1,
    bastionMethods
};

PyMODINIT_FUNC PyInit_bastion_hash(void) {
    return PyModule_Create(&bastionModule);
}

#else

PyMODINIT_FUNC initbastion_hash(void) {
    (void) Py_InitModule("bastion_hash", bastionMethods);
}
#endif
