#include "Ball.h"
#include "Dxlib.h"

void Ball::Init() {		// ������
	posX_m = 10.0f;
	posY_m = 10.0f;
}

void Ball::Step() {		// �ʏ�
	posX_m += 5.0f;
	posY_m += 5.0f;
}

void Ball::Draw() {		// �`��

}

void Ball::Fin() {		// �I��
	posX_m = 10.0f;
	posY_m = 10.0f;
}