#include <raylib.h>
#include "racket.h"
#include <iostream>

Bat::Bat()
{
    b_properties.y = 200;
    b_properties.x = 50;
    b_properties.posY = GetScreenHeight() / 2 - 100; // 100 offset when drawn
    b_properties.posX = 0;
    b_properties.speedY = 10;
}

PlayerBat::PlayerBat()
{
}

void PlayerBat::Update()
{
    if (IsKeyDown(KEY_W))
    {
        b_properties.posY = std::max(0.0f, b_properties.posY - b_properties.speedY);
    }
    else if (IsKeyDown(KEY_S))
    {
        b_properties.posY = std::min(GetScreenHeight() - b_properties.y, b_properties.posY + b_properties.speedY);
    }
}

Rectangle PlayerBat::GetRectangle()
{
    return {b_properties.posX, b_properties.posY, b_properties.x, b_properties.y};
}

void PlayerBat::Draw() const
{
    DrawRectangle(b_properties.posX, b_properties.posY, b_properties.x, b_properties.y, RED);
}

// ENEMY AI CODE GOES HERE
EnemyBat::EnemyBat()
{
    b_properties.posX = GetScreenWidth() - 50;
}

void EnemyBat::Update(Vector2 ballPosition)
{
    float targetY = ballPosition.y - b_properties.y / 2;
    float smoothingFactor = 0.1f;
    float maxSpeed = 10.0f;

    // Make the AI more likely to lose, as it has less reaction time
    if (GetScreenWidth() / 2 > ballPosition.x)
    {
        float centerY = GetScreenHeight() / 2 - 100;
        // Dont lerp this, IMO it looks super odd
        float deltaMovement = (centerY - b_properties.posY);

        deltaMovement = std::max(-maxSpeed, std::min(deltaMovement, maxSpeed));
        b_properties.posY += deltaMovement;
    }
    else
    {
        float deltaMovement = (targetY - b_properties.posY) * smoothingFactor;

        deltaMovement = std::max(-maxSpeed, std::min(deltaMovement, maxSpeed));
        b_properties.posY += deltaMovement;

        // Checks so it cannot exit the screen
        b_properties.posY = std::max(0.0f, b_properties.posY);
        b_properties.posY = std::min(GetScreenHeight() - b_properties.y, b_properties.posY);
    }
}

void EnemyBat::Draw() const
{
    DrawRectangle(b_properties.posX, b_properties.posY, b_properties.x, b_properties.y, RED);
}

Rectangle EnemyBat::GetRectangle()
{
    return {b_properties.posX, b_properties.posY, b_properties.x, b_properties.y};
}