#ifndef IMAGE
#define IMAGE

#include <string>
#include "color.h"

class Image{
    int x;
    int y;
    int components;
    unsigned char* image;

    public:

    Image();

    Image(int height, int width);

    Image(std::string filename);

    Image(const Image& vec);

    ~Image();

    void operator=(const Image& img);

    void SaveAs(std::string filename);

    int GetHeight() const;

    int GetWidth() const;

    int GetComponents() const;

    Color GetPixel(int a, int b);

    void SetPixel(int a, int b, Color input);

    float getPixelFloat(int a, int b) const;

    void setPixelFloat(int a, int b, float value);

};


#endif