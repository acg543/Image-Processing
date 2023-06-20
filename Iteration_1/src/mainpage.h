/*! \mainpage The Canny Edge Detection Project
 *
 * \section intro_sec Introduction
 *
 * Canny edge detection is a multi-step image filter that detects only the outlines of an image. It is the culmination of 6
 * individual filters, applied one after another until only the edges of the original image are pronounced.
 *
 *
 * \section how_works_sec How it Works:
 *  
 *  Each of the below filters are applied to an image. Starting with a Greyscale Filter and ending with a Hysteresis Filter. 
 *  The resulting image is a Canny Edge Detection Filtered image.
 *
 *  1. Greyscale
 *  2. Gaussian blur
 *  3. Sobel filter
 *  4. Non-max suppression
 *  5. Double threshold
 *  6. Hysteresis
 *
 * \section build/run_sec Building & Running the Program
 *
 * To build the program, run the following command:
 *      % make
 *
 * To run the program, run the following command:
 *      % ./image_processor *****finish this part******
 *
 * 
 * \section classes_sec The Main Classes
 *
 *  Image - Resposible for all things regarding the image
 *  Filter - Contains the Filter constructor and pure virtual definition of Apply() [used to apply filters to images]
 *  Color - Responsible for accessing/changing pixel RGBA values
 *  
 *
 *
 *
 *
 *
 *
 *
 *
 * \section extend_sec Extending the Project
 *
 * To extend this project or add new filters, follow these steps:
 *
 *  1) Create 2 new files, "new_filter.h" & "new_filter.cc" -- "new_filter" is just a placeholder name
 *  2) Add a class definition with an Apply() method in the ".h" file
 *  3) Implement the class in the ".cc" file
 *  4) Make sure the new_filter class inherits from the "Filter" class
 *  5) Add an #include statement in main.cc
 *
 *
 */