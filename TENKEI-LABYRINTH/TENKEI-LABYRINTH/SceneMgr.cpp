#include"SceneMgr.h"

SceneMgr::SceneMgr()
{
	mpScene	 = nullptr;
	mpScene = new LoadScene();
	preScene = mpScene->GetNowScene();
	fadeCount = 255;
	fadeFlag = false;
	brightFlag = true;
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

void SceneMgr::FadeDisplay()
{
	SetDrawBright(fadeCount, fadeCount, fadeCount);
}

void SceneMgr::FadeCount()
{
	if(fadeFlag)
	{
		if (brightFlag)
		{
			if (fadeCount < 255)
			{
				fadeCount++;
			}
			else
			{
				brightFlag = false;
				fadeFlag = false;
			}
		}
		else
		{
			if (fadeCount > 0)
			{
				fadeCount--;
			}
			else
			{
				brightFlag = true;
				fadeFlag = false;
			}
		}
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

	DrawFormatString(1700, 0, 0xFFFFFF, "counter : %d", fadeCount);
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