#pragma once

// カウント時間クラス
class CntTimer {
private:
	int cnttimeM_m;		// 分タイムメンバ変数
	int cnttimeS_m;		// 秒タイムメンバ変数
	int cnttimeMS_m;	// ミリ秒タイムメンバ変数
	float cnttimeball_m;// 時間経過でボールの速度アップ
	bool timeclear_m;	// 残り時間0になったときtrueにする
	public:

		void Init();	// 初期化処理
		void Step();	// 通常処理
		void Draw();	// 描画処理
		void Fin();		// 終了処理

		bool GetTimerClear() { return timeclear_m; };	// クリア変数取得（残り時間０になったらクリアにしたいため）
		// float GetCountTime() { return cnttimeball_m; };	// 時間経過ボール速度上昇変数取得

};