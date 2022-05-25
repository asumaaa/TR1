#pragma once
#include "Gravity.h"

#define PI 3.1415

//構造体
struct dot { float x; float y; };
struct box
{
	//時計回り
	dot topLeft;
	dot topRight;
	dot BottomRight;
	dot BottomLeft;
};
struct circle
{
	float x;
	float y;
	float r;
	float weight;
};
struct Triangle
{
	dot top;
	dot left;
	dot right;
	float weight;
};

//各描画関数
void DrawVecBox(box box_);
void DrawCircle(circle circle_);
void DrawTriangle(Triangle t);
void DrawMetaball(circle circle);	//64のベクトルで円を描画

//三角形の各点に重力を与える
void giveGravityTriangle(Triangle t);
//二つの三角形に万有引力を発生させる
void gravitationTriangle(Triangle t1, Triangle t2);