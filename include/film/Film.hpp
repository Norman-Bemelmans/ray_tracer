// Film class definition

#ifndef FILM_HPP
#define FILM_HPP

#include <vector>

namespace RT {
class RGBColor;

class Film {
friend void film_test();
public:
    Film() = default;
    // method to append RGBColor to bitmap.
    void addToBitmap(RGBColor col);
private:
    // bitmap is the container that holds the color at each pixel of the viewing window.
    std::vector<RGBColor> bitmap;
};
} // namespace RT

#endif
