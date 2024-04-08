#include "DxLib.h"
#include "../ScenePlay/Scene.h"
#include "SceneClear.h"

#define CLEAR_PATH "Data/Title/Clear.png"
#define CLEAR_HAIKEI_PATH "Data/Haikei/�摜1.png"
//SE
#define CLEAR_SE_PATH		"Data/SE/�����Ɣ���.wav"

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
	//SE������
	ClearSEHandle = LoadSoundMem(CLEAR_SE_PATH);
}

void StepClear()
{
	if (ClearSEcount == 0) {
		PlaySoundMem(ClearSEHandle, DX_PLAYTYPE_LOOP, true);
		ClearSEcount++;
	}
	//Enter�L�[�����ꂽ�Ȃ�
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

void DrawClear()
{
	//�w�i
	DrawGraph(-10, -10, ClearHikeiHandle, true);
	//�Q�[���I�[�o�[�`��
	DrawGraph(150, 100, ClearHandle, true);
	DrawFormatString(230, 300, GetColor(0, 200, 0), "�^�C�g���֖߂�FEnter");
}

void FinClear()
{
	//�^�C�g���V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	DeleteSoundMem(ClearSEHandle);
	ClearSEcount = 0;
}