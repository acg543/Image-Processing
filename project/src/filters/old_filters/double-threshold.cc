#include "double-threshold.h"

DoubleThresholdFilter::DoubleThresholdFilter(float h, float l) {
    high_threshold = h;
    low_threshold = l;
}

void DoubleThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {

    // Define 3 different pixel outputs
    Color strong(1, 1, 1);
    Color weak(0.1, 0.1, 0.1);
    Color zero(0, 0, 0);

    // Copy the input image into the output image
    for (int img = 0; img < original.size(); img++) {
        *filtered[img] = *original[img];

        // Loop through each pixel in the input image
        for (int i = 0; i < original[img]->GetWidth(); i++) {
            for (int j = 0; j < original[img]->GetHeight(); j++) {

                Color pixel = original[img]->GetPixel(i, j);
                
                // Check current pixel against threshold values and set pixel accordingly
                if (pixel.GetRed() >= high_threshold)
                    filtered[img]->SetPixel(i, j, strong);

                else if (pixel.GetRed() < low_threshold) 
                    filtered[img]->SetPixel(i, j, zero);
                
                else 
                    filtered[img]->SetPixel(i, j, weak);
            }
        }
    }
}