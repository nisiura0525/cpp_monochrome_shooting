#pragma once
#include "SCENE.h"
class STAGE :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        int stageClearImg = 0;
        int gameClearImg = 0;
        int pinchImg = 0;
        float backToTitleTime = 0;
        COLOR backColor;
        COLOR gameOverColor;
        COLOR stageClearColor;
        float logoPx = 0;
        float logoPy = 0;
    };
private:
    DATA Stage;
    void BackGround();
    void gameoverLogo(int img, const COLOR& color);
    void gameclearLogo(int img, const COLOR& color,float px,float py);
public:
    STAGE(class GAME* game) : SCENE(game) {}
    void create();
    void init();
    void proc();
    void update();
    void draw();
    void nextScene();
    void gameover();
    void gameclear();
};
