#ifndef DOUBLETHRESHOLD
#define DOUBLETHRESHOLD

#include "image.h"
#include "filter.h"
#include <vector>

class DoubleThresholdFilter : public Filter {

private:
    float high_threshold;
    float low_threshold;

public:
    DoubleThresholdFilter(float h, float l);
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};
#endif