#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene.h"
#include"ScenePlay.h"
#include "../Collision/Collision.h"
#include "../Timer/Timer.h"

//自機情報
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //自機のパス

#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度

//構造体
PlayerInfo playerInfo = { 0 };

// cnt時間クラス
CntTimer cnttimer;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//プレイヤー初期化
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 0;
	playerInfo.y = 0;


	cnttimer.Init();
}

void StepPlay()
{
	int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //移動スピード

	//移動処理(右)
	if (CheckHitKey(KEY_INPUT_D)) {
		playerInfo.x += moveSpeed;
	}
	//移動処理(左)
	if (CheckHitKey(KEY_INPUT_A)) {
		playerInfo.x -= moveSpeed;
	}
	//移動処理(上)
	if (CheckHitKey(KEY_INPUT_W)) {
		playerInfo.y -= moveSpeed;
	}
	//移動処理(下)
	if (CheckHitKey(KEY_INPUT_S)) {
		playerInfo.y += moveSpeed;
	}


	cnttimer.Step();
}

void DrawPlay()
{
	//プレイヤーの描画
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	//動作Test (仮壁)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 100, 0), false);	//壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 255, 0), true);		//左壁
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 255, 0), true);		//右壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(255, 255, 0), true);		//上壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(255, 255, 0), true);		//下壁


	cnttimer.Draw();
}

void FinPlay()
{

}