#include "ball.h"
#include "racket.h"
#include <raylib.h>
#include <iostream>

Ball::Ball(Rectangle (&rects)[2])
    : ballPosition{1000, 1000}, rects(&rects),
      x(1000), y(1000), speedX(5), speedY(5), radius(15)
{
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    ballPosition = {x, y};
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    for (auto &&rect : *rects)
    {
        if (CheckCollisionCircleRec(ballPosition, radius, rect))
        {
            speedX *= -1.05;
            // Positive value, otherwise it always reverses the direction the ball goes
            speedY *= 1.05;
            std::cout << "hit the thing";
        }
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
