#include "Ball.h"
#include "Dxlib.h"

void Ball::Init() {		// èâä˙âª
	posX_m = 10.0f;
	posY_m = 10.0f;
}

void Ball::Step() {		// í èÌ
	posX_m += 5.0f;
	posY_m += 5.0f;
}

void Ball::Draw() {		// ï`âÊ

}

void Ball::Fin() {		// èIóπ
	posX_m = 10.0f;
	posY_m = 10.0f;
}