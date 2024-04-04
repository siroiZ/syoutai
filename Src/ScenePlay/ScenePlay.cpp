#include "DxLib.h"	//DXライブラリのインクルード     //2309405宇賀塚暖紀
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"

#include "../Collision/Collision.h"

//自機情報
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //自機のパス

#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度
#define PLAYER_MOVE_DASH_SPEED (3)    //プレイヤーの通常移動速度

//構造体
PlayerInfo playerInfo = { 0 };
// タイムクラス
CntTimer cnttime;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//プレイヤー初期化
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 320;
	playerInfo.y = 240;
	playerInfo.playerhp = 3;

	cnttime.Init();
}

void StepPlay()
{
	int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //移動スピード
	//Rシフトキーでダッシュ
	if (CheckHitKey(KEY_INPUT_RSHIFT)) {
		moveSpeed = PLAYER_MOVE_DASH_SPEED;
	}

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
	//プレイヤーと壁との当たり判定
	if (playerInfo.x < SCREEN_SIZE_X / 2 - 300 + 100-3) {
		playerInfo.x = playerInfo.x + 1;         //左壁
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x + 2;     //ダッシュ中の処理
		}
	}
	if (playerInfo.x+32> SCREEN_SIZE_X / 2 + 200+3) {
		playerInfo.x = playerInfo.x - 1;         //右壁
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x - 2;     //ダッシュ中の処理
		}
	}
	if (playerInfo.y + 32 > SCREEN_SIZE_Y / 2 + 200+3) {
		playerInfo.y = playerInfo.y - 1;         //下壁
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.y = playerInfo.y - 2;     //ダッシュ中の処理
		}
	}
	if (playerInfo.y < SCREEN_SIZE_Y / 2 - 300 + 100-3) {
		playerInfo.y = playerInfo.y + 1;         //上壁
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.y = playerInfo.y + 2;     //ダッシュ中の処理
		}
	}

	cnttime.Step();
}

void DrawPlay()
{

	//動作Test (仮壁)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 225, 225), false);	//壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//左壁
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//右壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(0, 100, 225), true);		//上壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(0, 100, 225), true);		//下壁

	//プレイヤーの描画
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	cnttime.Draw();
}

void FinPlay()
{

}