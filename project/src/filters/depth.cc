#include "depth.h"

double * FindDepth(Image img, double location[2]) {
    double output[4] = {0, 0, 0, 0};

    Image temp = img;

    //get that pixel to find the distance to it
    Color robot = temp.GetPixel(location[0], location[1]);

    //find direction vector
    double dirVec[3] = {0, 0, 0};

    dirVec[0] = robot.Red() - 0.5 * 2.0;
    dirVec[1] = robot.Green() - 0.5 * 2.0;
    dirVec[2] = robot.Blue() - 0.5 * 2.0;

    //find absolute value of direction vector
    double absDir = (sqrt((dirVec[0] * dirVec[0]) + (dirVec[1] * dirVec[1]) + (dirVec[2] * dirVec[2])));

    //find direction and distance
    double distance = (1.0 - absDir) * 50.0;
    double direction[3] = {dirVec[0] / absDir, dirVec[1] / absDir, dirVec[2] / absDir};

    
    output[0] = direction[0];
    output[1] = direction[1];
    output[2] = direction[2];
    output[3] = distance;

    return output;
}