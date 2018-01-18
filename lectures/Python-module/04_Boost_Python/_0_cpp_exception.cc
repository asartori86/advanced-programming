#include <Python.h>

struct myException {};

void explainException(const myException& x) {
	PyErr_SetString(PyExc_UserWarning, "...to print in Python Shell"); 
};

void this_throw_myException(){throw myException();}

#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_0_cpp_exception) {
	register_exception_translator<myException>(explainException);
	def("foo", this_throw_myException);
}
