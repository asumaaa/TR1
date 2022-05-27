#include "2DMetaball.h"
#include "DxLib.h"
#include "math.h"

Metaball::Metaball(float x, float y, float r, float weight)
{
	this->circle.x = x;
	this->circle.y = y;
	this->circle.r = r;
	this->circle.weight = weight;
	 
	for (int i = 0; i < 64; i++)
	{
		float a = i;
		this->dot[i].x = cos(a / 64 * PI * 2) * circle.r + circle.x;
		this->dot[i].y = sin(a / 64 * PI * 2) * circle.r + circle.y;
	}

	for (int i = 0; i < 64; i++)
	{
		this->gra[i].x = dot[i].x;
		this->gra[i].y = dot[i].y;
		this->gra[i].weight = weight;
	}
}

void Metaball::Draw()
{
	for (int i = 0; i < 64; i++)
	{
		if (i <= 62)
		{
			DrawLine(dot[i].x, dot[i].y, dot[i + 1].x, dot[i + 1].y, GetColor(255, 255, 255), true);
		}
		if (i == 63)
		{
			DrawLine(dot[63].x, dot[63].y, dot[0].x, dot[0].y, GetColor(255, 255, 255), true);
		}
	}
}

void Metaball::Gravitation(Metaball metaball2)
{
	for (int i = 0; i < 64; i++)
	{
		gra[i].Gravitation(metaball2.gra[63 - i]);
		dot[i].x = gra[i].x;
		gra[i].GravitationY(metaball2.gra[i]);
		dot[i].y = gra[i].y;
	}
}
