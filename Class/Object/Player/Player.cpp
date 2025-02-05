#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
Player::Player(float posX , float posY)
{
	// 位置
	SetPosX(posX);
	SetPosY(posY);

	// 移動速度
	SetVelX(0.0f);
	SetVelY(0.0f);

	// 図形の半径
	SetRadius(16.0f);

	// 弾
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i] = new Bullet();
	}

	// クールタイム
	coolTime = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
	// 弾
	for (int i = 0; i < kBulletNum; i++)
	{
		delete bullet_[i];
	}
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
	SetVelX(0.0f);
	SetVelY(0.0f);

	// Wキーで、上に移動する
	if (keys[DIK_W])
	{
		if (GetPosY() - GetRadius() > 0.0f)
		{
			SetVelY(-4.0f);
		}
	}

	// Aキーで、左に移動する
	if (keys[DIK_A])
	{
		if (GetPosX() - GetRadius() > 0.0f)
		{
			SetVelX(-4.0f);
		}
	}

	// Sキーで、下に移動する
	if (keys[DIK_S])
	{
		if (GetPosY() + GetRadius() < static_cast<float>(kScreenHeight))
		{
			SetVelY(4.0f);
		}
	}

	// Dキーで、右に移動する
	if (keys[DIK_D])
	{
		if (GetPosX() + GetRadius() < static_cast<float>(kScreenWidth))
		{
			SetVelX(4.0f);
		}
	}

	// 動かす
	SetPosX(GetPosX() + GetVelX());
	SetPosY(GetPosY() + GetVelY());
}

/// <summary>
/// 発射操作を行う
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::ShotOperation(const char* keys , const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}


	// クールタイムを進める
	if (coolTime > 0)
	{
		coolTime--;
	}

	// スペースキーで、弾を発射する
	if (keys[DIK_SPACE])
	{
		// クールタイムが完了次第
		if (coolTime <= 0)
		{
			for (int i = 0; i < kBulletNum; i++)
			{
				if (bullet_[i]->isShot_ == false)
				{
					// クールタイムを開始する
					coolTime = 10;

					bullet_[i]->Shot(GetPosX(), GetPosY(), 0.0f, -8.0f);

					break;
				}
			}
		}
	}


	// 発射されている弾を動かす
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i]->Move();
	}
}

/// <summary>
/// 描画する
/// </summary>
void Player::Draw()
{
	// プレイヤー
	Novice::DrawEllipse
	(
		static_cast<int>(GetPosX()), static_cast<int>(GetPosY()),
		static_cast<int>(GetRadius()), static_cast<int>(GetRadius()),
		0.0f, 0xFFFFFFFF, kFillModeSolid
	);


	// プレイヤーの弾
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i]->Draw();
	}
}