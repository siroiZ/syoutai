//ウィンドウを表示するプログラム（ひな形）		//制作者：2309405宇賀塚暖紀

#include "DxLib.h"	//DXライブラリのインクルード
#include"ScenePlay/Scene.h"
#include"ScenePlay/ScenePlay.h"
#include"SceneClear/SceneClear.h"
#include"SceneGameOver/SceneGameOver.h"
#include "SceneTitle/SceneTitle.h"
#include "Ball/Ball.h"

//現在のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

// define
#define	SCREEN_SIZE_X	640	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	480	// Y方向の画面サイズを指定
//自機情報
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //自機のパス
#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	VECTOR pos = { 100,200,1 };
	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------
		switch (g_CurrentSceneID)
		{
			//タイトルシーン
		case SCENE_ID_INIT_TITLE:

			InitTitle();
			break;
		case SCENE_ID_LOOP_TITLE:

			StepTitle();


			DrawTitle();
			break;

		case SCENE_ID_FIN_TITLE:

			FinTitle();
			break;

			//プレイシーン
		case SCENE_ID_INIT_PLAY:
		{
			InitPlay();
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{

			StepPlay();

			DrawPlay();

		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			FinPlay();
		}
		break;
		//クリアシーン
		case SCENE_ID_INIT_CLEAR:
		{
			InitClear();
		}
		break;

		case SCENE_ID_LOOP_CLEAR:
		{
			StepClear();

			DrawClear();
		}
		break;

		case SCENE_ID_FIN_CLEAR:
		{
			FinClear();
		}
		break;
		//ゲームオーバーシーン
		case SCENE_ID_INIT_GAMEOVER:
		{
			InitGameOver();

		}
		break;

		case SCENE_ID_LOOP_GAMEOVER:
		{
			StepGameOver();

			DrawGameOver();
		}
		break;
		case SCENE_ID_FIN_GAMEOVER:
		{
			FinGameOver();
		}
		break;

		default:
			break;
		}
		

		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

