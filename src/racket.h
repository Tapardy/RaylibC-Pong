#pragma once
#include <raylib.h>

struct BatProperties
{
    float y;
    float x;
    float posY;
    float posX;
    float speedY;
};

class Bat
{
public:
    Bat();
    virtual void Update() {}
    virtual void Draw() const {}
    virtual Rectangle GetRectangle() { return Rectangle{}; }

    // Needs to be accessible by both the inheritors
protected:
    BatProperties b_properties;
};

class PlayerBat : public Bat
{
public:
    PlayerBat();
    void Update() override;
    void Draw() const override;
    Rectangle GetRectangle() override;
};

class EnemyBat : public Bat
{
public:
    EnemyBat();
    void Update() override;
    void Draw() const override;
    Rectangle GetRectangle() override;
};