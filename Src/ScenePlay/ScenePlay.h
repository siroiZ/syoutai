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
	int x, y;                         //プレイヤー座標
	int playerhp;            //プレイヤーのHP
};

//自機HP情報構造体
struct PlayerHPInfo
{
	int handle;		//画像ハンドル
	int x, y;		//座標
};

struct TekiInfo
{
	int enemyhandle;
	int enemyx;
	int enemyy;
};

#endif