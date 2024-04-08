//�E�B���h�E��\������v���O�����i�ЂȌ`�j		//����ҁF2309405�F��˒g�I

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"ScenePlay/Scene.h"
#include"ScenePlay/ScenePlay.h"
#include"SceneClear/SceneClear.h"
#include"SceneGameOver/SceneGameOver.h"
#include "SceneTitle/SceneTitle.h"
#include "Ball/Ball.h"

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

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
			//�^�C�g���V�[��
		case SCENE_ID_INIT_TITLE:

			InitTitle();
			break;
		case SCENE_ID_LOOP_TITLE:

			StepTitle();


			DrawTitle();
			break;

		case SCENE_ID_FIN_TITLE:

			FinTitle();
			break;

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
		//�N���A�V�[��
		case SCENE_ID_INIT_CLEAR:
		{
			InitClear();
		}
		break;

		case SCENE_ID_LOOP_CLEAR:
		{
			StepClear();

			DrawClear();
		}
		break;

		case SCENE_ID_FIN_CLEAR:
		{
			FinClear();
		}
		break;
		//�Q�[���I�[�o�[�V�[��
		case SCENE_ID_INIT_GAMEOVER:
		{
			InitGameOver();

		}
		break;

		case SCENE_ID_LOOP_GAMEOVER:
		{
			StepGameOver();

			DrawGameOver();
		}
		break;
		case SCENE_ID_FIN_GAMEOVER:
		{
			FinGameOver();
		}
		break;

		default:
			break;
		}
		

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

