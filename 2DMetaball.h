#pragma once
#include "Gravity.h"
#include "Transform.h"

#define PI 3.1415

class Metaball
{
public:
	circle circle;
	dot dot[64];
	Gravity gra[64];

public:
	Metaball(float x, float y, float r, float weight);

public:
	void Draw();
	void Gravitation(Metaball metaball2);
};