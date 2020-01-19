#pragma once
#include "BaseScene.h"
class CreditScene :
	public BaseScene
{
public:
	CreditScene();
	~CreditScene();
	void UI_Update();
	void UI_Draw();
	void Update();
	void Draw();
};