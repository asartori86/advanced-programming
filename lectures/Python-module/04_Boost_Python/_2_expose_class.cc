#include <iostream>
struct Greetings
{
    void set(std::string name) { this->name2greet = name; }
    std::string greet() { return "Hello "+this->name2greet; }
    std::string name2greet;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_2_expose_class) {
	class_<Greetings>("Greetings")
	.def("greet", &Greetings::greet)
	.def("set"  , &Greetings::set)
	;
}
