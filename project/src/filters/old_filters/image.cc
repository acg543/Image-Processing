#include <iostream>
#include <string>

// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "image.h"


Image::Image(){
    x = 0;
    y = 0;
    components = 4;
    image = new unsigned char[0];
}

Image::Image(int width, int height){
    x = width;
    y = height;
    components = 4;
    image = new unsigned char[width*height*4];
}

Image::Image(std::string filename){

    unsigned char *loadedImage = stbi_load(filename.c_str(), &x, &y, &components, STBI_rgb_alpha);
    components = 4;

    // Copy the image data into a local image buffer and free the image
    image = new unsigned char[x*y*components];
	std::copy(loadedImage, loadedImage + x*y*components, image); // copy allows us to copy one byte array to another
    stbi_image_free(loadedImage);
}

Image::Image(const Image& img){
    image = NULL;
    *this = img;
}

Image::~Image(){
    delete[] image;
}

void Image::operator=(const Image& img){
    if (image)
        delete[] this->image;
    this->x = img.x;
    this->y = img.y;
    this->components = img.components;
    this->image = new unsigned char[this->x * this->y * this->components];
    std::copy(img.image, img.image + x * y * components, this->image);
}

void Image::SaveAs(std::string filename){
    stbi_write_png(filename.c_str(), this->x, this->y, this->components, this->image, this->x*4);
}

int Image::GetHeight() const {
    return this->y;
}

int Image::GetWidth() const {
    return this->x;
}

int Image::GetComponents() const {
    return this->components;
}

Color Image::GetPixel(int a, int b){
    if (a < 0) { a = 0; }
    if (a >= this->x) { a = this->x - 1; }
    if (b < 0) { b = 0; }
    if (b >= this->y) { b = this->y - 1; }
    unsigned char* pixel = &image[(b * x + a) *4];
    return Color(pixel[0]*1.0/255.0,
               pixel[1]*1.0/255.0,
               pixel[2]*1.0/255.0);
}

void Image::SetPixel(int a, int b, Color input){
    unsigned char* pix = &image[(b * x + a) *4];
    pix[0] = input.GetRed()*255.0;
    pix[1] = input.GetGreen()*255.0;
    pix[2] = input.GetBlue()*255.0;
    pix[3] = input.GetAlpha()*255.0;
}

float Image::getPixelFloat(int a, int b) const {
    unsigned char* pixel = &image[(b * x + a)*4];
    return *reinterpret_cast<float*>(pixel);
}

void Image::setPixelFloat(int a, int b, float value){
    unsigned char* pixel = &image[(b * x + a)*4];
    *reinterpret_cast<float*>(pixel) = value;
}