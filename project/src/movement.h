#ifndef MOVEMENT_H_
#define MOVEMENT_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for handling movement of the drone
 */
class Movement {
public:
    /**
     * @brief Pure virtual function for handling drone movement
     */
    virtual void Move(Drone& drone, double direction[3], double distance, float speed, double dt) = 0;

};
#endif