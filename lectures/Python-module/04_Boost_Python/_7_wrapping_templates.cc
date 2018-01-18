#include <iostream>

template <typename T> 
struct Foo {
	Foo(): value{(T) 0.01234567890123456789} {}
	T value;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_7_wrapping_templates) {
	class_<Foo <int> >("Foo_int")
		.def_readonly("value", &Foo <int>::value); 	
	class_<Foo <float> >("Foo_float")
		.def_readonly("value", &Foo <float>::value); 	
	class_<Foo <double> >("Foo_double")
		.def_readonly("value", &Foo <double>::value); 	
} 


