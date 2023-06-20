#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "picojson.h"
#include "drone.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for creating json object entities
 */
class EntityFactory {
public:
    // Drone object to get initialized by CreateEntity 
    Drone droneEntity;
    /**
     * @brief Creates an entity based on the object passed in
     */
    void CreateEntity(picojson::object& entityData);
};
#endif