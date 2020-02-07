#pragma once
#include "BaseGameScene.h"
#include "CameraData.h"
#include "MapData.h"
#include "Player.h"

typedef class LabyrinthScene
	: public BaseGameScene
{
private:
public:
	LabyrinthScene();
	~LabyrinthScene();
	void GameUpdate();
	void GameDraw();
	Player* myChara;

}Lab_Scene;