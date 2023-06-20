#include "gaussian_filter.h"
#include <cmath>
#include <iostream>


void GaussianFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    
    float sigma = 2.0;
    float a = 2.0 * sigma * sigma, b = a;


    float sum = 0.0;

    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            a = sqrt(x * x + y * y);
            kernel[x + 2][y + 2] = (exp( - (a * a) / b)) / (M_PI * b);
            sum += kernel[x + 2][y + 2];
        }
    }

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            kernel[x][y] /= sum;
        }
    }




    for (int img = 0; img < original.size(); img++) {
        
        *filtered[img] = *original[img];

        int width = original[img]->GetWidth();
        int height = original[img]->GetHeight();


        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                
                Color color(0,0,0);
                float red = 0, blue = red, green = red;


                int a = 0;

                for (int i = x - 2; i <= x + 2; i++) {

                    int b = 0;
                    
                    for (int j = y - 2; j <= y + 2; j++) {

                        if (i >= 0 && i < width && j >= 0 && j < height) {
                            color = original[img]->GetPixel(i, j);
                            red = red + (color.GetRed() * (kernel[a][b]));
                            green = green + (color.GetGreen() * (kernel[a][b]));
                            blue = blue + (color.GetBlue() * (kernel[a][b]));
                        }

                        b++;

                    }

                    a++;

                }

                Color newColor(red, green, blue);
                filtered[img]->SetPixel(x, y, newColor);


            }
        }
    }
}