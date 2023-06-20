#include "entity_factory.h"

void EntityFactory::CreateEntity(picojson::object& entityData) {

    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    if (entityData["name"].get<std::string>() == "drone") {

        droneEntity.SetID(entityData["entityId"].get<double>());
        droneEntity.SetSpeed(entityData["speed"].get<double>());

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        droneEntity.SetPosition(position[0].get<double>(), position[1].get<double>(), position[1].get<double>());

        // Get the direction as an array
        picojson::array dir = entityData["direction"].get<picojson::array>();
        droneEntity.SetDirection(dir[0].get<double>(), dir[1].get<double>(), dir[1].get<double>());

}
}