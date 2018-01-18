#include <sstream>
#include <string>
#include <iostream>

template <typename T>
class Number
{
private:
    T mN;
public:
    Number(T n = 0) : mN(n) {}
    Number& operator+= (const T i){
        mN += i;
        return *this;
    }
    Number& operator-= (const T i){
        mN -= i;
        return *this;
    }
    std::string str() const{
        std::stringstream s;
        s << mN;
        return s.str();
    }
    std::string repr() const{
        std::stringstream s;
        s << "Number("<< mN << ")";
        return s.str();
    }

    bool lt(const T i) {
        return mN<i;
    }

	/*
    bool gt(const T i) {
        return mN>i;
    }
	*/
	
	template <typename ot>
	friend bool operator>(const Number<ot>& n, const Number<ot>& i); 
};

template <typename T>
Number<T>& operator+(Number<T>& n, const T i){ 
    n += i;
    return n;
};

template <typename T>
Number<T>& operator-(Number<T>& n, const T i){ 
    n -= i;
    return n;
};

template <typename T>
bool operator>(const Number<T>& n, const Number<T>& i){ 
    return n.mN > i.mN;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(_10_operators_magics)
{
    class_<Number<int>>("Number_i")
        .def(init< optional<int> >()) // constructior
        .def("__str__"  , &Number<int>::str)
        .def("__repr__" , &Number<int>::repr)
        .def("__lt__"   , &Number<int>::lt)
        //.def("__gt__"   , &Number<int>::gt)
        .def(self > self)  // __gt__
        .def(self += int()) // __iadd__
        .def(self + int())  // __add__
        .def(self -= int()) // __isub__
        .def(self - int())  // __sub__
    ;
} 
