#include"SceneMgr.h"

SceneMgr::SceneMgr()
{
	mpScene	 = nullptr;
	mpScene = new LoadScene();
	preScene = mpScene->GetNowScene();
}

SceneMgr::~SceneMgr()
{
	RELEASE(mpScene);
}

void SceneMgr::ChangeScene()
{
	RELEASE(mpScene);

	switch (mpScene->GetNowScene())
	{
	case S_Name::eLoad:
		mpScene = new LoadScene();
		break;
	case S_Name::eTitle:
		mpScene = new TitleScene();
		break;
	case S_Name::eGame:
		mpScene = new GameScene();
		break;
	case S_Name::eCredit:
		mpScene = new CreditScene();
		break;
	default:
		break;

	}
}

void SceneMgr::SceneUpdate() 
{
	preScene = mpScene->GetNowScene();
	mpScene->Update();
	if (mpScene->GetNowScene() != preScene)
	{
		ChangeScene();
	}
}

void SceneMgr::SceneDraw()
{
	mpScene->Draw();
}

bool SceneMgr::GetEndInput()
{
	if (Keyboard::GetKey(KEY_INPUT_ESCAPE) == 1
		|| Keyboard::GetKey(KEY_INPUT_END) == 1
		|| (JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_START) == 1
			&& JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_BACK) == 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}