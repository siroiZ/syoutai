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
	int x, y;                         //座標
};

#endif