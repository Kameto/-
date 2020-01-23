#include "BaseGameScene.h"

GS_Name BaseGameScene::nowGameScene = GS_Name::eGameLoad;

BaseGameScene::BaseGameScene()
{

}

BaseGameScene::~BaseGameScene() 
{

}

GS_Name BaseGameScene::GetNowGameScene()
{
	return this->nowGameScene;
}

void BaseGameScene::ChangeGameScene()
{
	if (Keyboard::GetKey(KEY_INPUT_SPACE) == 1)
	{
		this->nowGameScene = (GS_Name)(((int)this->nowGameScene + 1) % (int)GS_Name::eSceneSize);
	}
}

void BaseGameScene::NowSceneDraw()
{
#ifdef _DEBUG
	switch (this->nowGameScene)
	{
	case GS_Name::eGameLoad:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eGameLoad));
		break;
	case GS_Name::eLabyrinth:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eLabyrinth));
		break;
	case GS_Name::eSaveArea:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eSaveArea));
		break;
	case GS_Name::eStatusCheck:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eStatusCheck));
		break;
	case GS_Name::eSaveDisplay:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eSaveDisplay));
		break;
	case GS_Name::eGachaDisplay:
		DrawExtendFormatString(0, 64, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eGachaDisplay));
		break;
	default:
		break;
	}
	DrawExtendFormatString(0, 96, 2.0, 2.0, 0xFFFFFF, "nextscene will  pushed for Åu space key Åv");
#else

#endif // _DEBUG
}