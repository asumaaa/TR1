#pragma once
#include "Transform.h"
#include "DxLib.h"
#include "cmath"

#define G 6.674	//万有引力定数

//一つの点に重力を持たせる
class Gravity
{
public:
	float weight;	//質量kg
	float x;		//重力を持たせる点の座標
	float y;
	float r;		//距離
public:
	//コンストラクタ
	Gravity();
	Gravity(float x,float y,float weight);

	float length(Gravity g);	//	長さを返す
	float VecGetX(Gravity g);	//正規化
	float VecGetY(Gravity g);	//正規化

	//
	void Gravitation(Gravity g);
	void GravitationY(Gravity g);
};