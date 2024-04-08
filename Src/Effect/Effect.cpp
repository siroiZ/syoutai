#include <DxLib.h>
#include "effect.h"

//一度に表示できるエフェクト最大数
#define EFFECT_MAX_NUM		(20)

//エフェクトのアニメ最大数
#define EFFECT_ANIME_MAX_NUM	(4)	

//エフェクト情報
struct EffectInfo
{
	//★エフェクトの種類
	EFFECT_TYPE type;

	//★画像ハンドル
	int imageHandle[EFFECT_ANIME_MAX_NUM];

	//★座標
	int x, y;

	//★使用フラグ
	bool isUse;

	//★アニメ数
	int animeUseNum;

	//★現在のアニメ番号
	int currentAnimeIndex;

	//★１枚あたりの表示時間
	float changeTime;

	//★現在のアニメ時間
	float currentAnimeTime;
};

//エフェクト情報
EffectInfo effectInfo[EFFECT_MAX_NUM];

//エフェクトのファイルパス
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
};

//各エフェクトのアニメ数
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
};

//各エフェクトの画像分割数 [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
};

//エフェクトの画像サイズ
const int effectImageSize[EFFECT_TYPE_NUM] =
{
	64,	//EFFECT_TYPE_EXPLOSION
};

//各エフェクトのアニメ画像切り替え時間
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
};

//エフェクトの読み込み
//引数	：エフェクトの種類、作成数
void LoadEffect(EFFECT_TYPE type, int create_num)
{
	for (int currentAnimeIndex = 0; currentAnimeIndex < create_num; currentAnimeIndex++) {

		for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++) {
			//★読み込みしていないエフェクト情報を見つける
			//★（ひとつ目の画像ハンドルがゼロなら読み込みされてない）
			if (effectInfo[effectIndex].imageHandle[0] == 0) {

				int AnimeInfoNumX = effectImageSplitNum[type][0];
				int AnimeInfoNumY = effectImageSplitNum[type][1];

				//
				int ImageSize = effectImageSize[type];

				//★画像を分割読み込み
				int success_flg = LoadDivGraph(effectFilePath[type], effectAnimeImgNum[type], effectImageSplitNum[type][0], effectImageSplitNum[type][1], ImageSize, ImageSize, effectInfo[effectIndex].imageHandle);

				//成功した
				if (success_flg == 0)
				{
					//★アニメ数を格納
					effectInfo[effectIndex].animeUseNum = effectAnimeImgNum[type];

					//★１枚当たりの表示時間を設定
					effectInfo[effectIndex].changeTime = effectChageTime[type];

					//★エフェクトの種類を設定
					effectInfo[effectIndex].type = type;
				}

				//★成否にかかわらず抜ける
				break;
			}
		}
	}
}

//エフェクトの初期化
void InitEffect()
{
	//★すべてのエフェクト情報の変数をクリアする（ゼロにする）
	for (int effect_Index = 0; effect_Index < EFFECT_ANIME_MAX_NUM; effect_Index++)
	{
		effectInfo[effect_Index].x = 0;
		effectInfo[effect_Index].y = 0;
		effectInfo[effect_Index].animeUseNum = 0;
		effectInfo[effect_Index].currentAnimeIndex = 0;
		effectInfo[effect_Index].currentAnimeTime = 0.0f;
		effectInfo[effect_Index].changeTime = 0.0f;
		effectInfo[effect_Index].isUse = false;
		//effectInfo[effectIndex].type = EFFECT_TYPE_EXPLOSION;
		for (int i = 0; i < EFFECT_ANIME_MAX_NUM; i++)
		{
			effectInfo[effect_Index].imageHandle[i] = 0;
		}
	}

}

//エフェクト通常処理
void StepEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//★使用中ならアニメ時間を経過させて、アニメ番号を更新する
		if (effectInfo[effect_index].isUse == true /*effectInfo[effect_index].changeTime*/)
		{
			//★画像切り替わるに必要な時間経過したら
			if (effectInfo[effect_index].currentAnimeTime >= effectInfo[effect_index].changeTime)
			{
				//★次の画像へ
				effectInfo[effect_index].currentAnimeIndex++;
				//★計測時間リセット
				effectInfo[effect_index].currentAnimeTime = 0.0f;
				//★次の画像がもし無いなら
				if (effectInfo[effect_index].currentAnimeIndex >= effectInfo[effect_index].animeUseNum)
				{
					//★使用中フラグをOFFに
					effectInfo[effect_index].isUse = false;
					//★以下の処理は不要
					continue;
				}
			}
			//★時間更新
			effectInfo[effect_index].currentAnimeTime += 1.0f / FRAME_RATE;
		}
	}
}

//エフェクト描画処理
void DrawEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//★使用中なら現在のアニメ番号で描画する
		if (effectInfo[effect_index].isUse == true) {
			int x = effectInfo[effect_index].x;
			int y = effectInfo[effect_index].y;
			int handleIndex = effectInfo[effect_index].currentAnimeIndex;
			int imageHandle = effectInfo[effect_index].imageHandle[handleIndex];

			DrawRotaGraph(x, y, 1.0f, 0.0f, imageHandle, true);
		}
	}
}

//エフェクトの後処理
void FinEffect()
{
	//★すべてのエフェクトを削除する
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//★すべて削除する
		for (int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
		{
			//★ゼロ以外なら削除する
			if (effectInfo[effect_index].imageHandle[anime_index] != 0)
			{
				//★画像削除引数を設定する
				DeleteGraph(effectInfo[effect_index].imageHandle[anime_index]);

				//★削除したらゼロを入れておく
				effectInfo[effect_index].imageHandle[anime_index] = 0;
			}
		}
	}
}

//エフェクトの再生
//引数	：エフェクトの種類, Ｘ座標, Ｙ座標, １枚あたりの表示時間
void PlayEffect(EFFECT_TYPE type, int x, int y)
{
	//★未使用エフェクトを探して再生
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//★使用中なら以下行わない
		if (!effectInfo[effect_index].isUse) {
			//★タイプが一致した 
			if (effectInfo[effect_index].type == type) {
				//★座標設定
				effectInfo[effect_index].x = x;
				effectInfo[effect_index].y = y;
				//★計測用の変数をクリア
				effectInfo[effect_index].currentAnimeIndex = 0;
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//★使用中にする
				effectInfo[effect_index].isUse = true;
				break;
			}
		}
	}
}