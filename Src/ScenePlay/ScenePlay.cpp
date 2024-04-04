#include "DxLib.h"	//DX���C�u�����̃C���N���[�h     //2309405�F��˒g�I
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"

#include "../Collision/Collision.h"

//���@���
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //���@�̃p�X

#define PLAYER_MOVE_NORMAL_SPEED (1)    //�v���C���[�̒ʏ�ړ����x
#define PLAYER_MOVE_DASH_SPEED (3)    //�v���C���[�̒ʏ�ړ����x

//�\����
PlayerInfo playerInfo = { 0 };
// �^�C���N���X
CntTimer cnttime;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//�v���C���[������
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 320;
	playerInfo.y = 240;
	playerInfo.playerhp = 3;

	cnttime.Init();
}

void StepPlay()
{
	int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //�ړ��X�s�[�h
	//R�V�t�g�L�[�Ń_�b�V��
	if (CheckHitKey(KEY_INPUT_RSHIFT)) {
		moveSpeed = PLAYER_MOVE_DASH_SPEED;
	}

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
	//�v���C���[�ƕǂƂ̓����蔻��
	if (playerInfo.x < SCREEN_SIZE_X / 2 - 300 + 100-3) {
		playerInfo.x = playerInfo.x + 1;         //����
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x + 2;     //�_�b�V�����̏���
		}
	}
	if (playerInfo.x+32> SCREEN_SIZE_X / 2 + 200+3) {
		playerInfo.x = playerInfo.x - 1;         //�E��
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x - 2;     //�_�b�V�����̏���
		}
	}
	if (playerInfo.y + 32 > SCREEN_SIZE_Y / 2 + 200+3) {
		playerInfo.y = playerInfo.y - 1;         //����
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.y = playerInfo.y - 2;     //�_�b�V�����̏���
		}
	}
	if (playerInfo.y < SCREEN_SIZE_Y / 2 - 300 + 100-3) {
		playerInfo.y = playerInfo.y + 1;         //���
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.y = playerInfo.y + 2;     //�_�b�V�����̏���
		}
	}

	cnttime.Step();
}

void DrawPlay()
{

	//����Test (����)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 225, 225), false);	//��
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//����
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//�E��
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(0, 100, 225), true);		//���
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(0, 100, 225), true);		//����

	//�v���C���[�̕`��
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	cnttime.Draw();
}

void FinPlay()
{

}