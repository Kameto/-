#include "Player.h"

Player::Player()
	: BaseCharacter()
{
	SetDrawPoint(WND_WIDTH / 2, WND_HEIGHT / 2);
}

Player::Player(const int _x, const int _y)
	: BaseCharacter(_x, _y)
{
	SetDrawPoint(WND_WIDTH / 2, WND_HEIGHT / 2);
}

Player::~Player()
{
	SetDrawPoint(0, 0);
}

void Player::CharaUpdate()
{
	if (Keyboard::GetKey(KEY_INPUT_UP) > 0) { cy--; }
	else if (Keyboard::GetKey(KEY_INPUT_DOWN) > 0) { cy++; }
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0) { cx--; }
	else if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0) { cx++; }

	MapData::SetPlayerPoint(cx, cy);
}

void Player::CharaDraw()
{
	DrawGraph(dx, dy - 32, Graphics::GetPlayerGraphs("Chara0"), true);
	//DrawBoxAA(dx, dy - 32, dx + 64, dy + 32, 0xFF0000, false, 2.0f);
	//DrawGraph(cx * 64, cy * 64, Graphics::GetPlayerGraphs("Chara0"), true);
}