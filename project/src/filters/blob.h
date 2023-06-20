#ifndef BLOB
#define BLOB


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
 * @brief The class for applying the blob detection
 */
class Blob {
    public:
        /**
         * @brief Determines if the robot is there and the location of it in the image
         * 
         */
        double * FindBlob(Image orig, Image canny);
};
#endif