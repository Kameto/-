#pragma once
#include "GameLoadScene.h"
#include "LabyrinthScene.h"

class GameMgr
{
public:
	GameMgr();
	~GameMgr();
	void ChangeGameScene();
	void GameUpdate();
	void GameDraw();

	BaseGameScene* mpGameScene;
	GS_Name preGameScene;
};