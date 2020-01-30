#pragma once
#include "BattleScene.h"
#include "GameLoadScene.h"
#include "GachaDisplayScene.h"
#include "LabyrinthScene.h"
#include "SaveAreaScene.h"

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