#ifndef CANNY_EDGE
#define CANNY_EDGE

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "imageio/canny_edge_detect.h"

#include "imageio/image.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for finding the outline of the robot
 */
class CannyEdge {
        
    public:
        /**
        * @brief Highlights the edges in the image
        */
        Image ApplyCannyEdge (Image input);

};
#endif