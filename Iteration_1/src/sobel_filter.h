//Jacob Dingee (dinge038)
#ifndef SOBEL
#define SOBEL

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
 * @brief The filter class that applies the Sobel Filter
 */
class SobelFilter : public Filter {

    public:
        /**
        * @brief Applies the Sobel Filter to an image
        */
        void Apply(std::vector<Image*> original, std::vector<Image*> filtered);

    private:
        /**
        * @brief Defining our horizontal and vertical kernels
        */
    float kernelX[3][3] = {{-1.0, 0.0, 1.0}, 
                           {-2.0, 0.0, 2.0}, 
                           {-1.0, 0.0, 1.0}};

    float kernelY[3][3] = {{1.0, 2.0, 1.0}, 
                           {0.0, 0.0, 0.0}, 
                           {-1.0, -2.0, -1.0}};
};

#endif