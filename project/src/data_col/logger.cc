#include <iostream>
#include "logger.h"

class Logger {
    Logger() {}  // private so only the class can create itself
    static Logger* instance = NULL;

    public:
        static Instance() { // this is the primary instance and where it gets created
            if (!instance) {    // lazy loading does not create an instance if an instance is not required
                instance = new Logger();
            }
            return *instance;
        }

        void Logger::Log(const std::string& message, bool csv, bool db, bool cl) {
            if (csv) {
                std::ofstream csvFile("/data.csv", std::fstream::in | std::fstream::out | std::fstream::app);
                csvFile << message << std::endl;
                csvFile.close();
            }
            if (db) {
                // save within a folder
                std::ofstream csvFile("/db/data.csv", std::fstream::in | std::fstream::out | std::fstream::app);
                csvFile << message << std::endl;
                csvFile.close();
            }
            if (cl) {
                // this assumes we are saving data to both csv and the command line
                std::ofstream csvFile("/data.csv", std::fstream::in | std::fstream::out | std::fstream::app);
                csvFile << message << std::endl;
                csvFile.close();
                fstream file;
                file.open("/data.csv", ios::out);
                string line;
            
                // Backup streambuffers of  cout
                streambuf* stream_buffer_cout = cout.rdbuf();
                streambuf* stream_buffer_cin = cin.rdbuf();
            
                // Get the streambuffer of the file
                streambuf* stream_buffer_file = file.rdbuf();
            
                // Redirect cout to file
                cout.rdbuf(stream_buffer_file);
            
                // Redirect cout back to screen
                cout.rdbuf(stream_buffer_cout);
            
                file.close();
                return 0;
            }
            // std::cout << message << std::endl;
        }

        void operator=(const Logger&) = delete;


};

/* 

singleton is like a global variable that exists for each class
if you declare things as static, it can be accessed without having to call a new object of the singleton or even pushing it to the stack
once declared, it can be called directly

this instantiates an object that will write to a csv

scope the logger to it and log the velocity, position, ...

calculate the time and speed of beeline and patrol to see which one is better

create a method that feeds the data to Log()

implement this in the web app

*/