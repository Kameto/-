#include "GameScene.h"

GameScene::GameScene()
{
	gmgr = new GameMgr();
	md = new MapData();
	cd = new CameraData();
}

GameScene::~GameScene()
{
	RELEASE(cd);
	RELEASE(md);
	RELEASE(gmgr);
}

void GameScene::UI_Update()
{

}

void GameScene::UI_Draw()
{

}

void GameScene::Update()
{
	UI_Update();
	gmgr->GameUpdate();
	BaseScene::ChangeScene(S_Name::eCredit);
}

void GameScene::Draw()
{
	UI_Draw();
	gmgr->GameDraw();
	BaseScene::DrawDebugSceneData();
}