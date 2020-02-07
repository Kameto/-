#include "CameraData.h"

int CameraData::cX;
int CameraData::cY;
int CameraData::mcX;
int CameraData::mcY;

CameraData::CameraData()
{
	UnsetData();
}

CameraData::~CameraData()
{
	UnsetData();
}

void CameraData::Update(int &px, int &py)
{
	cX = mcX - px;
	cY = mcY - py;
}

void CameraData::SetMapCenter(const int _x, const int _y)
{
	mcX = _x;
	mcY = _y;
}

void CameraData::UnsetData()
{
	cX = 0;
	cY = 0;
	mcX = 0;
	mcY = 0;
}

int CameraData::GetCameraX()
{
	return cX;
}

int CameraData::GetCameraY()
{
	return cY;
}