#include <iostream>

// simple
const char *simple() { return "hello, world"; }

// auto overloading
void auto_foo(){std::cout<<"0 args" << std::endl;}
void auto_foo(bool a){std::cout<<"1 args" << std::endl;}
void auto_foo(bool a, int b){std::cout<<"2 args" << std::endl;}
void auto_foo(bool a, int b, char c){std::cout<<"3 args" << std::endl;}

// default values
void defval_foo(bool a, int b=0, std::string c="0"){
	std::cout << a  
		<< " " << b 
		<< " " << c 
		<< std::endl;
}

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_FUNCTION_OVERLOADS(auto_foo_overloads, auto_foo, 0, 3); 
BOOST_PYTHON_FUNCTION_OVERLOADS(defval_foo_overloads, defval_foo, 1, 3);

BOOST_PYTHON_MODULE(_1_expose_function) {
	def("simple"     , simple);
	def("auto_foo"  , (void(*)(bool,int,char))0,auto_foo_overloads());
	def("defval_foo" , (void(*)(bool,int,std::string))0,defval_foo_overloads());
}
