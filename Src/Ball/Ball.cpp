#include "Ball.h"
#include "Dxlib.h"

#define TEKI_PATH     "Data/PlayerImage/smallDiePlayer.png"

void Ball::Init() {		// 初期化
	posX_m = 10.0f;
	posY_m = 10.0f;
}

void Ball::Step() {		// 通常
	posX_m += 5.0f;
	posY_m += 5.0f;
}

void Ball::Draw() {		// 描画

}

void Ball::Fin() {		// 終了
	posX_m = 10.0f;
	posY_m = 10.0f;
}