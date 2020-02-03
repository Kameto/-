#pragma once
#include "BaseGameScene.h"
#include <string>

class GachaDisplayScene :
	public BaseGameScene
{
public:
	GachaDisplayScene();
	~GachaDisplayScene();
	void GameUpdate();
	void GameDraw();

	int nowStone;
	int stoneCount;
	double roolCount;
	bool roolFlag;
};