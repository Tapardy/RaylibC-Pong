#include <raylib.h>
#include "racket.h"
#include <iostream>

Bat::Bat()
{
    b_properties.y = 200;
    b_properties.x = 50;
    b_properties.posY = GetScreenHeight() / 2;
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
        b_properties.posY -= b_properties.speedY;
    }
    else if (IsKeyDown(KEY_S))
    {
        b_properties.posY += b_properties.speedY;
    }
}

Rectangle PlayerBat::GetRectangle()
{
    std::cout << "Player bat rectangle properties: "
              << "posX=" << b_properties.posX
              << ", posY=" << b_properties.posY
              << std::endl;

    return {b_properties.posX, b_properties.posY, b_properties.x, b_properties.y};
}

void PlayerBat::Draw() const
{
    DrawRectangle(b_properties.posX, b_properties.posY, b_properties.x, b_properties.y, RED);
}

// ENEMY AI CODE GOES HERE
EnemyBat::EnemyBat()
{
    b_properties.posX = 800;
}

void EnemyBat::Update()
{
    // Follow ball position, implement later
}

void EnemyBat::Draw() const
{
    DrawRectangle(b_properties.posX, b_properties.posY, b_properties.x, b_properties.y, RED);
}

Rectangle EnemyBat::GetRectangle()
{
    std::cout << "Enemy bat rectangle properties: "
              << "posX=" << b_properties.posX
              << ", posY=" << b_properties.posY
              << std::endl;

    return {b_properties.posX, b_properties.posY, b_properties.x, b_properties.y};
}