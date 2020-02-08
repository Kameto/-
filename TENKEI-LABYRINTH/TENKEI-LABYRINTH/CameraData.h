#pragma once
#include "DefFunc.h"
class CameraData
{
private:
	static int cX;// カメラX座標
	static int cY;// カメラY座標
	static int mcX;// マップ中心
	static int mcY;// マップ中心

public:
	CameraData();
	~CameraData();
	static void SetMapCenter(const int _x, const int _y);
	static void UnsetData();
	static void Update(int &px, int &py);
	static int GetCameraX();
	static int GetCameraY();
};