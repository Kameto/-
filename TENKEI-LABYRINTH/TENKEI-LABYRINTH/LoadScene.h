#pragma once
#include "BaseScene.h"
#include <thread>
#include <mutex>

class LoadScene :
	public BaseScene
{
private:
	bool loadFlag;
	int fade;
	int time;
	vector<thread>vThs;

public:
	LoadScene();
	~LoadScene();
	void UI_Update();
	void UI_Draw();
	void Update();
	void Draw();
};