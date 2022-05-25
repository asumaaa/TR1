#pragma once
#include "Gravity.h"

#define PI 3.1415

//�\����
struct dot { float x; float y; };
struct box
{
	//���v���
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

//�e�`��֐�
void DrawVecBox(box box_);
void DrawCircle(circle circle_);
void DrawTriangle(Triangle t);
void DrawMetaball(circle circle);	//64�̃x�N�g���ŉ~��`��

//�O�p�`�̊e�_�ɏd�͂�^����
void giveGravityTriangle(Triangle t);
//��̎O�p�`�ɖ��L���͂𔭐�������
void gravitationTriangle(Triangle t1, Triangle t2);