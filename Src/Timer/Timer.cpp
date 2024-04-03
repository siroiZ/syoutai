#include "Timer.h"		//2309402_�o���^�ߓl
#include "DxLib.h"
#include "time.h"

void CntTimer::Init() {		// ������
	cnttimeM_m = 0;		// ��
	cnttimeS_m = 0;		// �b
	cnttimeMS_m = 0;	// �~���b
}

void CntTimer::Step() {		// �ʏ�
	cnttimeMS_m++;
	if (cnttimeMS_m >= 10) {
		cnttimeMS_m = 0;
		cnttimeS_m++;
	}
	if (cnttimeS_m >= 60) {
		cnttimeS_m = 0;
		cnttimeM_m++;
	}
}

void CntTimer::Draw() {		// �`��
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%0d:%0d:%0d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);
}