#pragma once
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
	static void SetMapCenter(const int _y, const int _x);
	static void UnsetData();
	static void Update(int &py, int &px);
	static int GetCameraX();
	static int GetCameraY();
};