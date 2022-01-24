#pragma once
#include "CHARACTER.h"
class WHITE_KING :
    public CHARACTER
{
public:
    struct DATA {
        int   rightAnimId = 0;
        int   leftAnimId = 1;
        int   fallFlag = 0;
        int   jumpFlag = 0;
        float curWx = 0;
        float initVecUp;
        float initVecX = 0;
        float initVecY = 0;
        float ac = 1;
        float acCurTime = 0;
        float acInterval = 0;
        float gravity = 0;
        float alphaLowVal = 0;
        float damageTime = 0;
        float damageInterval = 0;
        char explosionCharaId = 0;
        int summonNumber = 0;
        COLOR damageColor;
        COLOR normalColor;
    };
private:
    DATA WhiteKing;
public:
    WHITE_KING(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
private:
    void Move();
    void Summons();
    void CollisionWithMap();
    void ChangeColor();
    void damage();
public:
    int hp() { return Chara.hp; }
};

