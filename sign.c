#include <Python.h>
static PyObject *
sign_start(PyObject *self, PyObject *args)
{
	const char *command;
	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	system(command);
	return Py_Null;
}

sign_draw(PyObject *self, PyObject *args)
{
	
