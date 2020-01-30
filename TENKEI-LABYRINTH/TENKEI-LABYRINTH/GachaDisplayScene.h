#pragma once
#include "BaseGameScene.h"
class GachaDisplayScene :
	public BaseGameScene
{
public:
	GachaDisplayScene();
	~GachaDisplayScene();
	void GameUpdate();
	void GameDraw();
};