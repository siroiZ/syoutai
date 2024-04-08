#include "DxLib.h"
#include "../ScenePlay/Scene.h"
#include "SceneClear.h"

#define CLEAR_PATH "Data/Title/Clear.png"
#define CLEAR_HAIKEI_PATH "Data/Haikei/画像1.png"
//SE
#define CLEAR_SE_PATH		"Data/SE/歓声と拍手.wav"

int ClearHandle;
int ClearHikeiHandle;
int ClearSEcount = 0;
//SE
int ClearSEHandle;

void InitClear()
{
	ClearHandle = LoadGraph(CLEAR_PATH);
	ClearHikeiHandle = LoadGraph(CLEAR_HAIKEI_PATH);
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
	//SE初期化
	ClearSEHandle = LoadSoundMem(CLEAR_SE_PATH);
}

void StepClear()
{
	if (ClearSEcount == 0) {
		PlaySoundMem(ClearSEHandle, DX_PLAYTYPE_LOOP, true);
		ClearSEcount++;
	}
	//Enterキー押されたなら
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

void DrawClear()
{
	//背景
	DrawGraph(-10, -10, ClearHikeiHandle, true);
	//ゲームオーバー描画
	DrawGraph(150, 100, ClearHandle, true);
	DrawFormatString(230, 300, GetColor(0, 200, 0), "タイトルへ戻る：Enter");
}

void FinClear()
{
	//タイトルシーンへ移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	DeleteSoundMem(ClearSEHandle);
	ClearSEcount = 0;
}