#include "Player.h"

Player::Player()
	: BaseCharacter()
{
	SetDrawPoint(WND_WIDTH / 2, WND_HEIGHT / 2);
	SetGraphSize(Graphics::GetPlayerGraphs("Chara0"));
	areaFlag = false;
}

Player::Player(const int _x, const int _y)
	: BaseCharacter(_x, _y)
{
	SetDrawPoint(WND_WIDTH / 2, WND_HEIGHT / 2);
	areaFlag = false;
}

Player::~Player()
{
	SetDrawPoint(0, 0);
}

void Player::SetFlag(const bool flag)
{
	areaFlag = flag;
}

void Player::CharaUpdate()
{
	// 向き変更入力処理
	if (Keyboard::GetKey(KEY_INPUT_UP) > 0) { moveDir = Dir::eUp; }
	else if (Keyboard::GetKey(KEY_INPUT_DOWN) > 0) { moveDir = Dir::eDown; }
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0) { moveDir = Dir::eLeft; }
	else if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0) { moveDir = Dir::eRight; }
	else { moveDir = Dir::eNone; }

	if (areaFlag)
	{
		switch (moveDir)
		{
		case Dir::eUp:
			dy -= 3;
			break;
		case Dir::eDown:
			dy += 3;
			break;
		case Dir::eLeft:
			dx -= 3;
			break;
		case Dir::eRight:
			dx += 3;
			break;
		case Dir::eNone:
			break;
		default:
			break;
		}
	}
	else
	{
		// マップの判定処理
		if (!BaseCharacter::CheckHitBody())
		{
			moveDir = Dir::eNone;
		}

		// 移動処理
		switch (moveDir)
		{
		case Dir::eUp:
			cy--;
			break;
		case Dir::eDown:
			cy++;
			break;
		case Dir::eLeft:
			cx--;
			break;
		case Dir::eRight:
			cx++;
			break;
		case Dir::eNone:
			break;
		default:
			break;
		}

		// プレイヤーの位置取得
		MapData::SetPlayerPoint(cx, cy);
	}
}

void Player::CharaDraw()
{
	DrawRotaGraph(dx + 28, dy, 1.0, 0.0, Graphics::GetPlayerGraphs("Chara0"), true);
}