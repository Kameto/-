#pragma once
#include "BaseGameScene.h"
#include <string>

#define THIS_EVE 5

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
	int eventCount[THIS_EVE];
	bool eventFlag[THIS_EVE];
	double roolCount;
	bool roolFlag;
};