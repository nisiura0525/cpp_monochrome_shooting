#include "BLACK_WORLD.h"
#include"window.h"
#include"graphic.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
//#include"CHARACTER_MANAGER.h"
BLACK_WORLD::~BLACK_WORLD() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
}
void BLACK_WORLD::create() {
    Map = game()->container()->data().blackMap;
    Map.fileName = Map.fileName1;
}
void BLACK_WORLD::update() {
    //プレイヤーが画面の中央を超えた分だけスクロール
    Map.wx += game()->characterManager()->blackPlayer()->overCenterVx();
    if (Map.wx > Map.endWorldX) {
        Map.wx = Map.endWorldX;
    }
}
//void BLACK_WORLD::draw() {
//    int startcol = (int)map.wx / map.chipsize;//表示開始列
//    int endcol = startcol + map.dispcols;//表示終了列
//    for (int c = startcol; c < endcol; c++) {
//        float wx = (float)map.chipsize * c;
//        for (int r = 0; r < map.rows; r++) {
//            float wy = (float)map.chipsize * r;
//            char charaid = map.data[r * map.cols + c];
//            if (charaid >= '0' && charaid <= '9') {
//                float px = wx - map.wx;
//                float py = wy - map.wy;
//                if (charaid == '1')image(map.blockimg, px, py);
//                else if (charaid == '2')image(map.goalimg, px, py);
//            }
//            else if (charaid >= 'a' && charaid <= 'z') {
//                game()->charactermanager()->appear(charaid, wx, wy);
//                map.data[r * map.cols + c] = '.';
//            }
//        }
//    }
//}
//マップチップとキャラの当たり判定用関数群---------------------------------------------------
//　指定されたワールド座標( wx wy )が、マップチップの中にはいっているかチェックする
//bool map::collisioncheck(float wx, float wy) {
//    //ワールド座標からマップdataの列colと行rowを求める
//    int col = (int)wx / map.chipsize;
//    int row = (int)wy / map.chipsize;
//    //dataの範囲外は判定できないので除外
//    if ((col < 0) || (col >= map.cols) || (row < 0) || (row >= map.rows)) {
//        return false;
//    }
//    //次の記述で座標がマップチップの中に入っているか判定できる
//    if (map.data[col + row * map.cols] == '1') {
//        return true;
//    }
//    return false;
//}
////　マップチップとキャラの左辺が重なっているか
//bool map::collisioncharaleft(float wx, float wy) {
//    bool lefttop = collisioncheck(wx, wy);
//    bool leftbottom = collisioncheck(wx, wy + map.chipsize - 1);
//    return lefttop || leftbottom;
//}
////　マップチップとキャラの右辺が重なっているか
//bool map::collisionchararight(float wx, float wy) {
//    bool righttop = collisioncheck(wx + map.chipsize - 1, wy);
//    bool rightbottom = collisioncheck(wx + map.chipsize - 1, wy + map.chipsize - 1);
//    return righttop || rightbottom;
//}
////　マップチップとキャラの上辺が重なっているか
//bool map::collisioncharatop(float wx, float wy) {
//    bool topleft = collisioncheck(wx, wy);
//    bool topright = collisioncheck(wx + map.chipsize - 1, wy);
//    return topleft || topright;
//}
////　マップチップとキャラの下辺が重なっている、または、接しているか。ここだけ他と違う！
//bool map::collisioncharabottom(float wx, float wy) {
//    // wy + map.chipsizeをcheck関数に渡すことにより
//    // キャラがマップチップと接しているかチェックできる。
//    bool bottomleft = collisioncheck(wx, wy + map.chipsize);
//    bool bottomright = collisioncheck(wx + map.chipsize - 1, wy + map.chipsize);
//    return bottomleft || bottomright;
//}
//　マップチップと弾の当たり判定に使用
//bool map::collisionchararect(float wleft, float wtop, float wright, float wbottom) {
//    bool righttop = collisioncheck(wright, wtop);
//    bool rightbottom = collisioncheck(wright, wbottom);
//    bool lefttop = collisioncheck(wleft, wtop);
//    bool leftbottom = collisioncheck(wleft, wbottom);
//    return righttop || rightbottom || lefttop || leftbottom;
//}
//ウィンドウからのはみだし判定用---------------------------------------------------------
float BLACK_WORLD::wDispLeft() {
    return Map.wx - Map.chipSize;
}
float BLACK_WORLD::wDispRight() {
    return Map.wx + width;
}
