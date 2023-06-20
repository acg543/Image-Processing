#ifndef GREYSCALE
#define GREYSCALE

#include <vector>
#include "image.h"
#include "filter.h"
class GreyScaleFilter : public Filter {

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);

};
#endif