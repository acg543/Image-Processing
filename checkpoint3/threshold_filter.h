#ifndef THRESHOLD
#define THRESHOLD

#include "image.h"
#include "filter.h"

class ThresholdFilter : public Filter {
public:
    ThresholdFilter(float a);

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);


    float threshold;

};

#endif