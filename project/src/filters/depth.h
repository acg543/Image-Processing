#ifndef DEPTH
#define DEPTH


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "imageio/image.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for finding direction and distance to the robot
 */
class Depth {
        
    public:
        /**
        * @brief Finds the direction and distance to the robot
        */
        double * FindDepth(Image img, double location[2]);

};
#endif