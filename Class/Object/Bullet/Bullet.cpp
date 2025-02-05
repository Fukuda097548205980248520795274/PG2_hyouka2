#include "Bullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet()
{
	// 発射しているかどうか（発射フラグ）
	isShot_ = false;

	// 位置
	SetPosX(0.0f);
	SetPosY(0.0f);

	// 移動速度
	SetVelX(0.0f);
	SetVelY(0.0f);

	// 図形の半径
	SetRadius(8.0f);
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
	SetPosX(posX);
	SetPosY(posY);

	// 移動速度
	SetVelX(velX);
	SetVelY(velY);
}

/// <summary>
/// 動かす
/// </summary>
void Bullet::Move()
{
	// 発射されている（発射フラグがtrueである）弾を動かす
	if (isShot_)
	{
		SetPosX(GetPosX() + GetVelX());
		SetPosY(GetPosY() + GetVelY());

		// 画面外に出たら消える（発射フラグがfalseになる）
		if (GetPosX() + GetRadius() < 0.0f || GetPosX() - GetRadius() > static_cast<float>(kScreenWidth) ||
			GetPosY() + GetRadius() < 0.0f || GetPosY() - GetRadius() > static_cast<float>(kScreenHeight))
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
			static_cast<int>(GetPosX()), static_cast<int>(GetPosY()),
			static_cast<int>(GetRadius()), static_cast<int>(GetRadius()),
			0.0f, 0xFFFFFFFF, kFillModeSolid
		);
	}
}