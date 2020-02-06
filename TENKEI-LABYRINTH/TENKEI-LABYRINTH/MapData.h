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

public:
	MapData();
	~MapData();
	static void Draw();
	static void SetMapData();
	static void UnsetData();
	static int GetCenterX();
	static int GetCenterY();
};