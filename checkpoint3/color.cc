#include "color.h"



Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
    alpha = 1;
}

Color::Color(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;
    alpha = 1;
}

float Color::GetRed() {
    return red;
}

float Color::GetGreen() {
    return green;
}

float Color::GetBlue() {
    return blue;
}

float Color::GetAlpha() {
    return alpha;
}

void Color::SetRed(float a) {
    red = a;
}

void Color::SetGreen(float a) {
    green = a;
}

void Color::SetBlue(float a) {
    blue = a;
}

void Color::SetAlpha(float a) {
    alpha = 255;
}

float Color::GetLuminance() {
    return 0.2126*red + 0.7152*green + 0.0722*blue;
}