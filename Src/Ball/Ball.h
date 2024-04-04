#pragma once

// ボールクラス
class Ball {
private:
	float posX_m, posY_m;	// ボールの座標
public:
	void Init();	// 初期化
	void Step();	// 通常
	void Draw();	// 描画
	void Fin();		// 終了
};