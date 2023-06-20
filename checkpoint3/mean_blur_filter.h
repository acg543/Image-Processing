#ifndef MEANBLUR
#define MEANBLUR

#include "image.h"
#include "filter.h"

class MeanBlurFilter : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    
};

#endif