#include <raylib.h>
#include "ball.h"
#include "racket.h"
#include <iostream>

// Welcome to:
// OverEngineered Pong
// Where I make pong, but it is so much more difficult than it should've, for the sake of learning cpp

int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "OverEngineered Pong");

    const Color darkGreen = {20, 160, 133, 255};

    PlayerBat player;
    EnemyBat enemy;
    Rectangle rects[2] = {player.GetRectangle(), enemy.GetRectangle()};
    Ball ball(rects);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        player.Update();
        enemy.Update(ball.ballPosition);
        ball.Update();

        rects[0] = player.GetRectangle();
        rects[1] = enemy.GetRectangle();

        BeginDrawing();
        ClearBackground(darkGreen);

        player.Draw();
        enemy.Draw();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
