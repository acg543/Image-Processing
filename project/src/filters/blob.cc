#include "blob.h"

double * FindBlob(Image orig, Image canny) {
    double output[3] = {0, 0, 0};


    //count number of white pixels in Canny Edge image
    int cannyCount = 0;
    for (int x = 0; x < canny.GetHeight(); x++) {
        for (int y = 0; y < canny.GetWidth(); y++) {

            Color pixel = canny.GetPixel(x, y);

            if (pixel.Red() == 1 && pixel.Green() == 1 && pixel.Blue() == 1) {
                cannyCount++;
            }
        }
    }

    //search original image for "orange" pixels 
    //then create another black and white image, black if pixel != orange, white if it does

    Image blob = orig;

    Color white = Color(1, 1, 1, 1);
    Color black = Color(0, 0, 0, 1);

    int blobCount = 0;
    double location[2] = {0, 0};

    for (int x = 0; x < orig.GetHeight(); x++) {
        for (int y = 0; y < orig.GetWidth(); y++) {
            Color pixel = orig .GetPixel(x, y);

            if (pixel.Red() > 0.9 && pixel.Green() > 0.4 && pixel.Blue() < 0.2) {
                blob.SetPixel(x, y, white);
                blobCount++;
                location[0] += x;
                location[1] += y;
            }
            else {
                blob.SetPixel(x, y, black);
            }
        }
    }

    //check number of white pixels against threshold
    if (blobCount / cannyCount < 10 ) {
        return output;
    }


    //find average position of white pixels (should be inside the robot)
    location[0] = location[0]/blobCount;
    location[1] = location[1]/blobCount;


    //setup output, 0: robot found, 1,2: pixel location of the robot
    output[0] = 1.0;
    output[1] = location[0];
    output[2] = location[1];

    return output;
}