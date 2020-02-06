#include "Player.h"

Player::Player()
	: BaseCharacter()
{
	SetDrawPoint(MapData::GetCenterX(), MapData::GetCenterY());
}

Player::Player(const int _x, const int _y)
	: BaseCharacter(_x, _y)
{
	SetDrawPoint(WND_WIDTH / 2, WND_HEIGHT / 2);
}

Player::~Player()
{

}

void Player::CharaUpdate()
{
	if (Keyboard::GetKey(KEY_INPUT_DOWN) > 0 && cy > (0 - 7)) { cy--; }
	else if (Keyboard::GetKey(KEY_INPUT_UP) > 0 && cy < (MapData::GetCenterY() * 2) - 5) { cy++; }
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0 && cx > (0 - 7)) { cx--; }
	else if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0 && cx < (MapData::GetCenterX() * 2) - 5) { cx++; }
}

void Player::CharaDraw()
{
	DrawGraph(dx, dy - 32, Graphics::GetPlayerGraphs("Chara0"), true);
	DrawBoxAA(dx, dy - 32, dx + 64, dy + 32, 0xFF0000, false, 2.0f);
}