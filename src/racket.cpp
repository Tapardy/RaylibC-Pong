#include <raylib.h>
#include "racket.h"

Bat::Bat()
    : y(200), x(50), posY(0), posX(0), speedY(10)
{
    posY = GetScreenHeight() / 2;
}

void Bat::Update()
{
    if (IsKeyDown(KEY_W))
    {
        posY -= speedY;
    }
    else if (IsKeyDown(KEY_S))
    {
        posY += speedY;
    }
}

void Bat::Draw() const
{
    DrawRectangle(posX, posY, x, y, RED);
}

Rectangle Bat::GetRectangle() const
{
    Rectangle rect = {posX, posY, x, y};
    return rect;
}