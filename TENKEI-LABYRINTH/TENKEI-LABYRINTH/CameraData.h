#pragma once
#include "DefFunc.h"
class CameraData
{
private:
	static int cX;// �J����X���W
	static int cY;// �J����Y���W
	static int mcX;// �}�b�v���S
	static int mcY;// �}�b�v���S

public:
	CameraData();
	~CameraData();
	static void SetMapCenter(const int _x, const int _y);
	static void UnsetData();
	static void Update(int &px, int &py);
	static int GetCameraX();
	static int GetCameraY();
};