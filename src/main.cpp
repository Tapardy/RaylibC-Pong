#include <raylib.h>
#include "ball.h"
#include "racket.h"

int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Bouncing Ball");

    const Color darkGreen = {20, 160, 133, 255};

    PlayerBat player;
    EnemyBat enemy;
    Ball ball(player);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // bat.Update();
        player.Update();
        enemy.Update();
        ball.Update();

        BeginDrawing();
        ClearBackground(darkGreen);
        // bat.Draw();
        player.Draw();
        enemy.Draw();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}