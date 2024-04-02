#include "DxLib.h"
#include "Collision.h"

//IsHitRect�̒�`
bool IsHitRect(int x1, int y1, int w1, int h1,	//�����蔻��֐�
	int x2, int y2, int w2, int h2)
{

	if (x1 < x2 + w2 &&	//Rect��荶
		x1 + w1 > x2 &&	//		�@�E
		y1 + h1 > y2 && //		�@��
		y1 < y2 + h2)	//		�@��
	{
		DrawString(0, 0, "���������I", GetColor(255, 255, 255), true);
		return true;
	}

	return false;
}

//IsHitCircle�̒�`
bool IsHitCircle(int X, int Y, int R, int X2, int Y2, int R2)
{
	if ((R + R2) * (R + R2) >
		(X - X2) * (X - X2) +
		(Y - Y2) * (Y - Y2))
	{
		DrawString(0, 0, "�������Ă���I�I", GetColor(255, 0, 0), true);
		return true;
	}

	DrawString(0, 0, "�������ĂȂ��I�I", GetColor(0, 0, 255), true);
	return false;
}
