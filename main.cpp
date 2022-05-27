#include "DxLib.h"
#include "Transform.h"
#include "Gravity.h"
#include "stdlib.h"
#include "time.h"
#include "2DMetaball.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "a";

// �E�B���h�E����
const int WIN_WIDTH = 600 * 2.5f;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400 * 2.5f;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	/*Triangle triangle1 = { {200,300},{100,500},{500,500} ,300};
	Triangle triangle2 = { {800,400},{700,450},{1050,600} ,300};*/

	//�e�_�̏d�͂��`
	/*Gravity t11(triangle1.top.x, triangle1.top.y, triangle1.weight);
	Gravity t12(triangle1.left.x, triangle1.left.y, triangle1.weight);
	Gravity t13(triangle1.right.x, triangle1.right.y, triangle1.weight);

	Gravity t21(triangle2.top.x, triangle2.top.y, triangle2.weight);
	Gravity t22(triangle2.left.x, triangle2.left.y, triangle2.weight);
	Gravity t23(triangle2.right.x, triangle2.right.y, triangle2.weight)*/;

	circle circle1{ 600, 400, 32, 200 };
	Gravity c(circle1.x, circle1.y, circle1.r);
	circle dot[256];
	Gravity d[256];
	for (int i = 0; i < 256; i++)
	{
		dot[i].x = rand() % WIN_WIDTH;
		dot[i].y = rand() % WIN_HEIGHT;
		dot[i].r = 4;
		dot[i].weight = 200;
	}
	for (int i = 0; i < 256; i++)
	{
		d[i].x = dot[i].x;
		d[i].y = dot[i].y;
		d[i].weight = dot[i].weight;
	}


	Metaball metaball1(300, 300, 128, 200);
	Metaball metaball2(900, 300, 128, 200);


	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		/*t11.Gravitation(t21);
		t12.Gravitation(t22);
		t13.Gravitation(t23);

		t21.Gravitation(t11);
		t22.Gravitation(t12);
		t23.Gravitation(t13);

		triangle1 = { {t11.x,t11.y},{t12.x,t12.y}, {t13.x,t13.y},triangle1.weight };
		triangle2 = { {t21.x,t21.y},{t22.x,t22.y}, {t23.x,t23.y},triangle2.weight };*/

		for (int i = 0; i < 256; i++)
		{
			d[i].Gravitation2(c);
			dot[i].x = d[i].x;
			dot[i].y = d[i].y;
		}

		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			metaball1.Gravitation(metaball2);
			metaball2.Gravitation(metaball1);
		}


		// �`�揈��
		/*DrawTriangle(triangle1);
		DrawTriangle(triangle2);*/
		/*for (int i = 0; i < 256; i++)
		{
			DrawCircle(dot[i]);
		}
		DrawCircle(circle1);*/

		metaball1.Draw();
		metaball2.Draw();


		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
