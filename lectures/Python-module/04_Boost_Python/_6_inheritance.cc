#include <iostream>

class Base1 {
public: 
    Base1(std::string MSG): msg{MSG}{std::cout << this->msg << ",";}
	std::string msg; 
};


class Base2 {
public: 
    Base2(std::string MSG): msg{MSG}{std::cout << this->msg << ",";}
	std::string msg; 
};

class Derived1: public Base1 {
public: 
	Derived1(): Base1("Base1") {std::cout<<std::endl;}
	Derived1(std::string MSG1): Base1(MSG1) {std::cout<<std::endl;}
};

class Derived2: public Base1, public Base2 {
public: 
	Derived2(): Base1("Base1"), Base2("Base2") {std::cout<<std::endl;}
	Derived2(std::string MSG1, std::string MSG2): Base1(MSG1), Base2(MSG2) {std::cout<<std::endl;}
};


#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_6_inheritance) {
	class_<Base1>("Base1",init<std::string>()); 	
	class_<Base2>("Base2",init<std::string>()); 	
	class_<Derived1, bases<Base1> >("Derived1")
		.def(init<std::string>());
	class_<Derived2, bases<Base1,Base2> >("Derived2")
		.def(init<std::string,std::string>());
} 


