#ifndef _SCENE_PLAY_H_
#define _SCENE_PLAY_H_

void InitPlay();

void StepPlay();

void DrawPlay();

void FinPlay();

//自機情報構造体
struct PlayerInfo
{
	int playerhandle;		          //プレイヤー画像ハンドル
	int playerdiehandle;              //プレイヤー(ピンチ)画像ハンドル
	int x, y;                         //プレイヤー座標
	int playerhp;            //プレイヤーのHP
};

//自機HP情報構造体
struct PlayerHPInfo
{
	int handle;		//画像ハンドル
	int x, y;		//座標
};

struct StartCountInfo
{
	int startcounthandle1;
	int startcounthandle2;
	int startcounthandle3;
	int starthandle;
};

#endif