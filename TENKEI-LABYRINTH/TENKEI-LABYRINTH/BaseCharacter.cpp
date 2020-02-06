#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	cx = 0;
	cy = 0;
	dx = 0;
	dy = 0;
}

BaseCharacter::BaseCharacter(const int _x, const int _y)
{
	cx = _x;
	cy = _y;
	dx = 0;
	dy = 0;
}

BaseCharacter::~BaseCharacter()
{
	cx = 0;
	cy = 0;
	dy = 0;
	dy = 0;
}

void BaseCharacter::SetDrawPoint(const int _x, const int _y)
{
	dx = _x;
	dy = _y;
}