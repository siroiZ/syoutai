#include "Timer.h"		//2309402_�o���^�ߓl
#include "DxLib.h"
#include "time.h"

void CntTimer::Init() {		// ������
	cnttimeM_m = 1;		// ��
	cnttimeS_m = 30;	// �b
	cnttimeMS_m = 0;	// �~���b
}

void CntTimer::Step() {		// �ʏ�

		if (cnttimeM_m >= 0) {
			cnttimeMS_m--;
		}
		if (cnttimeMS_m < 0) {
			cnttimeMS_m = 60;
			cnttimeS_m--;
		}
		if (cnttimeS_m < 0) {
			cnttimeS_m = 60;
			cnttimeM_m--;
		}
		if (cnttimeM_m < 0) {
			cnttimeM_m = 0;
			cnttimeS_m = 0;
			cnttimeMS_m = 0;
		}
}

void CntTimer::Draw() {		// �`��
	if (cnttimeM_m == 0 && cnttimeS_m <= 30 && cnttimeMS_m >= 0) {
		DrawFormatString(0, 0, GetColor(255, 100, 0), "%02d:%02d:%02d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

	}
	else
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%02d:%02d:%02d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

}

void CntTimer::Fin() {		// �I��
	cnttimeM_m = 0;
	cnttimeS_m = 0;
	cnttimeMS_m = 0;

}