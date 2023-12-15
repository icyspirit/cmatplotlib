
#ifndef CMATPLOTLIB_HPP
#define CMATPLOTLIB_HPP


#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <Python.h>


#define GENFUNC(NAME) \
template<typename... T> \
void NAME(T... args) \
{ \
    py_execute(std::string(#NAME) + "(" + ("" + ... + (to_string(args) + ", ")) + ")"); \
}


namespace cmatplotlib {

static bool initialized = false;


static void py_execute(const std::string& command)
{
    if (!initialized) {
        Py_Initialize();
        PyRun_SimpleString("from matplotlib.pyplot import *");
        PyRun_SimpleString("from numpy import *");
        initialized = true;
    }
    int errorCode = PyRun_SimpleString(command.c_str());
    if (errorCode != 0) {
        exit(errorCode);
    }
}


template<typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v)
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


GENFUNC(print);
GENFUNC(plot);
GENFUNC(plot3D);
GENFUNC(scatter);
GENFUNC(contour);
GENFUNC(contourf);
GENFUNC(pcolor);
GENFUNC(figure);
GENFUNC(show);

};


#endif

