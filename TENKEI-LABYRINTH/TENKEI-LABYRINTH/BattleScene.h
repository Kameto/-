#pragma once
#include "BaseGameScene.h"
class BattleScene :
	public BaseGameScene
{
public:
	BattleScene();
	~BattleScene();
	void GameUpdate();
	void GameDraw();
};

