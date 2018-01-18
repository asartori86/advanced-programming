#include <sstream>
#include <string>
#include <vector>

template <class T>
class myIterator {
private:
    std::vector<T> mS;
public:
    myIterator() {}
    void add(const T& s){
        mS.push_back(s);
    }

    typename std::vector<T>::iterator begin(){
        return mS.begin();
    }
    typename std::vector<T>::iterator end(){
        return mS.end();
    }

};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(__iterators)
{
    class_<myIterator<double>>("iterator_d")
        .def("range", 
			  range(&myIterator<double>::begin, 
					&myIterator<double>::end))
        .def("add", &myIterator<double>::add)
    ;

    class_<myIterator<std::string>>("iterator_s")
        .def("range", 
			  range(&myIterator<std::string>::begin, 
					&myIterator<std::string>::end))
        .def("add", &myIterator<std::string>::add)
    ;
} 
