#include "greyscale_filter.h"
#include <iostream>


void GreyScaleFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
<<<<<<< HEAD
    for (int img = 0; img < original.size(); img++) {

        *filtered[img] = *original[img];

        for (int x = 0; x < original[img]->GetWidth(); x++) {
            for (int y = 0; y < original[img]->GetHeight(); y++) {
                
                Color pixel = original[img]->GetPixel(x, y);

                float luminance = pixel.GetLuminance();
                pixel.SetRed(luminance);
                pixel.SetBlue(luminance);
                pixel.SetGreen(luminance);
                
=======
    for (int img = 0; original.size(); img++) {

        *filtered[img] = *original[img];

        for (int x = 0; x < original[img]->GetWidth(); x++) {
            for (int y = 0; y < original[img]->GetHeight(); y++) {

                Color pixel = original[img]->GetPixel(x, y);

                float luminance = pixel.GetLuminance();

                pixel.SetRed(luminance);
                pixel.SetBlue(luminance);
                pixel.SetGreen(luminance);
                pixel.SetAlpha(255);
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
                filtered[img]->SetPixel(x, y, pixel);
            }
        }
    }
}