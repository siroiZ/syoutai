#include "DxLib.h"
#include "../ScenePlay/Scene.h"
#include "SceneGameOver.h"

#define GAMEOVER_PATH "Data/Title/Gameover.png"
#define GAMEOVER_HAIKEI_PATH "Data/Haikei/�摜1.png"

int GameOverHandle;
int GameOverHikeiHandle;

void InitGameOver()
{
	GameOverHandle = LoadGraph(GAMEOVER_PATH);
	GameOverHikeiHandle = LoadGraph(GAMEOVER_HAIKEI_PATH);
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

void StepGameOver()
{
	//Enter�L�[�����ꂽ�Ȃ�
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

void DrawGameOver()
{
	//�w�i
	DrawGraph(-10, -10, GameOverHikeiHandle, true);
	//�Q�[���I�[�o�[�`��
	DrawGraph(55, 100, GameOverHandle, true);
	DrawFormatString(250, 300, GetColor(0, 200, 0), "��蒼���FEnter");
}

void FinGameOver()
{
	//�v���C�V�[���ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}