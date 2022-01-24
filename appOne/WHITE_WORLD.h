#pragma once
#include "MAP.h"
class WHITE_WORLD :
    public MAP
{
public:
    WHITE_WORLD(class GAME* game) : MAP(game) {};
    ~WHITE_WORLD();
    void create();//
    //void init();
    void update();
    //virtual void draw();
    //virtual float wx() { return Map.wx; }
    //virtual float wy() { return Map.wy; }
    //virtual int chipSize() { return Map.chipSize; }
    //マップチップとキャラの当たり判定に使用する関数群---------------------------------------
    //MAPから継承
    //ウィンドウ枠からのはみだし判定用---------------------------------------------------
    float wDispLeft();
    float wDispRight();
};

