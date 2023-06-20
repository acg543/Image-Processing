/*! \mainpage Drone Search and Rescue
 *
 *
 * \section overview Project Overview
 *
 *  The goal of this project was to locate a robot using image processing, manuver a drone to the robot's position, and safely 
 *  deliver the robot to the hospital. In order to accomplish this goal, we created a web app that ran a search and rescue simulation.
 *  Our group solution to this problem was to split the program up into two seperate facades, the Image Processing Facade and the 
 *  Simulation Facade. The two different facades are described below and a link to a google doc with design images and explainations
 *  is provided: (https://docs.google.com/document/d/1PGUH_LuUtF2hQxzLnQbeMqXHQhbGQ9Fh9dzaN2NJ5KU/edit)
 *
 *
 * \subsection simulation Simulation Facade
 *
 *  The simulation Facade's main purpose was to serve as a base class that updated the simulation based on changes made in 
 *  subclasses. The Simulation class was home to the drone object that was used throughout the simulation, as well as an Update
 *  function that updated the simulation to it's current state and a FinishUpdate fucntion that updates the webapp display after
 *  all calls to Update are finished. The Simulation class also housed a virtual CreateEntity function that was implemented 
 *  in the EntityFactory class.
 *
 *
 * \subsection simulation How it Works
 *  
 *  The search and rescue simulation is implemented using a facade pattern. The simulation facade (simulation.h) holds a few
 *  overarching functions that deal with the program as a whole, Update and FinishUpdate for example. It also has a drone object
 *  which it inherits from the EntityFactory class (entity_factory.h) where it is initialized. The simulation class inherits from 
 *  EntityFactory and Drone (drone.h). As stated before, EntityFactory is a class that has the CreateEntity function which initializes
 *  picojson objects. This class includes all entity classes it will create, drone.h is the only file it includes in this implementation,
 *  however it can be extended to create other entities. To extend, the developer would need to create a new file to represent
 *  whichever entity they want to implement. Then they would need to implement the CreateEntity function to fit the needs of the new
 *  entity. The UML representation of EntityFactory can be seen as Figure 2 on the google doc provided above.
 *  The Drone class holds all functions dealing with updating the drone object except for handling drone movement.
 *  Movement is handled by a seperate Movement class (movement.h) and is implemented using the factory design pattern. The movement
 *  class only houses a single purely virtual function Move which is furthur implemeted in child classed. Figure 1 on the google doc
 *  shows this pattern in UML. The Beeline class (beeline.h) is one such class that implements the Move function. It's implementation
 *  moves the passed drone object in a straight line, from point A to point B. The drone movement system could be furthur extended
 *  to include other forms of drone movement. All that would need to be done would be create another class that inherits from 
 *  the Movement class and includes drone.h. The Move function would need to be implemented to the developers discretion and any other
 *  helper functions could be added.
 *
 *
 * \subsection image Image Processing Facade
 *  
 *  The image processing facade brings all of the relavent image filters needed to locate the robot in a given image. The facades input 
 *  is an image. It then applys filters to try to and locate the robot in this image. If it finds the robot then it returns the direction 
 *  and distance needed to travel to the robot. Specifically it uses three subclasses, ApplyCannyEdge, FindBlob, and Depth. The UML can 
 *  be found in Figure 3 of the Google Doc.
 *
 * 
 * \subsection image How it Works
 * 
 *  To centralize all components of image processing we used a facade pattern. Within this facade (iamge_facade.cc) there is a single 
 *  function ApplyImage. ApplyImage take in a single photo and returns an array with 5 indexes, the first index being a binary 1 or 0. 
 *  If it is 1 then the robot is found in the image and if it is 0 then the robot was not found. The second, third, and fourth indexes 
 *  are the x, y, and z direction to the found robot. The fith and final index is the direction from the drone to the robot. When ApplyImage
 *  takes in an image it first uses the function ApplyCannyEdge (found in canny_edge.h) which returns a modified image with all found edges
 *  outlined. ApplyImage then calls FindBlob (found in blob.h). FindBlob takes in two images, the first being the original image and the
 *  second being the modified canny edge image. FindBlob then counts the number of white pixels in the canny edge image and the number of
 *  orange pixels in the original image. It then compares these two numbers and if there is 10 times as many orange pixels than white then 
 *  we have found the robot. FindBlob then finds the average location of these orange pixels and returns that in an array with three indexes.
 *  X, y, and z coordinates respectively. ApplyImage then calls Depth (found in depth.h). Depth takes in an image and the location found 
 *  with FindBlob. It then performs the proper calculations to find the distance from the drone to the robot. ApplyImage finally sets up
 *  the ouput array with the correct data and returns it.
 * 
 * 
 * 
 * \section start Getting Started
 *
 *  To run the Simulation:
 *      - Navigate to the project folder
 *      - Type "make -j"
 *      - Type "./build/web-app 8081 web"
 *
 *  To run the Tests:
 *      - Navigate to the project folder
 *      - Type "make -j"
 *      - Type "./build/test-app"
 *
 *
 * \section contributions How to Contribute
 *
 *  In order to add additional features onto the project: \n
 *     - 1) Create a new feature branch following the naming convention "feature/(extension's name)" \n
 *     - 2) Pull all available code from the project main branch \n
 *     - 3) Merge the main branch code into the new feature branch \n
 *     - 4) Write code for the new addition, following google C++ coding standards and including any necessary files \n
 *     - 5) Push the code to the feature branch \n
 *     - 6) Create a new pull request from the feature branch to the develop branch \n
 *          - this requires 1 reviewer to look over the code and accept the request \n
 *     - 7) Create another pull request from the develop branch into the main branch \n
 *          - this requires 2 reviews to look over the code and accept the request \n
 *      
 *
 *
 *
 */