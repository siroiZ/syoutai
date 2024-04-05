#include "DxLib.h"	//DXライブラリのインクルード     //2309405宇賀塚暖紀
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"

#include "../Collision/Collision.h"

//自機情報
#define PLAYER_PATH		"Data/PlayImage/smallPlayer.png"	    //自機のパス
#define TEKI_PATH     "Data/PlayImage/smallDiePlayer.png"

#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度
#define PLAYER_MOVE_DASH_SPEED (3)    //プレイヤーの通常移動速度
//体力ゲージ
#define HP_PATH		"Data/PlayImage/体力32サイズ(満タン).png"	//体力のパス
#define HP_MAX_NUM (3)

//構造体
PlayerInfo playerInfo = { 0 };
PlayerHPInfo playerhpInfo[HP_MAX_NUM] = { 0 };
TekiInfo tekiInfo = { 0 };
// タイムクラス
CntTimer cnttime;

//クリアシーンフラグ
bool isNextClearScene = false;      //クリア条件を満たしているか

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//プレイヤー初期化
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 320;
	playerInfo.y = 240;
	playerInfo.playerhp = 3;

	tekiInfo.enemyhandle = LoadGraph(TEKI_PATH);
	tekiInfo.enemyx = 320;
	tekiInfo.enemyy = 240;

	//HPInfo1
	for (int i = 0; i < HP_MAX_NUM; i++) {
		playerhpInfo[i].handle = LoadGraph(HP_PATH);
		playerhpInfo[i].x = 0;
		playerhpInfo[i].y = 0;
	}
	//X軸
	playerhpInfo[0].x = 405 + 40 * 5;
	playerhpInfo[1].x = 405 + 40 * 4;
	playerhpInfo[2].x = 405 + 40 * 3;
	//敵Y軸
	playerhpInfo[0].y = 12;
	playerhpInfo[1].y = 12;
	playerhpInfo[2].y = 12;

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
	if (playerInfo.x+76> SCREEN_SIZE_X / 2 + 200+3) {
		playerInfo.x = playerInfo.x - 1;         //右壁
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x - 2;     //ダッシュ中の処理
		}
	}
	if (playerInfo.y + 76 > SCREEN_SIZE_Y / 2 + 200+3) {
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

	//HP描画
	for (int i = 0; i < HP_MAX_NUM; i++) {
		if (playerInfo.playerhp >= 1) {
			DrawGraph(playerhpInfo[2].x, playerhpInfo[2].y, playerhpInfo[2].handle, true);
		}
		if (playerInfo.playerhp >= 2) {
			DrawGraph(playerhpInfo[1].x, playerhpInfo[1].y, playerhpInfo[1].handle, true);
		}
		if (playerInfo.playerhp == 3) {
			DrawGraph(playerhpInfo[0].x, playerhpInfo[0].y, playerhpInfo[0].handle, true);
		}
	}
	//DrawGraph(tekiInfo.enemyx, tekiInfo.enemyy, tekiInfo.enemyhandle, true);
	//プレイヤーの描画
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	//クリア判定
	/*if (cnttimeM_m <= 0 && cnttimeS_m <= 0 &&     //制限時間が０になったら
		cnttimeMS_m <= 0) {
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;    //FINに移動
		isNextClearScene = true;                 //クリア条件を満たす
	}*/

	cnttime.Draw();
}

void FinPlay()
{
	/*if (isNextClearScene) {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;  //クリアシーンへ
	}
	else {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;  //ゲームオーバーへ
	}*/
}