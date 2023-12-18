
#include "cmatplotlib.hpp"


using namespace cmatplotlib;
namespace plt = cmatplotlib::pyplot;


int main()
{
    double* w = new double[5]{1, 2, 3, 4, 5};
    std::vector<double> x{1, 2, 3};
    std::vector<double> y{2, 4, 6};
    std::vector<std::vector<double>> z = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};

    // to_vector can be used to convert raw pointer array to std::vector
    plt::figure();
    plt::plot(to_vector(w, 5));

    // Keyword arguments (defined in 'genkwarg.hpp') can be used
    plt::figure();
    plt::plot(x, y, label="hi");
    plt::legend();

    // Even multiple keyword arguments can be used
    plt::figure();
    plt::plot(x, y=y, label=std::string("HELLO"), color='k');
    plt::legend();

    // Basically, it supports all functions in matplotlib.pyplot
    plt::figure();
    plt::contour(x, y, z);
    plt::colorbar();

    // Even 3D plots
    plt::figure();
    plt::axes(projection="3d");
    plt::plot(x, y);

    plt::show();
}
