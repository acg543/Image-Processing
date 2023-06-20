#ifndef DRONE_H_
#define DRONE_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for representing the drone object in the simulation
 */
class Drone {
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
    double speed = 1;

public:
    /**
     * @brief Default drone constructor
     */
    Drone();
    /**
     * @brief Construct a drone at a given position
     */
    Drone(double x, double y, double z);
    /**
     * @brief Updates the drone position and other dynamic properties
     */
    void UpdateDrone(double dt);
    /**
     * @brief Sets the direction of the drone
     */
    void SetJoystick(double x, double y, double z, double a);
    /**
     * @brief Check if keys are pressed
     *
     * @return True if yes, False if not
     */
    bool IsKeyDown(const std::string& key);
    /**
     * @brief Sets the keyValue indexed at key to 0
     */
    void KeyUp(const std::string& key, int keyCode);
    /**
     * @brief Sets the keyValue indexed at key to 1
     */
    void KeyDown(const std::string& key, int keyCode);
    /**
     * @brief Sets the drone's ID
     */
    void SetID(int i) { id = i; }
    /**
     * @brief Sets the drone's speed
     */
    void SetSpeed(double s) { speed = s; }
    /**
     * @brief Sets the drone's position
     */
    void SetPosition(double x, double y, double z) { pos[0] = x; pos[1] = y; pos[2] = z; }
    /**
     * @brief Sets the drone's direction
     */
    void SetDirection(double x, double y, double z) { dir[0] = x; dir[1] = y; dir[2] = z;  }
    /**
     * @brief Gets the drone's position at a given index
     *
     * @return The drone's position at a given index
     */
    double GetPosition(int index) { return pos[index]; }
    /**
     * @brief Gets the drone's direction at a given index
     *
     * @return The drone's direction at a given index
     */
    double GetDirection(int index) { return dir[index]; }
    /**
     * @brief Gets the drone's ID
     *
     * @return The drone's ID
     */
    int GetID() { return id; }
    /**
     * @brief Gets the drone's speed
     *
     * @return The drone's speed
     */
    double GetSpeed() { return speed; }
};

#endif