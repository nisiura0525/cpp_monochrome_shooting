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
    //�v���C���[����ʂ̒����𒴂����������X�N���[��
    Map.wx += game()->characterManager()->blackPlayer()->overCenterVx();
    if (Map.wx > Map.endWorldX) {
        Map.wx = Map.endWorldX;
    }
}
//void BLACK_WORLD::draw() {
//    int startcol = (int)map.wx / map.chipsize;//�\���J�n��
//    int endcol = startcol + map.dispcols;//�\���I����
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
//�}�b�v�`�b�v�ƃL�����̓����蔻��p�֐��Q---------------------------------------------------
//�@�w�肳�ꂽ���[���h���W( wx wy )���A�}�b�v�`�b�v�̒��ɂ͂����Ă��邩�`�F�b�N����
//bool map::collisioncheck(float wx, float wy) {
//    //���[���h���W����}�b�vdata�̗�col�ƍsrow�����߂�
//    int col = (int)wx / map.chipsize;
//    int row = (int)wy / map.chipsize;
//    //data�͈̔͊O�͔���ł��Ȃ��̂ŏ��O
//    if ((col < 0) || (col >= map.cols) || (row < 0) || (row >= map.rows)) {
//        return false;
//    }
//    //���̋L�q�ō��W���}�b�v�`�b�v�̒��ɓ����Ă��邩����ł���
//    if (map.data[col + row * map.cols] == '1') {
//        return true;
//    }
//    return false;
//}
////�@�}�b�v�`�b�v�ƃL�����̍��ӂ��d�Ȃ��Ă��邩
//bool map::collisioncharaleft(float wx, float wy) {
//    bool lefttop = collisioncheck(wx, wy);
//    bool leftbottom = collisioncheck(wx, wy + map.chipsize - 1);
//    return lefttop || leftbottom;
//}
////�@�}�b�v�`�b�v�ƃL�����̉E�ӂ��d�Ȃ��Ă��邩
//bool map::collisionchararight(float wx, float wy) {
//    bool righttop = collisioncheck(wx + map.chipsize - 1, wy);
//    bool rightbottom = collisioncheck(wx + map.chipsize - 1, wy + map.chipsize - 1);
//    return righttop || rightbottom;
//}
////�@�}�b�v�`�b�v�ƃL�����̏�ӂ��d�Ȃ��Ă��邩
//bool map::collisioncharatop(float wx, float wy) {
//    bool topleft = collisioncheck(wx, wy);
//    bool topright = collisioncheck(wx + map.chipsize - 1, wy);
//    return topleft || topright;
//}
////�@�}�b�v�`�b�v�ƃL�����̉��ӂ��d�Ȃ��Ă���A�܂��́A�ڂ��Ă��邩�B�����������ƈႤ�I
//bool map::collisioncharabottom(float wx, float wy) {
//    // wy + map.chipsize��check�֐��ɓn�����Ƃɂ��
//    // �L�������}�b�v�`�b�v�Ɛڂ��Ă��邩�`�F�b�N�ł���B
//    bool bottomleft = collisioncheck(wx, wy + map.chipsize);
//    bool bottomright = collisioncheck(wx + map.chipsize - 1, wy + map.chipsize);
//    return bottomleft || bottomright;
//}
//�@�}�b�v�`�b�v�ƒe�̓����蔻��Ɏg�p
//bool map::collisionchararect(float wleft, float wtop, float wright, float wbottom) {
//    bool righttop = collisioncheck(wright, wtop);
//    bool rightbottom = collisioncheck(wright, wbottom);
//    bool lefttop = collisioncheck(wleft, wtop);
//    bool leftbottom = collisioncheck(wleft, wbottom);
//    return righttop || rightbottom || lefttop || leftbottom;
//}
//�E�B���h�E����݂̂͂�������p---------------------------------------------------------
float BLACK_WORLD::wDispLeft() {
    return Map.wx - Map.chipSize;
}
float BLACK_WORLD::wDispRight() {
    return Map.wx + width;
}
