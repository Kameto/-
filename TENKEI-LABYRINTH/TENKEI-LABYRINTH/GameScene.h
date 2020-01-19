#pragma once
#include "BaseScene.h"
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

};

