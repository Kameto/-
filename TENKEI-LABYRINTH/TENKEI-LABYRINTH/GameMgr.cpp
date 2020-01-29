#include "GameMgr.h"

GameMgr::GameMgr()
{
	this->mpGameScene = nullptr;
	this->mpGameScene = new GameLoadScene();
	this->preGameScene = this->mpGameScene->GetNowGameScene();
}

GameMgr::~GameMgr()
{
	RELEASE(this->mpGameScene);
}

void GameMgr::ChangeGameScene()
{
	RELEASE(this->mpGameScene);

	switch (this->mpGameScene->GetNowGameScene())
	{
	case GS_Name::eGameLoad:
		this->mpGameScene = new GameLoadScene();
		break;
	case GS_Name::eLabyrinth:
		this->mpGameScene = new LabyrinthScene();
		break;
	case GS_Name::eSaveArea:
		this->mpGameScene = new SaveAreaScene();
		break;
	case GS_Name::eStatusCheck:
		break;
	case GS_Name::eSaveDisplay:
		break;
	case GS_Name::eGachaDisplay:
		break;
	default:
		break;
	}
}

void GameMgr::GameUpdate() 
{
	this->preGameScene = this->mpGameScene->GetNowGameScene();
	this->mpGameScene->GameUpdate();
	if (this->preGameScene != this->mpGameScene->GetNowGameScene())
	{
		this->ChangeGameScene();
	}
}

void GameMgr::GameDraw()
{
	this->mpGameScene->GameDraw();
}