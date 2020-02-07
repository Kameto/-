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
	inline static void SetPlayerPoint(int& _x, int& _y)
	{
		px = _x;
		py = _y;
	}
	static int GetCenterY();
	static int GetCenterX();
	static void Draw();
	static void SetMapData();
	static void UnsetData();
};