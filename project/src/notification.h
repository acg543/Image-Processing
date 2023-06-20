#ifndef NOTIFICATION
#define NOTIFICATION


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "imageio/image.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for displaying notifications.
 */

class Notification {
	/**
	 * @brief Creates notifications for battery percentage, if the drone is damaged, and if there is severe weather.
	 * 
	 */
	int battery;
	int damaged;
	int severeWeather;

	public:

	Notification();

	Notification(int batteryLife, int isDamaged, int isSevereWeather);

	~Notification();

	int getBattery() const;
	int getDamaged() const;
	int getSevereWeather() const;

	int displayBattery();
	int displayDamaged();
	int displaySevereWeather();
};

// use an observer pattern for this
// there are observers and subjects, observer observes subject and send messages
// drone is subject, observer would be something else

#endif