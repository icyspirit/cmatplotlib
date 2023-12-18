
#ifndef CMATPLOTLIB_HPP
#define CMATPLOTLIB_HPP


#include <ios>
#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
#include <Python.h>


#define GENFUNC(NAME) \
template<typename... T> \
void NAME(T... args) \
{ \
    py_execute(std::string(NAMESPACE) + "." + std::string(#NAME) + "(" + ("" + ... + (to_string(args) + ", ")) + ")"); \
}


#define GENKWARG(NAME) \
namespace kwargs { \
struct NAME { \
    template<typename T> \
    kwarg operator =(const T& v) const \
    { \
        return kwarg{#NAME, to_string(v)}; \
    } \
}; \
} \
static const kwargs::NAME NAME;


struct kwarg {
    std::string key;
    std::string value;
};


template<typename T>
inline std::vector<T> to_vector(const T* const v, size_t n)
{
    return std::vector(v, v + n);
}


template<typename T>
static std::ostream& operator <<(std::ostream& os, const std::vector<T>& v)
{
    if constexpr (std::is_floating_point_v<T>) {
        os << std::scientific;
    }
    os << '[';
    for (const T& v_: v) {
        os << v_ << ',';
    }
    return os << ']';
}


template<typename T>
std::string to_string(const T& v)
{
    std::ostringstream ss;
    ss << v;
    return ss.str();
}


std::string to_string(const char v)
{
    std::ostringstream ss;
    ss << "\"" << v << "\"";
    return ss.str();
}


std::string to_string(const char* v)
{
    std::ostringstream ss;
    ss << "\"" << v << "\"";
    return ss.str();
}


std::string to_string(const std::string& v)
{
    return "\"" + v + "\"";
}


std::string to_string(const kwarg& v)
{
    return "**{'" + v.key + "':" + v.value + "}";
}


namespace cmatplotlib {
    #include "genkwarg.hpp"

    namespace pyplot {
        static std::string NAMESPACE = "matplotlib.pyplot";
        static bool initialized = false;

        static void py_execute(const std::string& command)
        {
            if (!initialized) {
                Py_Initialize();
                PyRun_SimpleString(("import " + NAMESPACE).c_str());
                PyRun_SimpleString("from numpy import nan");
                initialized = true;
            }
            int err = PyRun_SimpleString(command.c_str());
            if (err != 0) {
                exit(err);
            }
        }

        #include "genfunc.hpp"
    }
};


#endif

