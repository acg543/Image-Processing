#include "drone.h"
#include <math.h>


Drone2::Drone() {}

Drone2::Drone(double a, double b, double c) { pos[0] = a; pos[1] = b; pos[2] = c; }

void Drone2::UpdateDrone(double dt) {
    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i]*dt;
    } 

    SetJoystick(
    IsKeyDown("l") ? 1 : (IsKeyDown("j") ? -1 : 0),
    IsKeyDown("i") ? 1 : (IsKeyDown("k") ? -1 : 0),
);
}

void Drone2::SetJoystick(double a, double b, double c, double d) {
    dir[0] = a; dir[1] = b; dir[2] = c;
}

void Drone2::KeyUp(const std::string& key, int keyCode) {
    keyValue[key] = 0;
}

void Drone2::KeyDown(const std::string& key, int keyCode) {
    keyValue[key] = 1;
}

bool Drone2::IsKeyDown(const std::string& key) {
    std::map<std::string,int>::iterator it = keyValue.find(key);
    if (it != keyValue.end()) {
        return it->second;
    } 

    return false;
}