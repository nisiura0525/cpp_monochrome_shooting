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
    //�}�b�v�`�b�v�ƃL�����̓����蔻��Ɏg�p����֐��Q---------------------------------------
    //MAP����p��
    //�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
    float wDispLeft();
    float wDispRight();
};

