#include "DxLib.h"	//DX���C�u�����̃C���N���[�h     //2309405�F��˒g�I
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"

#include "../Collision/Collision.h"

//���@���
#define PLAYER_PATH		"Data/PlayImage/smallPlayer.png"	    //���@�̃p�X
#define TEKI_PATH     "Data/PlayImage/smallDiePlayer.png"

#define PLAYER_MOVE_NORMAL_SPEED (1)    //�v���C���[�̒ʏ�ړ����x
#define PLAYER_MOVE_DASH_SPEED (3)    //�v���C���[�̒ʏ�ړ����x
//�̗̓Q�[�W
#define HP_PATH		"Data/PlayImage/�̗�32�T�C�Y(���^��).png"	//�̗͂̃p�X
#define HP_MAX_NUM (3)

//�\����
PlayerInfo playerInfo = { 0 };
PlayerHPInfo playerhpInfo[HP_MAX_NUM] = { 0 };
TekiInfo tekiInfo = { 0 };
// �^�C���N���X
CntTimer cnttime;

//�N���A�V�[���t���O
bool isNextClearScene = false;      //�N���A�����𖞂����Ă��邩

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//�v���C���[������
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);
	playerInfo.x = 320;
	playerInfo.y = 240;
	playerInfo.playerhp = 3;

	tekiInfo.enemyhandle = LoadGraph(TEKI_PATH);
	tekiInfo.enemyx = 320;
	tekiInfo.enemyy = 240;

	//HPInfo1
	for (int i = 0; i < HP_MAX_NUM; i++) {
		playerhpInfo[i].handle = LoadGraph(HP_PATH);
		playerhpInfo[i].x = 0;
		playerhpInfo[i].y = 0;
	}
	//X��
	playerhpInfo[0].x = 405 + 40 * 5;
	playerhpInfo[1].x = 405 + 40 * 4;
	playerhpInfo[2].x = 405 + 40 * 3;
	//�GY��
	playerhpInfo[0].y = 12;
	playerhpInfo[1].y = 12;
	playerhpInfo[2].y = 12;

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
	if (playerInfo.x+76> SCREEN_SIZE_X / 2 + 200+3) {
		playerInfo.x = playerInfo.x - 1;         //�E��
		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			playerInfo.x = playerInfo.x - 2;     //�_�b�V�����̏���
		}
	}
	if (playerInfo.y + 76 > SCREEN_SIZE_Y / 2 + 200+3) {
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

	//HP�`��
	for (int i = 0; i < HP_MAX_NUM; i++) {
		if (playerInfo.playerhp >= 1) {
			DrawGraph(playerhpInfo[2].x, playerhpInfo[2].y, playerhpInfo[2].handle, true);
		}
		if (playerInfo.playerhp >= 2) {
			DrawGraph(playerhpInfo[1].x, playerhpInfo[1].y, playerhpInfo[1].handle, true);
		}
		if (playerInfo.playerhp == 3) {
			DrawGraph(playerhpInfo[0].x, playerhpInfo[0].y, playerhpInfo[0].handle, true);
		}
	}
	//DrawGraph(tekiInfo.enemyx, tekiInfo.enemyy, tekiInfo.enemyhandle, true);
	//�v���C���[�̕`��
	DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);

	//�N���A����
	/*if (cnttimeM_m <= 0 && cnttimeS_m <= 0 &&     //�������Ԃ��O�ɂȂ�����
		cnttimeMS_m <= 0) {
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;    //FIN�Ɉړ�
		isNextClearScene = true;                 //�N���A�����𖞂���
	}*/

	cnttime.Draw();
}

void FinPlay()
{
	/*if (isNextClearScene) {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;  //�N���A�V�[����
	}
	else {
		playerInfo.playerhp = 3;
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;  //�Q�[���I�[�o�[��
	}*/
}