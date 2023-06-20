#include "beeline.h"
#include <math.h>


void Beeline::Move(Drone& drone, double direction[3], double distance, float speed, double dt) {

    // Rotate and Normalize the vector
    double magnitude = sqrt((direction[0] * direction[0]) + (direction[1] * direction[1]) + (direction[2] * direction[2]));
    direction[0] = direction[0] / magnitude; direction[1] = direction[1] / magnitude; direction[2] = direction[2] / magnitude;

    // Move the Drone
    direction[0] = direction[0] * speed; direction[1] = direction[1] * speed; direction[2] = direction[2] * speed;
    direction[0] = direction[0] * dt; direction[1] = direction[1] * dt; direction[2] = direction[2] * dt;
    drone.SetPosition(
        (drone.GetPosition(0) + direction[0]), 
        (drone.GetPosition(1) + direction[1]), 
        (drone.GetPosition(2) + direction[2]));
}

