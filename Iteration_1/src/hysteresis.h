#ifndef HYSTERESIS
#define HYSTERESIS

#include "image.h"
#include "filter.h"
#include <vector>

class HysteresisFilter : public Filter {

public:
    HysteresisFilter(){};
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};
#endif