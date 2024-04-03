#include "Timer.h"		//2309402_oŒõ^“ß“l
#include "DxLib.h"
#include "time.h"

void CntTimer::Init() {		// ‰Šú‰»
	cnttimeM_m = 1;		// •ª
	cnttimeS_m = 30;		// •b
	cnttimeMS_m = 0;	// ƒ~ƒŠ•b
}

void CntTimer::Step() {		// ’Êí

	if (cnttimeM_m >= 0 && cnttimeS_m >= 0 && cnttimeMS_m >= 0) {
		cnttimeMS_m--;
		if (cnttimeMS_m < 0) {
			cnttimeMS_m = 10;
			cnttimeS_m--;
		}
		if (cnttimeS_m < 0) {
			cnttimeS_m = 60;
			cnttimeM_m--;
		}
	}

}

void CntTimer::Draw() {		// •`‰æ
	if (cnttimeM_m == 0 && cnttimeS_m <= 30 && cnttimeMS_m >= 0) {
		DrawFormatString(0, 0, GetColor(255, 100, 0), "%0d:%0d:%0d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

	}
	else
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%0d:%0d:%0d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

}