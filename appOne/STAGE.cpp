#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAP.h"
#include"BLACK_WORLD.h"
#include"WHITE_WORLD.h"
#include"CHARACTER_MANAGER.h"
#include"FADE.h"
#include "STAGE.h"
#include"BLACK_STAGE.h"
#include"WHITE_STAGE.h"

void STAGE::create(){
    Stage = game()->container()->data().stage;
}
void STAGE::init() {
    Stage.backToTitleTime = game()->container()->data().stage.backToTitleTime;
    game()->blackStage()->init();
    game()->whiteStage()->init();
    game()->characterManager()->bulletInit();
    game()->fade()->inTrigger();
}
void STAGE::proc() {
    update();
    draw();
    nextScene();
}
void STAGE::update() {
   //game()->characterManager()->update();
    game()->blackStage()->update();
    game()->whiteStage()->update();
    game()->characterManager()->bulletUpdate();
}
void STAGE::draw(){
    BackGround();
    game()->characterManager()->bulletDraw();
    game()->fade()->draw();
    game()->whiteStage()->draw();
    game()->blackStage()->draw();
    if (game()->characterManager()->whitePlayer()->life() <= 0 &&
        game()->characterManager()->blackPlayer()->life() <= 0)
        gameoverLogo(Stage.pinchImg,Stage.gameOverColor);
    /*
    if (game()->characterManager()->whiteKing()->hp() == 0) {
        gameclearLogo(Stage.gameClearImg,Stage.stageClearColor, (width - 800) / 2, height /( 2 + 100));
    }
    if (game()->characterManager()->blackKing()->hp() == 0) {
        gameclearLogo(Stage.gameClearImg, Stage.stageClearColor, (width - 800) / 2,height /(2 -100));
    }
    */
#ifdef _DEBUG
    fill(255);
    printSize(50);
    print(game()->characterManager()->whitePlayer()->life());
    print(game()->characterManager()->blackPlayer()->life());
#endif
}
void STAGE::BackGround(){
    clear();
    rectMode(CORNER);
    imageColor(Stage.backColor);
    image(Stage.backImg, 0, 0);
}
void STAGE::gameoverLogo(int img, const COLOR& color) {
    imageColor(color);
    image(img, Stage.logoPx, Stage.logoPy);
    Stage.backToTitleTime -= delta;
}
void STAGE::gameclearLogo(int img, const COLOR& color,float px,float py) {
    imageColor(color);
    image(img, Stage.logoPx, Stage.logoPy);
    Stage.backToTitleTime -= delta;
}
void STAGE::nextScene() {
    game()->blackStage()->nextScene();
    game()->whiteStage()->nextScene();
    gameover();
    gameclear();
} 
void STAGE::gameover() {
    if (Stage.backToTitleTime <= 0) {
        game()->fade()->outTrigger();
    }
    if (game()->fade()->outEndFlag()) {
        game()->setCurScene(game()->title());   
    }
}
void STAGE::gameclear() {
    if (Stage.backToTitleTime <= 0) {
        game()->fade()->outTrigger();
    }
    if (game()->fade()->outEndFlag()) {
        game()->setCurScene(game()->title());
    }
}
