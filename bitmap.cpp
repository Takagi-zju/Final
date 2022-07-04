#include "bitmap.h"

void write_header(std::ostream &stream, unsigned int width, unsigned int height) {
    stream << "P3\n";
    stream << width << ' ' << height << '\n';
    stream << 255 << '\n';
}

void write_pixel(std::ostream &stream, unsigned char red, unsigned char green, unsigned char blue) {
    stream << static_cast<int>(red) << ' ' << static_cast<int>(green) << ' ' << static_cast<int>(blue) << '\n';
}
