#ifndef FILTER
#define FILTER
#include "image.h"
#include <vector>

class Filter {


public:

    virtual ~Filter() {}

    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered) = 0;

};

#endif