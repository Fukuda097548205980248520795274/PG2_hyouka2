#pragma once
#include "./Class/Object/Object.h"
#include "./Class/Object/Bullet/Bullet.h"

class Player : public Object
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X軸の位置</param>
	/// <param name="posY">Y軸の位置</param>
	Player(float posX  , float posY);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 移動操作を行う
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void MoveOperation(const char* keys, const char* preKeys);

	/// <summary>
	/// 発射操作を行う
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void ShotOperation(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;


private:

	// 弾
	Bullet* bullet_[kBulletNum];

	// クールタイム
	int coolTime;
};

