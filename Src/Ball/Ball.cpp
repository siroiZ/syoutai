#include "Ball.h"		//2309402_èoåıê^ìﬂìl
#include "Dxlib.h"

#define TEKI_PATH     "Data/PlayerImage/smallDiePlayer.png"

void Ball::Init() {		// èâä˙âª
	posX_m = 10.0f;
	posY_m = 10.0f;
}

void Ball::Step() {		// í èÌ
	posX_m += 5.0f;
	posY_m += 5.0f;
}

void Ball::Draw() {		// ï`âÊ
	DrawCircle(posX_m, posY_m, 5, GetColor(255, 0, 255), true);
}

void Ball::Fin() {		// èIóπ
	posX_m = 10.0f;
	posY_m = 10.0f;
}