#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Keyboard.h"
#include "MapData.h"
class BaseCharacter
{
public:
	int cx;// マップ用座標
	int cy;// マップ用座標
	int dx;// 描画座標
	int dy;// 描画座標

	BaseCharacter();
	BaseCharacter(const int _x, const int _y);
	~BaseCharacter();
	virtual void CharaUpdate() = 0;
	virtual void CharaDraw() = 0;

protected:
	void SetDrawPoint(const int _x, const int _y);
};