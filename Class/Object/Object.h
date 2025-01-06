#pragma once
#include <Novice.h>
#include "Structure.h"
#include "Constant.h"

class Object
{
public:

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();

protected:

	// 位置
	struct Vec2 pos_;

	// 移動速度
	struct Vec2 vel_;

	// 図形の半径
	float radius;
};

