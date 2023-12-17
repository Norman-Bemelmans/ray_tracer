// Film class function definitions

#include "Film.hpp"
#include "RGBColor.hpp"

namespace RT {
void Film::addToBitmap(RGBColor col) {
    this->bitmap.push_back(col);
    return;
}
} // namespace RT
