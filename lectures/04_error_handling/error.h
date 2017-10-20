#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace errorspace {

void error(const std::string& s) {
  throw std::runtime_error(s);
}

template <typename T>
void _error(T t) {
  std::ostringstream os;
  os << t;
  error(os.str());
}

template <typename T, typename... Tail>
void _error(const std::string& s, T f, Tail... rest) {
  std::ostringstream os;
  os << s << " " << f;
  _error(os.str(), rest...);
}

template <typename... Tail>
void error(const char* sfile,
           const unsigned int& line,
           const char* sfunc,
           Tail... rest) {
  std::ostringstream os;
  os << "\n\n"
     << "---------------------------------------------------------------------"
        "\n"
     << "A runtime exception has been thrown\n\n"
     << "function: " << sfunc << '\n'
     << "file:     " << sfile << '\n'
     << "line:     " << line << "\n\n"
     << "with the following message:\n\n";
  _error(os.str(), rest...);
}

}  // close namespace
