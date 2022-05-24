#include "Transform.h"
#include "DxLib.h"

void DrawVecBox(box box_)
{
	int color = GetColor(255, 255, 255);
	//ŽžŒvŽü‚è‚É•`‰æ
	DrawLine(box_.x1, box_.y1, box_.x2, box_.y2, color, true);
	DrawLine(box_.x2, box_.y2, box_.x3, box_.y3, color, true);
	DrawLine(box_.x3, box_.y3, box_.x4, box_.y4, color, true);
	DrawLine(box_.x4, box_.y4, box_.x1, box_.y1, color, true);
}

void DrawCircle(circle circle_)
{
	int color = GetColor(255, 255, 255);
	DrawCircle(circle_.x, circle_.y, circle_.r, color, false);
}
