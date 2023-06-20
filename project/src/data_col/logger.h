#ifndef LOGGER_H_
#define LOGGER_H_

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
 * @brief The class for saving csv data.
 */

class Logger {
    /**
     * @brief Saves data from the drone to a csv, database, and command line.
     * 
     */
    Logger();
    static Logger* instance;
    
    public:
        static Logger& Instance();

        void Log(const std::string& message, bool csv, bool db, bool cl);   // db - database, cl - command line

}

#endif