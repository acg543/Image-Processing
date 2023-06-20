#include "simulation.h"


void Simulation::Update(double dt) {

    drone.SetJoystick(
        IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
        IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
        IsKeyDown("ArrowUp") ? -1 : (IsKeyDown("ArrowDown") ? 1 : 0),
        IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0)
    );
    drone.UpdateDrone(dt);
}

void Simulation::FinishUpdate(picojson::object& returnValue) {

    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(drone.GetPosition(0)));
    pos.push_back(picojson::value(drone.GetPosition(1)));
    pos.push_back(picojson::value(drone.GetPosition(2)));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(drone.GetDirection(0)));
    dir.push_back(picojson::value(drone.GetDirection(1)));
    dir.push_back(picojson::value(drone.GetDirection(2)));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(drone.GetID())] = picojson::value(entity);
}

    