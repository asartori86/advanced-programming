#ifndef __AP_ERROR_H__
#define __AP_ERROR_H__

#include <assert.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ap {

  namespace internal {
    static std::string sep = " ";
  }

  template <typename T>
  void error(const T& s) {
    std::ostringstream os;
    os << s;
    throw std::runtime_error{os.str()};
  }

  template <typename T1, typename T2>
  void error(const T1& s, const T2& t) {
    std::ostringstream os;
    os << s << internal::sep << t;
    error(os.str());
  }

  template <typename T1, typename T2, typename... Tail>
  void error(const T1& f, const T2& s, const Tail&... rest) {
    /* std::cout << __PRETTY_FUNCTION__ << std::endl; */
    std::ostringstream os;
    os << f << internal::sep << s;
    error(os.str(), rest...);
  }

  inline void set_separator(const std::string& s) { internal::sep = s; }

  inline void reset_separator() { internal::sep = " "; }

}  // close namespace ap

// some useful macros
#define AP_error(...)                                                 \
  ap::internal::pretty_error(__FILE__, __LINE__, __PRETTY_FUNCTION__, \
                             __VA_ARGS__)

#ifndef NDEBUG
#define AP_assert(cond, ...)                                              \
  {                                                                       \
    if (!(cond))                                                          \
      ap::internal::pretty_error(__FILE__, __LINE__, __PRETTY_FUNCTION__, \
                                 __VA_ARGS__);                            \
  }
#else
#define AP_assert(cond, ...)
#endif

template <typename t1, typename t2, typename t3>
std::string NotInRange(const t1& a, const t2& b, const t3& c) {
  std::ostringstream os;
  os << c << " does not belong to [" << a << ", " << b << ")\n";
  return os.str();
}

namespace ap {
  namespace internal {
    template <typename T, typename... Tail>
    void pretty_error(const char* sfile,
                      const unsigned int& line,
                      const char* sfunc,
                      const T& f,
                      const Tail&... rest) {
      std::ostringstream os;
      os << "\n\n"
         << "------------------------------------------------------------------"
            "---"
            "\n"
         << "A runtime exception has been thrown\n\n"
         << "   function: " << sfunc << '\n'
         << "       file: " << sfile << '\n'
         << "       line: " << line << "\n\n"
         << "with the following output:\n\n"
         << f;
      error(os.str(), rest...);
    }
  }  // close namespace internal
}  // close namespace ap

#endif
