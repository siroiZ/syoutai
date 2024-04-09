#pragma once

// ボールクラス
class Ball {
private:
	float posX_m, posY_m;		// ボールの座標
	float speedX_m, speedY_m;	// ボール速度
	int hndl_m;					// 画像ハンドル
	int flgx_m;					// x壁に当たった
	int flgy_m;					// y壁
public:
	void Init();				// 初期化
	void Step();				// 通常
	void Draw();				// 描画
	void Fin();					// 終了

	float GetballposX() { return posX_m; };	// （ボールの座標をここから取得）
	float GetballposY() { return posY_m; };	

	void UpballspeedX(float x);	// ボール速度アップ
	void UpballspeedY(float y);

};

//ボール情報構造体
///*
struct BallInfo
{
	int handle;                       //敵画像ハンドル
	int x, y;                         //敵座標
};
//*/