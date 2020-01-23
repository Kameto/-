#pragma once
#include "BaseGameScene.h"

typedef class GameLoadScene :
	public BaseGameScene
{
public:
	GameLoadScene();
	~GameLoadScene();
	void GameUpdate();
	void GameDraw();

}GL_Scene;