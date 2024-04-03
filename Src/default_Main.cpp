//�E�B���h�E��\������v���O�����i�ЂȌ`�j		//����ҁF�@,2309402�o���^�ߓl,2309405�F��˒g�I

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"ScenePlay/Scene.h"
#include"ScenePlay/ScenePlay.h"

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_PLAY;

// define
#define	SCREEN_SIZE_X	640	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	480	// Y�����̉�ʃT�C�Y���w��
//���@���
#define PLAYER_PATH		"Data/PlayImage/teki1.png"	    //���@�̃p�X
#define PLAYER_MOVE_NORMAL_SPEED (1)    //�v���C���[�̒ʏ�ړ����x

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	VECTOR pos = { 100,200,1 };
	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------
		switch (g_CurrentSceneID)
		{
			//�v���C�V�[��
		case SCENE_ID_INIT_PLAY:
		{
			InitPlay();
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{

			StepPlay();

			DrawPlay();
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			FinPlay();
		}
		break;
		}
		/*//�v���C���[������
		int playerhandle = LoadGraph(PLAYER_PATH);
		int playerx = 0;
		int playery = 0;

		int moveSpeed = PLAYER_MOVE_NORMAL_SPEED;  //�ړ��X�s�[�h

		//�ړ�����(�E)
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			playerx += 1;
		}
		//�ړ�����(��)
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			playerx -= 1;
		}
		//�ړ�����(��)
		if (CheckHitKey(KEY_INPUT_UP)) {
			playery -= 1;
		}
		//�ړ�����(��)
		if (CheckHitKey(KEY_INPUT_DOWN)) {
			playery += 1;
		}

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
		DrawGraph(playerx, playery, playerhandle, true);*/

		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

