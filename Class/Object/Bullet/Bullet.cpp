#include "Bullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet()
{
	// 発射しているかどうか（発射フラグ）
	isShot_ = false;

	// 位置
	pos_ = { 0.0f , 0.0f };

	// 移動速度
	vel_ = { 0.0f , 0.0f };

	// 図形の半径
	radius_ = 8.0f;
}

/// <summary>
/// 発射する
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
/// <param name="velX">X軸の移動速度</param>
/// <param name="velY">Y軸の移動速度</param>
void Bullet::Shot(float posX , float posY , float velX , float velY)
{
	// 発射する（発射フラグをtrueにする）
	isShot_ = true;

	// 位置
	pos_ = { posX , posY };

	// 移動速度
	vel_ = { velX , velY };
}

/// <summary>
/// 動かす
/// </summary>
void Bullet::Move()
{
	// 発射されている（発射フラグがtrueである）弾を動かす
	if (isShot_)
	{
		pos_.x += vel_.x;
		pos_.y += vel_.y;

		// 画面外に出たら消える（発射フラグがfalseになる）
		if (pos_.x + radius_ < 0.0f || pos_.x - radius_ > static_cast<float>(kScreenWidth) ||
			pos_.y + radius_ < 0.0f || pos_.y - radius_ > static_cast<float>(kScreenHeight))
		{
			isShot_ = false;
		}
	}
}

/// <summary>
/// 描画する
/// </summary>
void Bullet::Draw()
{
	// 発射されている（発射フラグがtrueである）とき
	if (isShot_)
	{
		Novice::DrawEllipse
		(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, 0xFFFFFFFF, kFillModeSolid
		);
	}
}