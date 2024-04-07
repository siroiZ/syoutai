#include "DxLib.h"
#include "../ScenePlay/Scene.h"
#include "SceneClear.h"

#define CLEAR_PATH "Data/Title/Clear.png"
#define CLEAR_HAIKEI_PATH "Data/Haikei/画像1.png"

int ClearHandle;
int ClearHikeiHandle;

void InitClear()
{
	ClearHandle = LoadGraph(CLEAR_PATH);
	ClearHikeiHandle = LoadGraph(CLEAR_HAIKEI_PATH);
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

void StepClear()
{
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
}