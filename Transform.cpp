#include "Transform.h"
#include "DxLib.h"
#include "math.h"

void DrawVecBox(box box_)
{
	int color = GetColor(255, 255, 255);
	//時計周りに描画
	/*DrawLine(box_.x1, box_.y1, box_.x2, box_.y2, color, true);
	DrawLine(box_.x2, box_.y2, box_.x3, box_.y3, color, true);
	DrawLine(box_.x3, box_.y3, box_.x4, box_.y4, color, true);
	DrawLine(box_.x4, box_.y4, box_.x1, box_.y1, color, true);*/
}

void DrawCircle(circle circle_)
{
	int color = GetColor(255, 255, 255);
	DrawCircle(circle_.x, circle_.y, circle_.r, color, false);
}

void DrawTriangle(Triangle t)
{
	int color = GetColor(255, 255, 255);
	DrawLine(t.top.x, t.top.y, t.left.x, t.left.y, color, true);
	DrawLine(t.left.x, t.left.y, t.right.x, t.right.y, color, true);
	DrawLine(t.right.x, t.right.y, t.top.x, t.top.y, color, true);
}

void DrawMetaball(circle circle)
{
	dot dot[64];
	for (int i = 0; i < 64; i++)
	{
		float a = i;
		dot[i].x = cos(a/64 * PI * 2) * circle.r + circle.x;
		dot[i].y = sin(a/64 * PI * 2) * circle.r + circle.y;
	}

	for (int i = 0; i < 64; i++)
	{
		if (i <= 62 )
		{
			DrawLine(dot[i].x, dot[i].y, dot[i + 1].x, dot[i + 1].y, GetColor(255, 255, 255), true);
		}
		if (i == 63)
		{
			DrawLine(dot[63].x, dot[63].y, dot[0].x, dot[0].y, GetColor(255, 255, 255), true);
		}
	}
}

void giveGravityTriangle(Triangle t)
{
	Gravity(t.top.x, t.top.y, t.weight);
	Gravity(t.left.x, t.left.y, t.weight);
	Gravity(t.right.x, t.right.y, t.weight);
}

void gravitationTriangle(Triangle t1, Triangle t2)
{
	//各点の重力を定義
	/*Gravity t11(t1.top.x, t1.top.y, t1.weight);
	Gravity t12(t1.left.x, t1.left.y, t1.weight);
	Gravity t13(t1.right.x, t1.right.y, t1.weight);

	Gravity t21(t2.top.x, t2.top.y, t2.weight);
	Gravity t22(t2.left.x, t2.left.y, t2.weight);
	Gravity t23(t2.right.x, t2.right.y, t2.weight);

	t11.Gravitation(t22);
	t21.Gravitation(t11);

	t12.Gravitation(t22);
	t22.Gravitation(t12);

	t13.Gravitation(t23);
	t23.Gravitation(t13);*/

	/*t1 = { {t11.x,t11.y},{t12.x,t12.y}, {t13.x,t13.y},t1.weight };
	t2 ={{t21.x,t21.y},{t22.x,t22.y}, {t23.x,t23.y},t2.weight };*/
	t1.top.x += 1;
}

