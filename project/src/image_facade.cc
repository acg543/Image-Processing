#include "image_facade.h"

double * ApplyImage (Image img) {
            
    //1: if 1 found robot, 2 3 4: direction vector, 5: distance
    double output[5] = {0, 0, 0, 0, 0};

    Image temp = img;


    //apply canny edge to image
    temp = ApplyCannyEdge(img);

    //check if robot is found and return average location of white pixels
    double * loca = FindBlob(img, temp);

    //if we didnt find the robot just exit, else find distance and direction to robot
    if (loca[0] == 0) {
        return output;
    }

    double * dirVec = FindDepth(img, loca);

    //setup output to return
    output[0] = 1.0;
    output[1] = dirVec[0];
    output[2] = dirVec[1];
    output[3] = dirVec[2];
    output[4] = dirVec[3];

    return output;
}