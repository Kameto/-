#include "BaseScene.h"

S_Name BaseScene::nowScene = S_Name::eLoad;

BaseScene::BaseScene()
{

}

BaseScene::~BaseScene()
{

}

S_Name BaseScene::GetNowScene()
{
	return this->nowScene;
}

void BaseScene::UpdateDebugSceneData(S_Name nextScene)
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		this->nowScene = nextScene;
	}
}

void BaseScene::DrawDebugSceneData()
{
#ifdef _DEBUG
	switch (this->nowScene)
	{
	case S_Name::eLoad:
		DrawExtendFormatString(0, 0, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eLoad));
		break;
	case S_Name::eTitle:
		DrawExtendFormatString(0, 0, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eTitle));
		break;
	case S_Name::eGame:
		DrawExtendFormatString(0, 0, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eGame));
		break;
	case S_Name::eCredit:
		DrawExtendFormatString(0, 0, 2.0, 2.0, 0xFFFFFF, "nowScene : %s", STR(S_Name::eCredit));
		break;
	default:
		break;
	}
	DrawExtendFormatString(0, 32, 2.0, 2.0, 0xFFFFFF, "nextscene will  pushed for Åu enter key Åv");
#else

#endif // _DEBUG
}