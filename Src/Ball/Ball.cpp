#include "Ball.h"		//2309402_�o���^�ߓl
#include "Dxlib.h"

#define TEKI_PATH     "Data/PlayImage/smallDiePlayer.png"
BallInfo Ball;

void Ball::Init() {		// ������
	posX_m = 10.0f;
	posY_m = 10.0f;
	hndl_m = LoadGraph(TEKI_PATH);
}

void Ball::Step() {		// �ʏ�
	posX_m += 5.0f;
	posY_m += 5.0f;
}

void Ball::Draw() {		// �`��
	// DrawCircle(posX_m, posY_m, 5, GetColor(255, 0, 255), true);
	DrawGraph(posX_m / 2, posY_m / 2, hndl_m, true);
}

void Ball::Fin() {		// �I��
	posX_m = 10.0f;
	posY_m = 10.0f;
}