#include <iostream>
#include <fstream>
#include <complex>

#include "bitmap.h"

const unsigned int width = 2000;
const unsigned int height = 2000;
const double xmin = -2.0;
const double xmax = 2.0;
const double ymin = -2.0;
const double ymax = 2.0;

double julia(std::complex<double> z, std::complex<double> c, unsigned int max_iter = 500) {
    for (unsigned int i = 0; i < max_iter; ++i) {
        z = z*z + c;
        if (std::abs(z) > 2) {
            return static_cast<double>(i) / max_iter;
        }
    }
    return 1.0;
}

int main(int argc, char *argv[]) {
    std::complex<double> c(std::atof(argv[1]), std::atof(argv[2]));
    std::ofstream output(argv[3]);
    if (!output.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    write_header(output, width, height);

    const double x1 = (xmax - xmin) / width;
    const double y1 = (ymax - ymin) / height;

    double y = ymin;
    for(unsigned int i = 0; i < width; ++i) {
        double x = xmin;
        for(unsigned int j = 0; j < height; ++j) {
            double intensitive = julia(std::complex<double>(x, y), c);
            unsigned char red = 255 * intensitive;
            unsigned char green = 255 * intensitive;
            unsigned char blue = 255 * intensitive;

            write_pixel(output, red, green, blue);
            x += x1;
        }
        y += y1;
    }
}
