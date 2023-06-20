#include "non-max_suppression.h"
#include <iostream>

/*  used to make the final image have thin edges
    finds pixels with maximum value in edge directions
    sets less intense ones to 0
*/
void NonMaxSuppressionFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    for (int img = 0; img < original.size(); img++) {

        *filtered[img] = *original[img];

        for (int i = 0; i < original[img]->GetWidth(); i++) {
            for (int j = 0; j < original[img]->GetHeight(); j++) {

                int q = 255;
                int r = 255;

                //angle 0
                if (0 <= angle[i,j] < 22.5) || (157.5 <= angle[i,j] <= 180){
                    q = img[i, j+1];
                    r = img[i, j-1];
                }

                //angle 45
                else if (22.5 <= angle[i,j] < 67.5){
                    q = img[i+1, j-1];
                    r = img[i-1, j+1];
                }

                //angle 90
                else if (67.5 <= angle[i,j] < 112.5){
                    q = img[i+1, j];
                    r = img[i-1, j];
                }

                //angle 135
                else if (112.5 <= angle[i,j] < 157.5){
                    q = img[i-1, j-1];
                    r = img[i+1, j+1];
                }

                if (img[i,j] >= q) && (img[i,j] >= r){
                    Z[i,j] = img[i,j];
                }

                else {
                    Z[i,j] = 0;
                }

            }
        }
    }
}

/*

*/
