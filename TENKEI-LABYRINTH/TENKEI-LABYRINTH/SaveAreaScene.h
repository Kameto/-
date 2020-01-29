#pragma once
#include "BaseGameScene.h"

#define EFFECT_NUM 5

class SaveAreaScene :
	public BaseGameScene
{
public:
	SaveAreaScene();
	~SaveAreaScene();
	void GameUpdate();
	void GameDraw();

	int* effectCounter = new int[EFFECT_NUM];
};