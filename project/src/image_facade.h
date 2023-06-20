#ifndef IMAGE_FACADE
#define IMAGE_FACADE


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filters/canny_edge.cc"
#include "filters/blob.cc"
#include "filters/depth.cc"

#include "imageio/image.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"

#include <string>
#include <cmath>


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for finding the robot, the direction, and distance from an image
 */
class ImageFacade {
        
    public:
        /**
        * @brief Finds if the robot is within the image, and if found finds the direction and distance to it
        */
        double * ApplyImage (Image img);

};
#endif