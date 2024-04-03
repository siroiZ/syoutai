#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene.h"
#include"ScenePlay.h"
#include "../Collision/Collision.h"

//自機情報
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //自機のパス

#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度
#define PLAYER_MOVE_DASH_SPEED (3)    //プレイヤーの通常移動速度

//構造体
PlayerInfo playerInfo = { 0 };

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//プレイヤー初期化
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 0;
	playerInfo.y = 0;

}

void StepPlay()
{
	int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //移動スピード
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



}

void DrawPlay()
{
	//プレイヤーの描画
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

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
}

void FinPlay()
{

}