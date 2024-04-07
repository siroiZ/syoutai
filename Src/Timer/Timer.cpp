#include "Timer.h"		//2309402_出光真那斗
#include "DxLib.h"
#include "time.h"

void CntTimer::Init() {		// 初期化
	cnttimeM_m = 1;			// 分
	cnttimeS_m = 30;		// 秒
	cnttimeMS_m = 0;		// ミリ秒
	cnttimeball_m = 0.0f;	// 時間経過でボールの速度アップ
	timeclear_m = false;
}

void CntTimer::Step() {		// 通常

		if (cnttimeM_m >= 0) {
			cnttimeMS_m--;
			cnttimeball_m += 0.1f;
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
			timeclear_m = true;
		}
}

void CntTimer::Draw() {		// 描画
	if (cnttimeM_m == 0 && cnttimeS_m <= 30 && cnttimeMS_m >= 0) {
		DrawFormatString(0, 0, GetColor(255, 100, 0), "%02d:%02d:%02d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

	}
	else
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%02d:%02d:%02d", cnttimeM_m, cnttimeS_m, cnttimeMS_m);

}

void CntTimer::Fin() {		// 終了
	cnttimeM_m = 0;
	cnttimeS_m = 0;
	cnttimeMS_m = 0;
	cnttimeball_m = 0.0f;
}