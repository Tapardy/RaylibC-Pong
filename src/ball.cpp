#include "ball.h"
#include "racket.h"
#include <raylib.h>
#include <iostream>

Ball::Ball(Bat &racket)
    : x(1000), y(1000), speedX(5), speedY(5), radius(15), racket(racket)
{
}
void Ball::Update()
{
    x += speedX;
    y += speedY;
    Vector2 ballposition = {x, y};
    Rectangle rect = racket.GetRectangle();
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if (CheckCollisionCircleRec(ballposition, radius, rect))
    {
        speedX *= -1.05;
        speedY *= -1.05;
        std::cout << "hit the thing";
    }

    // Makes it bounce on the screen sides by reverting the x/y location
    if ((x + radius >= screenWidth) || (x - radius <= 0))
    {
        speedX *= -1;
    }

    if ((y + radius >= screenHeight) || (y - radius <= 0))
    {
        speedY *= -1;
    }
}

void Ball::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}