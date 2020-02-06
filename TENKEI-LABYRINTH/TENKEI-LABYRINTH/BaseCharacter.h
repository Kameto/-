#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Keyboard.h"
#include "MapData.h"
class BaseCharacter
{
public:
	int cx;// �}�b�v�p���W
	int cy;// �}�b�v�p���W
	int dx;// �`����W
	int dy;// �`����W

	BaseCharacter();
	BaseCharacter(const int _x, const int _y);
	~BaseCharacter();
	virtual void CharaUpdate() = 0;
	virtual void CharaDraw() = 0;

protected:
	void SetDrawPoint(const int _x, const int _y);
};