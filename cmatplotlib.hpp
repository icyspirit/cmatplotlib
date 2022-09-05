
#ifndef CMATPLOTLIB_HPP
#define CMATPLOTLIB_HPP

#include <string>
#include <vector>
#include <Python.h>

template<class T>
class mpl
{
private:
    std::string toString(const std::vector<T>& v) const
    {
        char buf[32];
        std::string s = "[";
        for (T _v : v) {
            sprintf(buf, "%e,", _v);
            s += buf;
        }
        s += "]";
        return s;
    }

    std::string toString(const std::vector<std::vector<T>>& v) const
    {
        std::string s = "[";
        for (std::vector<T> _v : v) {
            s += toString(_v) + ",";
        }
        s += "]";
        return s;
    }

public:
    mpl()
    {
        Py_Initialize();
        PyRun_SimpleString("import matplotlib.pyplot as plt");
    }

    void plot(const std::vector<T>& x) const
    {
        std::string command = "plt.plot(" + toString(x) + ")";
        PyRun_SimpleString(command.c_str());
    }

    void plot(const std::vector<T>& x, const std::vector<T>& y) const
    {
        std::string command = "plt.plot(" + toString(x) + "," + toString(y) + ")";
        PyRun_SimpleString(command.c_str());
    }

    void contour(const std::vector<std::vector<T>>& z) const
    {
        std::string command = "plt.contour(" + toString(z) + ")";
        PyRun_SimpleString(command.c_str());

    }

    void contour(const std::vector<T>& x, const std::vector<T>& y, const std::vector<std::vector<T>>& z) const
    {
        std::string command = "plt.contour(" + toString(x) + "," + toString(y) + "," + toString(z) + ")";
        PyRun_SimpleString(command.c_str());
    }

    void show() const
    {
        PyRun_SimpleString("plt.show()");
    }
};

#endif
