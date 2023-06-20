#include "threshold_filter.h"
#include "color.h"
#include <iostream>

ThresholdFilter::ThresholdFilter(float a) { //sets threshold
    threshold = a;
<<<<<<< HEAD
    
=======
    //std::cout << threshold << std::endl;
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
}
void ThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    for (int img = 0; img < original.size(); img++) {

        *filtered[img] = *original[img];

        for (int x = 0; x < original[img]->GetWidth(); x++) {
            for (int y = 0; y < original[img]->GetHeight(); y++) {

                Color pixel = original[img]->GetPixel(x, y);

<<<<<<< HEAD
                
                if (pixel.GetLuminance() < threshold) {
                    
=======
                //std::cout << this.threshold << std::endl;
                if (pixel.GetLuminance() < threshold) {
                    //std::cout << "test 1" << std::endl;
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
                    filtered[img]->SetPixel(x,y,Color(0,0,0));

                }
                else {
<<<<<<< HEAD
                    
=======
                    //std::cout << "test 2" << std::endl;
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
                    filtered[img]->SetPixel(x,y,Color(1,1,1));
                    
                }
            }
        }
    }
}