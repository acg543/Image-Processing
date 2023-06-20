#include "mean_blur_filter.h"

void MeanBlurFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
<<<<<<< HEAD
    
=======
    /*
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
    for (int img = 0; img < original.size(); img++) {

        *filtered[img] = *original[img];

        int width = original[img]->GetWidth();
        int height = original[img]->GetHeight();

        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {

                Color color(0,0,0);

<<<<<<< HEAD
                float red = 0, green = red, blue = red, alpha = 255;

                for (int i = x-1; i<= x+1; i++) {
                    for (int j = y-1; j <= y+1; j++) {

                        

                        if (i >= 0 && i < width && j >= 0 && j < height) {
                            color = original[img]->GetPixel(i, j);

                            red = red + (color.GetRed() * (1.0 / 9.0));
                            green = green + (color.GetGreen() * (1.0 / 9.0));
                            blue = blue + (color.GetBlue() * (1.0 / 9.0));

                        }

=======
                for (int i = x-1; i<= x+1; i++) {
                    for (int j = y-1; j <= y+1; j++) {

                        if (x >= 0 && x < width && y >= 0 && y < height) {
                            color = color + original[img]->GetPixel(i,j)*(1.0/9.0);
                        }
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
                    }
                }

                Color newColor(red, green, blue);
                filtered[img]->SetPixel(x, y, newColor);
            }
        }
    } 
<<<<<<< HEAD
    
=======
    */
>>>>>>> 277f5a951a0598a7649a4ae64697b2221f3f1c7e
}