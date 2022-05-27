#include "DxLib.h"
#include "Transform.h"
#include "Gravity.h"
#include "stdlib.h"
#include "time.h"
#include "2DMetaball.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "a";

// ウィンドウ横幅
const int WIN_WIDTH = 600 * 2.5f;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400 * 2.5f;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言

	/*Triangle triangle1 = { {200,300},{100,500},{500,500} ,300};
	Triangle triangle2 = { {800,400},{700,450},{1050,600} ,300};*/

	//各点の重力を定義
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


	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

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


		// 描画処理
		/*DrawTriangle(triangle1);
		DrawTriangle(triangle2);*/
		/*for (int i = 0; i < 256; i++)
		{
			DrawCircle(dot[i]);
		}
		DrawCircle(circle1);*/

		metaball1.Draw();
		metaball2.Draw();


		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
