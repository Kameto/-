#pragma once
#include "BaseScene.h"
#include "GameMgr.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	void UI_Update();
	void UI_Draw();
	void Update();
	void Draw();

private:
	GameMgr* gmgr;
};