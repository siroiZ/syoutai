#include "Ball.h"		//2309402_�o���^�ߓl
#include "../Timer/Timer.h"
#include "Dxlib.h"
#define	SCREEN_SIZE_X	640	// X�����̉�ʃT�C�Y
#define	SCREEN_SIZE_Y	480	// Y�����̉�ʃT�C�Y

#define TEKI_PATH     "Data/Charactor/Enemy.png"

// BallInfo Ball;

CntTimer cntball;

void Ball::Init() {		// ������
	posX_m = 325.0f;
	posY_m = 75.0f;
	speedX_m = 0.5f;
	speedY_m = 0.5f;
	hndl_m = LoadGraph(TEKI_PATH);
}

void Ball::Step() {		// �ʏ�
	posX_m += speedX_m + cntball.GetCountTime();
	posY_m += speedY_m + cntball.GetCountTime();

	if (posX_m > 500) {
		speedX_m = speedX_m * -1;
	}
	if (posX_m < 140) {
		speedX_m = speedX_m * -1;
	}
	if (posY_m > 420) {
		speedY_m = speedY_m * -1;
	}
	if (posY_m < 60) {
		speedY_m = speedY_m * -1;
	}


	//DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
	//	SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//����
	//DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
	//	SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//�E��
	//DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
	//	SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(0, 100, 225), true);		//���
	//DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200, 
	//	SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(0, 100, 225), true);		//����

}

void Ball::Draw() {		// �`��
	//DrawCircle(posX_m, posY_m, 5, GetColor(255, 0, 255), true);
	//DrawGraph(posX_m, posY_m, hndl_m, true);
	DrawRotaGraph(posX_m, posY_m, 0.125f, 0.0f, hndl_m, true);
}

void Ball::Fin() {		// �I��
	posX_m = 275.0f;
	posY_m = 50.0f;
}


void Ball::SetballspeedX(float x) {	// ���x�ݒ�
	speedX_m = x;
}
void Ball::SetballspeedY(float y) {
	speedY_m = y;
}
