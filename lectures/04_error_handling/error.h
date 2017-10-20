#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace errorspace{

 void error(const std::string& s)
  {
    throw std::runtime_error(s);
  }
  
    template <typename obj>
      void error(const std::string& s, const obj& o, const std::string& sfile, const unsigned int line)
  {
    std::ostringstream os;
    os << "\n\n"
       << "---------------------------------------------------------------------\n"
       << "A runtime exception has been called from file "<< sfile << ":"<<line
       <<"\nwith the following message.\n\n"
       << s <<" "<< o
       << "\n---------------------------------------------------------------------\n";
    error(os.str());
  }




} // close namespace
