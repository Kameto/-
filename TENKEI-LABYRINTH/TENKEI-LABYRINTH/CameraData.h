#pragma once
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
	static void SetMapCenter(const int _y, const int _x);
	static void UnsetData();
	static void Update(int &py, int &px);
	static int GetCameraX();
	static int GetCameraY();
};