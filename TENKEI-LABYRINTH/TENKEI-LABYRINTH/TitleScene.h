#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	void UI_Update();
	void UI_Draw();
	void Update();
	void Draw();
};