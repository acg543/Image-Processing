#include "hysteresis.h"

void HysteresisFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {

    // Copy the input image into the output image
    for (int img = 0; img < original.size(); img++) {
        *filtered[img] = *original[img];

        // Loop through each pixel in the input image
        for (int i = 0; i < original[img]->GetWidth(); i++) {
            for (int j = 0; j < original[img]->GetHeight(); j++) {

                // Check if the current pixel is weak
                if (original[img]->GetPixel(i, j).GetRed() < 0.3) {
                
                    // Check bounds, if any surrounding pixels are strong, set current pixel to be strong
                    if (i > 0) {
                        if ((original[img]->GetPixel(i-1, j).GetRed() == 1) || (original[img]->GetPixel(i-1, j+1).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

                    if  (j > 0) {
                        if ((original[img]->GetPixel(i, j-1).GetRed() == 1) || (original[img]->GetPixel(i-1, j-1).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

                    if (i < original[img]->GetWidth()) {
                        if ((original[img]->GetPixel(i+1, j).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

                    if (j < original[img]->GetHeight()) {
                        if ((original[img]->GetPixel(i, j+1).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

                    if ((j < original[img]->GetHeight()) && (i < original[img]->GetWidth())) {
                        if ((original[img]->GetPixel(i+1, j+1).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

                    if (i > 0 && j > 0) {
                        if ((original[img]->GetPixel(i-1, j-1).GetRed() == 1))
                            filtered[img]->SetPixel(i, j, Color(1,1,1));
                        else
                            filtered[img]->SetPixel(i, j, Color(0,0,0));
                    }

        
                    }
                }
            }
        }
    }