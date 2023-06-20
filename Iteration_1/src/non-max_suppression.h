#ifndef NONMAX
#define NONMAX

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The filter class that applies the Hysteresis Filter
 */
class NonMaxSuppressionFilter : public Filter {

public:

    /**
    * @brief Applies the Hysteresis Filter to an image
    */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif