#include <raylib.h>
#include "ball.h"
#include "racket.h"
#include <iostream>

// Welcome to:
// OverEngineered Pong
// Where I make pong, but it is so much more difficult than it should've, for the sake of learning cpp

int playerScore = 0;
int enemyScore = 0;

void handleSideHit(bool leftSide)
{
    if (leftSide)
    {
        enemyScore++;
        std::cout << "enemy scored";
    }
    else
    {
        playerScore++;
        std::cout << "enemy scored";
    }
}

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

    // Subscribe to the score function
    ball.onSideHit = handleSideHit;

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
        int playerScoreWidth = MeasureText(TextFormat("%d", playerScore), 100);
        int enemyScoreWidth = MeasureText(TextFormat("%d", enemyScore), 100);

        DrawText(TextFormat("%d", playerScore), 300 - playerScoreWidth / 2, 0, 100, WHITE);
        DrawText(TextFormat("%d", enemyScore), screenWidth - 300 - enemyScoreWidth / 2, 0, 100, WHITE);

        player.Draw();
        enemy.Draw();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
