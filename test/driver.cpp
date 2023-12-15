

#include "cmatplotlib.hpp"

using namespace cmatplotlib;

int main()
{
    std::vector<double> x{1, 2, 3};
    std::vector<double> y{2, 4, 6};
    print(x, y);
    plot(x, y);
    show();
}
