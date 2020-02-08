#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Graphics.h"
#include "MyRand.h"
#include <vector>
class MapData
{
private:
	static vector<vector<int>>mapdata;
	static int px;
	static int py;

public:
	MapData();
	~MapData();

	/**** �Q�b�^�[ ****/
	// �~�j�}�b�v�p�v���C���[���W�擾
	inline static void SetPlayerPoint(int& _x, int& _y)
	{
		px = _x;
		py = _y;
	}
	// �L��������p���W�擾
	inline static int CheckMapData(int _x, int _y)
	{
		return mapdata.at(_y).at(_x);
	}
	// �����l�̎擾
	static int GetCenterY();
	// �����l�̎擾
	static int GetCenterX();
	/******************/

	/**** ���� ****/
	static void Draw();
	/**************/

	/**** �ݒ� ****/
	static void SetMapData();
	static void UnsetData();
	/**************/
};