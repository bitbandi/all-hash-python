#include <Python.h>

#include "yescrypt.h"
#include "yescryptcommon.c"
#include "yescrypt-opt.c"
#include "sha256_Y.c"

static void YescryptHash(const char *input, int length, char *output)
{
    yescrypt_bsty((const uint8_t*)input, length, (const uint8_t*)input, length, 2048, 8, 1, (uint8_t*)output, 32);
}

static PyObject *yescrypt_getpowhash(PyObject *self, PyObject *args)
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
    YescryptHash((char *)PyBytes_AsString((PyObject*) input), 80, output);
#else
    YescryptHash((char *)PyString_AsString((PyObject*) input), 80, output);
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

static PyMethodDef YescryptMethods[] = {
    { "getPoWHash", yescrypt_getpowhash, METH_VARARGS, "Returns the proof of work hash using X15 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef YescryptModule = {
    PyModuleDef_HEAD_INIT,
    "yescrypt_hash",
    "...",
    -1,
    YescryptMethods
};

PyMODINIT_FUNC PyInit_yescrypt_hash(void) {
    return PyModule_Create(&YescryptModule);
}

#else

PyMODINIT_FUNC inityescrypt_hash(void) {
    (void) Py_InitModule("yescrypt_hash", YescryptMethods);
}
#endif


