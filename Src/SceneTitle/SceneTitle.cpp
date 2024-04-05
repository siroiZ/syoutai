#include "DxLib.h"
#include "../ScenePlay/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

#define TITLE_PATH   "Data/Title/Title.PNG"

int TitleHandle;


void InitTitle()
{
	TitleHandle= LoadGraph(TITLE_PATH);

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}


//エンターキーが押されたら
void StepTitle()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//タイトル画像を描画
void DrawTitle()
{
	DrawGraph(0, 0, TitleHandle, true);
}

//プレイシーンに移動
void FinTitle()
{
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}