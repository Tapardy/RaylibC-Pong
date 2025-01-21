#include "racket.h"
#include <raylib.h>

class Ball
{
public:
    Ball(Rectangle (&rects)[2]);
    typedef void (*SideHitCallback)(bool);
    SideHitCallback onSideHit = nullptr;
    void Update();
    void Draw() const;
    Vector2 ballPosition;

private:
    Rectangle (*rects)[2];
    float x;
    float y;
    float speedX;
    float speedY;
    int radius;
};