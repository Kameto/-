#pragma once
#include "BaseGameScene.h"
#include "CameraData.h"
#include "MapData.h"

typedef class GameLoadScene :
	public BaseGameScene
{
public:
	GameLoadScene();
	~GameLoadScene();
	void GameUpdate();
	void GameDraw();

}GL_Scene;