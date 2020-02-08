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

	/**** �C�x���g�����p�ϐ� ****/
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