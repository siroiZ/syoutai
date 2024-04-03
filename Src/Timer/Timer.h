#pragma once

// カウント時間クラス
class CntTimer {
private:
	int cnttimeM_m;		// 分タイムメンバ変数
	int cnttimeS_m;		// 秒タイムメンバ変数
	int cnttimeMS_m;	// ミリ秒タイムメンバ変数
	public:

		void Init();	// 初期化処理
		void Step();	// 通常処理
		void Draw();	// 描画処理

};