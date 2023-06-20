#ifndef SIMULATION_H_
#define SIMULATION_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"
#include "entity_factory.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for simulating a drone finding a robot
 */
class Simulation : public EntityFactory, public Drone {

public:
    // Drone Entity
    Drone drone = EntityFactory::droneEntity;
    /**
     * @brief Creates an entity based on object passed and sets all data fields
     */
    virtual void CreateEntity(picojson::object& entityData) {}
    /**
     * @brief Updates the simulation based on time passed
     */
    void Update(double dt);
    /**
     * @brief Updates the final display. Called after all updating is done
     */
    void FinishUpdate(picojson::object& returnValue);

};
#endif