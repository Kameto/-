#pragma once
#include "BaseCharacter.h"
class Player :
	public BaseCharacter
{
private:
	bool areaFlag;

public:
	Player();
	Player(const int _x, const int _y);
	~Player();
	void SetFlag(const bool flag);
	void CharaUpdate();
	void CharaDraw();
};

