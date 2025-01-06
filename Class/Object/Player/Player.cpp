#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
Player::Player(float posX , float posY)
{
	// 位置
	pos_ = { posX , posY };

	// 移動速度
	vel_ = { 0.0f , 0.0f };

	// 図形の半径
	radius_ = 16.0f;
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{

}

/// <summary>
/// 移動操作を行う
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::MoveOperation(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}


	// 移動速度を初期化する
	vel_ = { 0.0f , 0.0f };

	// Wキーで、上に移動する
	if (keys[DIK_W])
	{
		if (pos_.y - radius_ > 0.0f)
		{
			vel_.y = -4.0f;
		}
	}

	// Aキーで、左に移動する
	if (keys[DIK_A])
	{
		if (pos_.x - radius_ > 0.0f)
		{
			vel_.x = -4.0f;
		}
	}

	// Sキーで、下に移動する
	if (keys[DIK_S])
	{
		if (pos_.y + radius_ < static_cast<float>(kScreenHeight))
		{
			vel_.y = 4.0f;
		}
	}

	// Dキーで、右に移動する
	if (keys[DIK_D])
	{
		if (pos_.x + radius_ < static_cast<float>(kScreenWidth))
		{
			vel_.x = 4.0f;
		}
	}

	// 動かす
	pos_.x += vel_.x;
	pos_.y += vel_.y;
}

/// <summary>
/// 描画する
/// </summary>
void Player::Draw()
{
	Novice::DrawEllipse
	(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, 0xFFFFFFFF, kFillModeSolid
	);
}