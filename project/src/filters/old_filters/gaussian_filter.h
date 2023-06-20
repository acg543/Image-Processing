//Jacob Dingee (dinge038)
#ifndef GAUSSIAN
#define GAUSSIAN

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "image.h"
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The filter class that applies the Gaussian Filter
 */
class GaussianFilter : public Filter {

public:
    /**
    * @brief Applies the Gaussian Blur Filter to an image
    */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);


private:
    /**
    * @brief Creating the frame for our 5x5 kernel
    */
    float kernel[5][5];

};

#endif