#ifndef DRONE_APP_H_
#define DRONE_APP_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include "WebServer.h"
#include <chrono>
#include "simulation.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A Web Application Sever that communicates with a web page through web sockets
 */
class WebApp : public JSONSession, public Simulation {
public:
    /**
     * @brief Initializes server
     */
    WebApp() : start(std::chrono::system_clock::now()), time(0.0) {}
    /**
     * @brief Destructor
     */
    virtual ~WebApp() {}
    /**
     * @brief Receives JSON from the web server
     */
    void receiveJSON(picojson::value& val);
    /**
     * @brief Handles specific commands from the web server
     */
    void ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue);


private:
    // Used for tracking time since last update
    std::chrono::time_point<std::chrono::system_clock> start;
    // Stores current state of key presses
    std::map<std::string,int> keyValue;
    // The total time the server has been running.
    double time;
};

#endif
