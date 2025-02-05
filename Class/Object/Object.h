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

	// Setter
	void SetPosX(float posX) { this->pos_.x = posX; }
	void SetPosY(float posY) { this->pos_.y = posY; }
	void SetVelX(float velX) { this->vel_.x = velX; }
	void SetVelY(float velY) { this->vel_.y = velY; }
	void SetRadius(float radius) { this->radius_ = radius; }

	// Getter
	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetVelX() { return vel_.x; }
	float GetVelY() { return vel_.y; }
	float GetRadius() { return radius_; }


private:

	// 位置
	struct Vec2 pos_;

	// 移動速度
	struct Vec2 vel_;

	// 図形の半径
	float radius_;
};

