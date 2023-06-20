#include "drone.h"
#include <math.h>


Drone::Drone() {}

Drone::Drone(double x, double y, double z) { pos[0] = x; pos[1] = y; pos[2] = z; }

void Drone::UpdateDrone(double dt) {
    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i]*dt;
    } 
}

void Drone::SetJoystick(double x, double y, double z, double a) {
    dir[0] = x; dir[1] = y; dir[2] = z;
}

void Drone::KeyUp(const std::string& key, int keyCode) {
    keyValue[key] = 0;
}

void Drone::KeyDown(const std::string& key, int keyCode) {
    keyValue[key] = 1;
}

bool Drone::IsKeyDown(const std::string& key) {
    std::map<std::string,int>::iterator it = keyValue.find(key);
    if (it != keyValue.end()) {
        return it->second;
    } 

    return false;
}