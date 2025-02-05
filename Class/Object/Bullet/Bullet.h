#pragma once
#include "./Class/Object/Object.h"

class Bullet : public Object
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// 発射する
	/// </summary>
	/// <param name="posX">X軸の位置</param>
	/// <param name="posY">Y軸の位置</param>
	/// <param name="velX">X軸の移動速度</param>
	/// <param name="velY">Y軸の移動速度</param>
	void Shot(float posX, float posY, float velX, float velY);

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;

	// 発射しているかどうか（発射フラグ）
	int isShot_;
};