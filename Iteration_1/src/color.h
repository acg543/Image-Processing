#ifndef COLOR
#define COLOR



class Color {
    float red;
    float green;
    float blue;
    float alpha;

    public:

    Color();

    Color(float r, float g, float b);

    float GetRed();

    float GetGreen();
    
    float GetBlue();

    float GetAlpha();

    void SetRed(float a);

    void SetGreen(float a);

    void SetBlue(float a);

    void SetAlpha(float a);

    float GetLuminance();

};

#endif