#pragma once
#include "BaseGameScene.h"
#include "CameraData.h"
#include "MapData.h"
#include "Player.h"

typedef class LabyrinthScene
	: public BaseGameScene
{
private:
	Player* myChara;

	/**** イベント処理用変数 ****/
	int eventCounter[5];
	bool eventFlag[5];
	/****************************/

public:
	LabyrinthScene();
	~LabyrinthScene();
	void GameUpdate();
	void GameDraw();
	void WorpUpdate();

}Lab_Scene;