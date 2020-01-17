#pragma once
#include "BaseScene.h"
#include "CreditScene.h"
#include "GameScene.h"
#include "LoadScene.h"
#include "TitleScene.h"
#include "MyRand.h"

#include <thread>

class SceneMgr
{
public:
	SceneMgr(); 
	~SceneMgr();

 	void ChangeScene();
	void SceneUpdate();
	void SceneDraw();
	bool GetEndInput();

private:
	void FadeDisplay();
	void FadeCount();
	BaseScene* mpScene;
	S_Name preScene;
	int fadeCount;
	bool fadeFlag;
	bool brightFlag;
};