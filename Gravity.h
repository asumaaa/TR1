#pragma once
#include "Transform.h"
#include "DxLib.h"
#include "cmath"

#define G 6.674	//���L���͒萔

//��̓_�ɏd�͂���������
class Gravity
{
public:
	float weight;	//����kg
	float x;		//�d�͂���������_�̍��W
	float y;
	float r;		//����
public:
	//�R���X�g���N�^
	Gravity();
	Gravity(float x,float y,float weight);

	float length(Gravity g);	//	������Ԃ�
	float VecGetX(Gravity g);	//���K��
	float VecGetY(Gravity g);	//���K��

	//
	void Gravitation(Gravity g);
	void GravitationY(Gravity g);
};