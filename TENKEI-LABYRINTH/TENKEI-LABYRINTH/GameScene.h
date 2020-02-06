#pragma once
#include "BaseScene.h"
#include "CameraData.h"
#include "GameMgr.h"
#include "MapData.h"

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
	CameraData* cd;
	GameMgr* gmgr;
	MapData* md;
};