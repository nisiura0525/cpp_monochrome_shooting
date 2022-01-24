#pragma once
#include "MAP.h"
class BLACK_WORLD :
	public MAP
{
public:
	enum CHARA_ID {
		PLAYER_ID = 'a',
		PLAYER_BULLET_ID = 'b',
		PUMPKIN_ID = 'c',
		BAT_ID = 'd',
		BAT_BULLET_ID = 'e',
		EXPLOSION_ID = 'f'
	};
public:
	BLACK_WORLD(class GAME* game) : MAP(game) {};
	~BLACK_WORLD();
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

