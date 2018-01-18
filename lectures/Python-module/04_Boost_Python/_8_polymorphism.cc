#include <iostream>

struct Interface_to_something
{
    virtual ~Interface_to_something() {}
    virtual std::string foo() = 0; 
};


struct Polymorphic_object : public Interface_to_something{
	virtual std::string foo() override {
		return "from this specific object created in C++";
	}
};

struct Another_object : public Interface_to_something{
	virtual std::string foo() override {
		return "from another object created in C++";
	}
};

Interface_to_something* polymorphic_objects_factory(const int type=0){
	switch(type){
		case 1: return new Polymorphic_object; 
		case 2: return new Another_object; 	   
		default: return nullptr; 			   //by default
	}
}

#include <boost/python.hpp>
using namespace boost::python;

class InterfaceWrap 
: public Interface_to_something, public wrapper<Interface_to_something>{
	std::string foo(){
        return this->get_override("foo")();
    }
};

BOOST_PYTHON_MODULE_INIT(_8_polymorphism)
{
    class_<Interface_to_something,boost::noncopyable>("", no_init)
		;

    class_<InterfaceWrap,boost::noncopyable>("Interface")
        .def("foo", pure_virtual(&Interface_to_something::foo))
        ;

	class_<Polymorphic_object,bases<Interface_to_something>>("obj1")
        .def("foo", &Polymorphic_object::foo)
        ;

	class_<Another_object,bases<Interface_to_something>>("obj2")
        .def("foo", &Another_object::foo)
        ;

	def("factory", &polymorphic_objects_factory, 
				   return_value_policy<manage_new_object>());
}

