#ifndef __COLLISION_H__
#define __COLLISION_H__

//IsHitRectのプロトタイプ宣言
bool IsHitRect(int x1, int y1, int w1, int h1,	//当たり判定関数
	int x2, int y2, int w2, int h2);

	//IsHitCircleのプロトタイプ宣言
	bool IsHitCircle(int X, int Y, int R, int X2, int Y2, int R2);

#endif
