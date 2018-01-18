#include <iostream>
struct Greetings
{
	Greetings(std::string name): name2greet(name) {this->set_greetings(name);} 
    void set_greetings(std::string name) {this->greetings = "Hello "+name;}
	std::string get_greetings() {return this->greetings;} 
	std::string get_name() {return this->name2greet;}
    std::string name2greet;
    std::string greetings;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_5_properties) {
	class_<Greetings>("Greetings",init<std::string>())
	.add_property("name2greet",&Greetings::get_name) // only getter 
	.add_property("greetings" ,&Greetings::get_greetings  
			                  ,&Greetings::set_greetings) // setter/getter 
	;
}
