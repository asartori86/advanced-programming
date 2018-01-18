#include <iostream>
struct Greetings
{
	Greetings(std::string name): name2greet(name) {} 
    std::string greet() { return "Hello "+this->name2greet; }
    std::string name2greet;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_3_constructors) {
	class_<Greetings>("Greetings",init<std::string>())
	.def("greet", &Greetings::greet)
	;
}
