#include "Gravity.h"
#include "cmath"
#include "math.h"
#include "stdlib.h"

Gravity::Gravity()
{
}

Gravity::Gravity(float x,float y, float weight)
{
	this->x = x;
	this->y = y;
	this->weight = weight;
}

float Gravity::length(Gravity g)
{
	float x2 = abs(x - g.x) * abs(x - g.x);
	float y2 = abs(y - g.y) * abs(y - g.y);
	return sqrt(x2 + y2);
}

float Gravity::VecGetX(Gravity g)
{
	return abs(g.x - x)/length(g);
}

float Gravity::VecGetY(Gravity g)
{
	return abs(g.y - y) / length(g);
}

void Gravity::Gravitation(Gravity g)
{
	if (abs(x - g.x) >= 100 || abs(y - g.y) >= 100)
	{
		if (x - g.x < 0)
		{
			x +=  ((weight * g.weight) / (length(g) * length(g))) * G * VecGetX(g);
		}
		else
		{
			x -=  ((weight * g.weight) / (length(g) * length(g))) * G * VecGetX(g);
		}
	}
	else if(abs(x - g.x) != 0/* || abs(y - g.y) != 0*/)
	{
		if (x - g.x < 0)
		{
			x += abs(x - g.x) /2;
		}
		else
		{
			x -= abs(x - g.x)/3;
		}
	}

	/*if (abs(x - g.x) >= 100|| abs(y - g.y) >=100)
	{
		if (y - g.y < 0)
		{
			y += ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
		else
		{
			y -=  ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
	}*/
}

void Gravity::GravitationY(Gravity g)
{
	if (abs(x - g.x) >= 100|| abs(y - g.y) >=100)
	{
		if (y - g.y < 0)
		{
			y += ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
		else
		{
			y -=  ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
	}
}

void Gravity::Gravitation2(Gravity g)
{
	if (abs(x - g.x) >= 100 || abs(y - g.y) >= 100)
	{
		if (x - g.x < 0)
		{
			x += ((weight * g.weight) / (length(g) * length(g))) * G * VecGetX(g);
		}
		else
		{
			x -= ((weight * g.weight) / (length(g) * length(g))) * G * VecGetX(g);
		}
	}
	if (abs(x - g.x) >= 100|| abs(y - g.y) >=100)
	{
		if (y - g.y < 0)
		{
			y += ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
		else
		{
			y -=  ((weight * g.weight) / (length(g) * length(g))) * G * VecGetY(g);
		}
	}
}


//float rx = abs(x - c.x);
//float ry = abs(y - c.y);
//
//GravityX = ((weight * weight_) / (rx * rx)) * G;
//GravityY = ((weight * weight_) / (ry * ry)) * G;
