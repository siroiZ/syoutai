#include "DxLib.h"
#include "Collision.h"

//IsHitRectの定義
bool IsHitRect(int x1, int y1, int w1, int h1,	//当たり判定関数
	int x2, int y2, int w2, int h2)
{

	if (x1 < x2 + w2 &&	//Rectより左
		x1 + w1 > x2 &&	//		　右
		y1 + h1 > y2 && //		　下
		y1 < y2 + h2)	//		　上
	{
		DrawString(0, 0, "当たった！", GetColor(255, 255, 255), true);
		return true;
	}

	return false;
}

//IsHitCircleの定義
bool IsHitCircle(int X, int Y, int R, int X2, int Y2, int R2)
{
	if ((R + R2) * (R + R2) >
		(X - X2) * (X - X2) +
		(Y - Y2) * (Y - Y2))
	{
		DrawString(0, 0, "当たっている！！", GetColor(255, 0, 0), true);
		return true;
	}

	DrawString(0, 0, "当たってない！！", GetColor(0, 0, 255), true);
	return false;
}
