#include "MyPlayerController.h"

#include <string>
#include <iostream>

Vector2 MyPlayerController::ComputeVelocity(bool moveRight, bool moveUp, bool moveLeft, bool moveDown)
{
	float x = -1.0f;
	float y = -1.0f;
	
	if (pythonModule_)
	{
		PyObject* pyComputeVelocity = PyObject_GetAttrString(pythonModule_, "ComputeVelocity");
		if (pyComputeVelocity)
		{
			Py_INCREF(pyComputeVelocity);
			{
				PyObject* pyResult = PyObject_CallFunctionObjArgs /* Call the python function. */
				(
					pyComputeVelocity,
					PyBool_FromLong((long)moveRight), // TODO: see if this call causes a memory leak.
					PyBool_FromLong((long)moveUp),
					PyBool_FromLong((long)moveLeft),
					PyBool_FromLong((long)moveDown),
					NULL
				);
				if (pyResult)
				{
					Py_INCREF(pyResult);
					{
						if (!PyArg_ParseTuple(pyResult, "ff", &x, &y))
						{
							std::cerr << "Could not parse the returned value!\n";
							return Vector2(x, y);
						}
						
					}Py_XDECREF(pyResult);
				}
				else
				{
					std::cerr << "Could not call function!\n";
					return Vector2(x, y);
				}
			}Py_XDECREF(pyComputeVelocity);
		}
		else
		{
			std::cerr << "Could not retireve python's ComputeVelocity()!\n";
			return Vector2(x, y);
		}
	}
	return Vector2(x, y);
}

void MyPlayerController::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("ComputeVelocity", "moveRight", "moveUp", "moveLeft", "moveDown"), &MyPlayerController::ComputeVelocity);
}

MyPlayerController::MyPlayerController()
{
	Py_Initialize();
	
	// Ugly hack to add current dir to sys.path . Need to find a better way.
	// Note: YES, this is needed for god knows what reason for the PyImport_ImportModule() to work...
	PyRun_SimpleString("import sys; sys.path.insert(0, 'C:/Users/admin/Desktop/godot/modules/MyPlayerController')");
	
	// Import python module into the interpreter and set an object reference to it.
	pythonModule_ = PyImport_ImportModule("MyPythonModule");
	if (pythonModule_)
	{
		Py_INCREF(pythonModule_); // Increment ref since the module needs to last for the whole runtime.
	}
	else
	{
		std::cerr << "Could not retireve MyPythonModule!\n";
		return;
	}
}

MyPlayerController::~MyPlayerController()
{
	// Decrement ref count to module object.
	if (pythonModule_)
	{
		Py_DECREF(pythonModule_);
	}
	else
	{
		std::cerr << "pythonModule_ is NULL!\n";
		Py_XDECREF(pythonModule_);
	}
	Py_Finalize();
}