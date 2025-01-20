#pragma once
#include <raylib.h>

struct BatProperties
{
    float y;
    float x;
    float posY;
    float posX;
    float speedY;
};

class Bat
{
public:
    Bat();
    void Update();
    void Draw() const;
    Rectangle GetRectangle() const;

private:
    float y;
    float x;
    float posY;
    float posX;
    float speedY;
};
