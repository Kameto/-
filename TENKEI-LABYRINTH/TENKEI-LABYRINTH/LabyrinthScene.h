#pragma once
#include "BaseGameScene.h"

typedef class LabyrinthScene
	: public BaseGameScene
{
public:
	LabyrinthScene();
	~LabyrinthScene();
	void GameUpdate();
	void GameDraw();
}Lab_Scene;