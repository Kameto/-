#pragma once
#include "BaseScene.h"
class LoadScene :
	public BaseScene
{
public:
	LoadScene();
	~LoadScene();
	void UI_Update();
	void UI_Draw();
	void Update();
	void Draw();

};