#include "DxLib.h"	//DXライブラリのインクルード     //2309405宇賀塚暖紀
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"
#include"../Ball/Ball.h"

#include "../Collision/Collision.h"

//自機情報
#define PLAYER_PATH		"Data/PlayImage/smallPlayer.png"	        //自機のパス
#define PLAYER_DIE_PATH		"Data/PlayImage/smallDiePlayer.png"	    //自機(ピンチ)のパス

#define PLAYER_MOVE_NORMAL_SPEED (1)    //プレイヤーの通常移動速度
#define PLAYER_MOVE_DASH_SPEED (3)    //プレイヤーの通常移動速度
//体力ゲージ
#define HP_PATH		"Data/PlayImage/体力32サイズ(満タン).png"	//体力のパス
#define HP_MAX_NUM (3)
//最初のカウンダウン
#define START_COUNT1_PATH		"Data/Count/1count.png"	//カウント1のパス
#define START_COUNT2_PATH		"Data/Count/2count.png"	//カウント2のパス
#define START_COUNT3_PATH		"Data/Count/3count.png"	//カウント3のパス
#define START_PATH		        "Data/Count/START.png"	//STARTのパス
//背景
#define HAIKEI_PATH		"Data/Haikei/画像1.png"	//背景のパス
//SE
#define START_COUNT_SE_PATH		"Data/SE/決定ボタンを押す2.wav"    //カウント(123)
#define START_SE_PATH		    "Data/SE/決定ボタンを押す1.wav"    //カウント(START)

//構造体
PlayerInfo playerInfo = { 0 };
PlayerHPInfo playerhpInfo[HP_MAX_NUM] = { 0 };
StartCountInfo startcountInfo = { 0 };

// タイムクラス
CntTimer cnttime;
//ボールクラス
Ball ball;

//クリアシーンフラグ
bool isNextClearScene = false;      //クリア条件を満たしているか
float boolx = 10.0f;
float booly = 10.0f;

//最初のカウントダウン用
bool startcountflag = false;
int startcount = 0;            //一時停止時間
//背景
int HaikeiHandle = { 0 };        //ハンドル
//SE関連
int startcountSEhundle = 0;
int startSEhundle = 0;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;     //SCENE ID LOOP PLAYへ
	//背景初期化
	HaikeiHandle= LoadGraph(HAIKEI_PATH);

	//プレイヤー初期化
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);           //プレイヤーハンドル
	playerInfo.playerdiehandle = LoadGraph(PLAYER_DIE_PATH);    //プレイヤー（ピンチ時）ハンドル
	playerInfo.x = 320-33;       //X座標
	playerInfo.y = 240-33;       //Y座標
	playerInfo.playerhp = 3;     //プレイヤーHP（ 3 ）

	//HP表示初期化
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
	//カウント初期化
	startcountInfo.startcounthandle1 = LoadGraph(START_COUNT1_PATH);
	startcountInfo.startcounthandle2 = LoadGraph(START_COUNT2_PATH);
	startcountInfo.startcounthandle3= LoadGraph(START_COUNT3_PATH);
	startcountInfo.starthandle = LoadGraph(START_PATH);
	//SE初期化
	startcountSEhundle = LoadSoundMem(START_COUNT_SE_PATH);
	startSEhundle = LoadSoundMem(START_SE_PATH);

	cnttime.Init();
	ball.Init();
}

void StepPlay()
{
	if (startcountflag == false) {
		startcount++;               //カウントを進めていく
		if (startcount == 30) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //カウント3 SE
		}
		if (startcount == 100) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //カウント2 SE
		}
		if (startcount == 170) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //カウント1 SE
		}
		if (startcount == 240) {
			PlaySoundMem(startSEhundle, DX_PLAYTYPE_BACK, true);    //START SE
		}
		if (startcount >= 310) {
			startcountflag = true;
		}
	}

	if (startcountflag == true) {
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
		if (playerInfo.x < SCREEN_SIZE_X / 2 - 300 + 90) {
			playerInfo.x = playerInfo.x + 1;         //左壁
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.x = playerInfo.x + 2;     //ダッシュ中の処理
			}
		}
		if (playerInfo.x + 76 > SCREEN_SIZE_X / 2 + 200 + 10) {
			playerInfo.x = playerInfo.x - 1;         //右壁
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.x = playerInfo.x - 2;     //ダッシュ中の処理
			}
		}
		if (playerInfo.y + 76 > SCREEN_SIZE_Y / 2 + 200 + 10) {
			playerInfo.y = playerInfo.y - 1;         //下壁
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.y = playerInfo.y - 2;     //ダッシュ中の処理
			}
		}
		if (playerInfo.y < SCREEN_SIZE_Y / 2 - 300 + 90) {
			playerInfo.y = playerInfo.y + 1;         //上壁
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.y = playerInfo.y + 2;     //ダッシュ中の処理
			}
		}
		//プレイヤーとボールとの当たり判定
		if (IsHitCircle(playerInfo.x+38, playerInfo.y+38, 19,
			ball.GetballposX(), ball.GetballposY(), 19)){
			playerInfo.playerhp--;
		}

		//クリア判定
		if (cnttime.GetTimerClear() == true) {     //制限時間が０になったら
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;    //FINに移動
			isNextClearScene = true;                 //クリア条件を満たす
		}

		cnttime.Step();
		ball.Step();
	}
}

void DrawPlay()
{
	//背景描画
	DrawGraph(-10, -10, HaikeiHandle, true);

	//動作Test (仮壁)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 225, 225), false);	//壁
	/*DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//左壁
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//右壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(0, 100, 225), true);		//上壁
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(0, 100, 225), true);		//下壁*/

	//プレイヤーの描画
	if (playerInfo.playerhp >= 2) {
		DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);
	}
	if (playerInfo.playerhp == 1) {
		DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerdiehandle, true);
	}

	ball.Draw();

	//囲い描画
	DrawBox(playerhpInfo[2].x - 4, playerhpInfo[2].y - 6,
		playerhpInfo[0].x + 34, playerhpInfo[0].y + 32 + 6, GetColor(250, 210, 0), true);	//HP(内側)
	DrawBox(playerhpInfo[2].x - 4, playerhpInfo[2].y - 6,
		playerhpInfo[0].x + 34, playerhpInfo[0].y + 32 + 6, GetColor(60, 60, 200), false);  //HP(外側)
	DrawBox(-5, -5, 80, 20, GetColor(250, 210, 0), true);	//残り時間(内側)
	DrawBox(-5, -5, 80, 20, GetColor(60, 60, 200), false); //残り時間(外側)

	DrawCircle(playerInfo.x + 38, playerInfo.y + 38, 19, GetColor(255, 0, 0), false);  //当たり判定表示(プレイヤー)
	DrawCircle(ball.GetballposX(), ball.GetballposY(),19, GetColor(255, 0, 0), false); //当たり判定表示(ボール)

	//HP描画
	for (int i = 0; i < HP_MAX_NUM; i++) {
		if (playerInfo.playerhp >= 1) {
			DrawGraph(playerhpInfo[0].x, playerhpInfo[0].y, playerhpInfo[0].handle, true);
		}
		if (playerInfo.playerhp >= 2) {
			DrawGraph(playerhpInfo[1].x, playerhpInfo[1].y, playerhpInfo[1].handle, true);
		}
		if (playerInfo.playerhp == 3) {
			DrawGraph(playerhpInfo[2].x, playerhpInfo[2].y, playerhpInfo[2].handle, true);
		}
	}

	//最初のカウント描画
	if (startcountflag == false) {
		if (startcount >= 30) {
			if (startcount <= 100) {
				DrawGraph(320 - 61, 240 - 61, startcountInfo.startcounthandle3, true);
			}
		}
		if (startcount >= 100) {
			if (startcount <= 170) {
				DrawGraph(320 - 64, 240 - 64, startcountInfo.startcounthandle2, true);
			}
		}
		if (startcount >= 170) {
			if (startcount <= 240) {
				DrawGraph(320 - 56, 240 - 56, startcountInfo.startcounthandle1, true);
			}
		}
		if (startcount >= 240) {
			if (startcount <= 310) {
				DrawGraph(320 - 162, 240 - 61, startcountInfo.starthandle, true);
			}
		}
	}
	//コメント表示
	DrawFormatString(playerhpInfo[2].x-27, playerhpInfo[2].y-4, GetColor(30, 30, 30), "HP");   //HP
	DrawFormatString(0, 23, GetColor(0, 100, 0), "残り時間");                                //残り時間


	cnttime.Draw();

}

void FinPlay()
{
	if (isNextClearScene) {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;  //クリアシーンへ
	}
	else {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;  //ゲームオーバーへ
	}
	//SE破棄
	DeleteSoundMem(startcountSEhundle);
	DeleteSoundMem(startSEhundle);

	cnttime.Fin();
	ball.Fin();
}