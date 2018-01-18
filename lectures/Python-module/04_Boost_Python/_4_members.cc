#include <iostream>
struct Greetings
{
	Greetings(std::string name): name2greet(name),greetings(greet()) {} 
    std::string greet() { return "Hello "+this->name2greet; }
    std::string name2greet;
    std::string greetings;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_4_members) {
	class_<Greetings>("Greetings",init<std::string>())
	.def_readonly("greetings"  , &Greetings::greetings)
	.def_readwrite("name2greet", &Greetings::name2greet) 
	;
}
