#include "ball.h"
#include "racket.h"
#include <raylib.h>
#include <iostream>

Ball::Ball(Rectangle (&rects)[2])
    : ballPosition{1000, 1000}, rects(&rects),
      x(GetScreenWidth() / 2), y(GetScreenHeight() / 2), speedX(GetRandomValue(0, 1) ? 5 : -5), speedY(5), radius(15)
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
        if (x + radius >= screenWidth)
        {
            if (onSideHit)
                onSideHit(false);

            // Spawn ball in the middle again
            x = screenWidth / 2;
            y = screenHeight / 2;
            speedX = (rand() % 2 == 0) ? 5 : -5;
            speedY = 5;
        }
        if (x - radius <= 0)
        {
            if (onSideHit)
                onSideHit(true);

            x = screenWidth / 2;
            y = screenHeight / 2;
            speedX = (rand() % 2 == 0) ? 5 : -5;
            speedY = 5;
        }
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
