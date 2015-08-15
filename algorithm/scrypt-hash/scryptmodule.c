#include <Python.h>

#include "scrypt.h"

static PyObject *scrypt_getpowhash(PyObject *self, PyObject *args)
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
    scrypt_1024_1_1_256((char *)PyBytes_AsString((PyObject*) input), output);
#else
    scrypt_1024_1_1_256((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef scryptMethods[] = {
    { "getPoWHash", scrypt_getpowhash, METH_VARARGS, "Returns the proof of work hash using scrypt hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef scryptModule = {
    PyModuleDef_HEAD_INIT,
    "ltc_scrypt",
    "...",
    -1,
    scryptMethods
};

PyMODINIT_FUNC PyInit_ltc_scrypt(void) {
    return PyModule_Create(&scryptModule);
}

#else

PyMODINIT_FUNC initltc_scrypt(void) {
    (void) Py_InitModule("ltc_scrypt", scryptMethods);
}
#endif
