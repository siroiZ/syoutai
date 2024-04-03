#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene.h"
#include"ScenePlay.h"
#include "../Collision/Collision.h"
#include "../Timer/Timer.h"

//���@���
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //���@�̃p�X

#define PLAYER_MOVE_NORMAL_SPEED (1)    //�v���C���[�̒ʏ�ړ����x

//�\����
PlayerInfo playerInfo = { 0 };

// cnt���ԃN���X
CntTimer cnttimer;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//�v���C���[������
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 0;
	playerInfo.y = 0;


	cnttimer.Init();
}

void StepPlay()
{
	int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //�ړ��X�s�[�h

	//�ړ�����(�E)
	if (CheckHitKey(KEY_INPUT_D)) {
		playerInfo.x += moveSpeed;
	}
	//�ړ�����(��)
	if (CheckHitKey(KEY_INPUT_A)) {
		playerInfo.x -= moveSpeed;
	}
	//�ړ�����(��)
	if (CheckHitKey(KEY_INPUT_W)) {
		playerInfo.y -= moveSpeed;
	}
	//�ړ�����(��)
	if (CheckHitKey(KEY_INPUT_S)) {
		playerInfo.y += moveSpeed;
	}


	cnttimer.Step();
}

void DrawPlay()
{
	//�v���C���[�̕`��
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	//����Test (����)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 100, 0), false);	//��
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 255, 0), true);		//����
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(255, 255, 0), true);		//�E��
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(255, 255, 0), true);		//���
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(255, 255, 0), true);		//����


	cnttimer.Draw();
}

void FinPlay()
{

}