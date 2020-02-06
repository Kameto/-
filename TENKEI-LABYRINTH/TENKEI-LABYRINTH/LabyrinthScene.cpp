#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eLabyrinth;
	dcX = MapData::GetCenterX();
	dcY = MapData::GetCenterX();
	myChara = new Player(MapData::GetCenterX(), MapData::GetCenterY());
}

LabyrinthScene::~LabyrinthScene()
{
	RELEASE(myChara);
	MapData::UnsetData();
	CameraData::UnsetData();
}

void LabyrinthScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eSaveArea);
	myChara->CharaUpdate();
	CameraData::Update(myChara->cy, myChara->cx);
}

void LabyrinthScene::GameDraw()
{
	/**** ƒ}ƒbƒv•`‰æ ****/
	MapData::Draw();
	myChara->CharaDraw();
	DrawFormatString(1200, 0, 0xFFFFFF, "mcX : %d\nmcY : %d", MapData::GetCenterX(), MapData::GetCenterY());
	DrawFormatString(1200, 64, 0xFFFFFF, "chara->cx : %d\nchara->cy : %d", myChara->cx, myChara->cy);
	/********************/

	BaseGameScene::NowSceneDraw();
}