#include "racket.h"
#include <raylib.h>

class Ball
{
public:
    Ball(Bat &racket);
    void Update();
    void Draw() const;

private:
    float x;
    float y;
    float speedX;
    float speedY;
    int radius;
    Bat &racket;
};