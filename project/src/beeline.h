#ifndef BEELINE_H
#define BEELINE_H


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"
#include "movement.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for moving the drone in a straight line from point A to point B
 */
class Beeline : public Movement {

public:
    /**
     * @brief Moves the drone in straight line 
     */
    void Move(Drone& drone, double direction[3], double distance, float speed, double dt);
};
#endif