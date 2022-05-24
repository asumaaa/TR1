#pragma once

struct box
{
	//ŽžŒv‰ñ‚è
	float x1;	
	float y1;
	float x2;	
	float y2;
	float x3;	
	float y3;
	float x4;	
	float y4;
};

struct circle
{
	float x;
	float y;
	float r;
};

void DrawVecBox(box box_);
void DrawCircle(circle circle_);