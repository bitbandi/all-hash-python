#include <Python.h>

#include "lyra2re.h"

static PyObject *lyra2re_getpowhash(PyObject *self, PyObject *args)
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
    lyra2re_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    lyra2re_hash((char *)PyString_AsString((PyObject*) input), output);
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

static PyMethodDef lyra2reMethods[] = {
    { "getPoWHash", lyra2re_getpowhash, METH_VARARGS, "Returns the proof of work hash using lyra2re hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef lyra2reModule = {
    PyModuleDef_HEAD_INIT,
    "lyra2re_hash",
    "...",
    -1,
    lyra2reMethods
};

PyMODINIT_FUNC PyInit_lyra2re_hash(void) {
    return PyModule_Create(&lyra2reModule);
}

#else

PyMODINIT_FUNC initlyra2re_hash(void) {
    (void) Py_InitModule("lyra2re_hash", lyra2reMethods);
}
#endif
