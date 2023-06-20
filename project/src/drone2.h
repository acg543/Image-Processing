#ifndef DRONE2_H_
#define DRONE2_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include "imageio/image.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for representing the drone object in the simulation
 */

class Drone2 {
    /**
     * @brief Creates a second robot.
     * 
     */
private:
    // Stores current state of key presses
    std::map<std::string,int> keyValue;
    // Position array storing coordinates <x,y,z>
    double pos[3]; 
    // Direction array
    double dir[3]; 
    // Entity ID
    int id; 
    // Speed of the drone
    double speed;

public:
    // Default Constructor
    Drone2();

    // Construct a drone at a given position
    Drone2(double a, double b, double c);

    // Updates the drone position and other dynamic properties
    void UpdateDrone(double dt);

    // Sets the direction of the drone
    void SetJoystick(double a, double b, double c, double d);
    // Check if keys are pressed
    bool IsKeyDown(const std::string& key);
    // Sets the keyValue indexed at key to 0
    void KeyUp(const std::string& key, int keyCode);
    // Sets the keyValue indexed at key to 1
    void KeyDown(const std::string& key, int keyCode);
    
    
    // Sets the drone's ID
    void SetID(int i) { id = i; }
    // Sets the drone's speed
    void SetSpeed(double s) { speed = s; }
    // Sets the drone's position
    void SetPosition(double a, double b, double c) { pos[0] = a; pos[1] = b; pos[2] = c; }
    // Sets the drone's direction
    void SetDirection(double a, double b, double c) { dir[0] = a; dir[1] = b; dir[2] = c;  }

    // Gets the drone's position
    double GetPosition(int index) { return pos[index]; }
    // Gets the drone's direction
    double GetDirection(int index) { return dir[index]; }
    // Gets the drone's ID
    int GetID() { return id; }
    // Gets the drone's speed
    double GetSpeed() { return speed; }
};

#endif