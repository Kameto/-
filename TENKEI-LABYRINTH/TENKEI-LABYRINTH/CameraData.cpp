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

void CameraData::Update(int &py, int &px)
{
	cX = mcX - px;
	cY = mcY - py;
}

void CameraData::SetMapCenter(const int _y, const int _x)
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