#include "sobel_filter.h"
#include <cmath>
#include <iostream>

void SobelFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {

    for (int img = 0; img < original.size(); img++) {

        Image floatImage = *original[img];
        Image imageX = *original[img];
        Image imageY = *original[img];
        Image final = *original[img];

        float gradient[final.GetWidth()][final.GetHeight()];

        int widthX = imageX.GetWidth();
        int heightX = imageX.GetHeight();

        int widthY = imageY.GetWidth();
        int heightY =imageY.GetHeight();

        int widthF = final.GetWidth();
        int heightF = final.GetHeight();

        //setting up floatImage to be used with float pixels
        Color color(0, 0, 0);
        for (int x = 0; x < widthX; x++) {
            for (int y = 0; y < heightX; y++) {

                color = original[img]->GetPixel(x, y);
                floatImage.setPixelFloat(x, y, color.GetRed() * 255);

            }
        }


        for (int x = 0; x < widthX; x++) {  //creating ImageX with KernelX
        
            for (int y = 0; y < heightX; y++) {
               
               float pixel = 0;
               float temp = 0;

               int a = 0;

               for (int i = x - 1; i <= x + 1; i++) {

                    int b = 0;

                    for (int j = y - 1; j <= y + 1; j++) {
                        
                        if (i >= 0 && i < widthX && j >= 0 && j < heightX) {
                            pixel = floatImage.getPixelFloat(i, j);
    
                            temp = temp + pixel * (kernelX[a][b]);

                        }
                        b++;
                    }
                    a++;
                }
                
                //imageX.SetPixel(x,y,Color(imageX.getPixelFloat(x,y), imageX.getPixelFloat(x,y), imageX.getPixelFloat(x,y)));
                if (temp > 255) {
                    temp = 255;
                }
                else if (temp < 0) {
                    temp = 0;
                }

                imageX.setPixelFloat(x, y, temp / 255);
            } 
            

        }



        for (int x = 0; x < widthY; x++) {  //creating ImageY with KernelY
            for (int y = 0; y < heightY; y++) {
           
                float pixel = 0;
                float temp = 0;
                int a = 0;

                for (int i = x - 1; i <= x + 1; i++) {

                     int b = 0;

                     for (int j = y - 1; j <= y + 1; j++) {
                         if (i >= 0 && i < widthY && j >= 0 && j < heightY) {
                             pixel = floatImage.getPixelFloat(i, j);

                             temp = temp + pixel * (kernelY[a][b]);

                         }
                         b++;
                     }
                     a++;
                }
                if (temp > 255) {
                    temp = 255;
                }
                else if (temp < 0) {
                    temp = 0;
                }
                
                imageY.setPixelFloat(x, y, temp / 255);
                
            }
        }

        


        for (int x = 0; x < widthF; x++) {  //combining the two Images into one and finding the intensity
            for (int y = 0; y < heightF; y++) {
                float pixelX = 0;
                float pixelY = 0;
                float newpixel = 0;

                pixelX = imageX.getPixelFloat(x, y);
                pixelY = imageY.getPixelFloat(x, y);

                newpixel = sqrt(pixelX * pixelX + pixelY * pixelY);
                std::cout << newpixel << std::endl;
                final.setPixelFloat(x, y, newpixel);

                gradient[x][y] = atan2(pixelY, pixelX); //DO NOT HAVE A WAY TO PASS THIS ON YET
            }   
        }

        for (int x = 0; x < widthF; x++) {  //turning final from floats to color
            for (int y = 0; y < heightF; y++) {
                int temp = final.getPixelFloat(x, y);
                Color color(temp, temp, temp);
                final.SetPixel(x, y, color);
            }
        }

        *filtered[img] = final;

    }
}