#pragma once
#include "BaseGameScene.h"

class GameMgr
{
public:
	GameMgr();
	~GameMgr();
	void ChangeGameScene();
	void GameUpdate();
	void GameDraw();

private:
	BaseGameScene* mpGameScene;
	GS_Name preGameScene;
};