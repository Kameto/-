#pragma once
#include "BaseCharacter.h"
class Player :
	public BaseCharacter
{
public:
	Player();
	Player(const int _x, const int _y);
	~Player();
	void CharaUpdate();
	void CharaDraw();
};

