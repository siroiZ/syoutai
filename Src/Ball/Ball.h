#pragma once

// ボールクラス
class Ball {
private:
	float posX_m, posY_m;	// ボールの座標
	int hndl_m;				// 画像ハンドル
public:
	void Init();	// 初期化
	void Step();	// 通常
	void Draw();	// 描画
	void Fin();		// 終了
};

//ボール情報構造体
struct BallInfo
{
	int handle;                       //敵画像ハンドル
	int x, y;                         //敵座標
};