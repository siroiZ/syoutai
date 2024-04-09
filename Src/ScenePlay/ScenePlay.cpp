#include "DxLib.h"	//DX���C�u�����̃C���N���[�h     //2309405�F��˒g�I
#include"Scene.h"
#include"ScenePlay.h"
#include"../Timer/Timer.h"
#include"../Ball/Ball.h"
#include "../Effect/Effect.h"
#include "../Collision/Collision.h"

//���@���
#define PLAYER_PATH		"Data/PlayImage/smallPlayer.png"	        //���@�̃p�X
#define PLAYER_DIE_PATH		"Data/PlayImage/smallDiePlayer.png"	    //���@(�s���`)�̃p�X

#define PLAYER_MOVE_NORMAL_SPEED (1)    //�v���C���[�̒ʏ�ړ����x
#define PLAYER_MOVE_DASH_SPEED (5)    //�v���C���[�̒ʏ�ړ����x
//�{�[�����
#define BALL_PATH     "Data/Charactor/Enemy.png"
#define BALL_MAX_NUM (5)
//�̗̓Q�[�W
#define HP_PATH		"Data/PlayImage/�̗�32�T�C�Y(���^��).png"	//�̗͂̃p�X
#define HP_MAX_NUM (3)
//�ŏ��̃J�E���_�E��
#define START_COUNT1_PATH		"Data/Count/1count.png"	//�J�E���g1�̃p�X
#define START_COUNT2_PATH		"Data/Count/2count.png"	//�J�E���g2�̃p�X
#define START_COUNT3_PATH		"Data/Count/3count.png"	//�J�E���g3�̃p�X
#define START_PATH		        "Data/Count/START.png"	//START�̃p�X
//�w�i
#define HAIKEI_PATH		"Data/Haikei/�摜1.png"	//�w�i�̃p�X
//BGM
#define BGM_PATH		"Data/SE/maou_bgm_8bit28.wav"        //BGM�̃p�X
//SE
#define START_COUNT_SE_PATH		"Data/SE/����{�^��������2.wav"    //�J�E���g(123)
#define START_SE_PATH		    "Data/SE/����{�^��������1.wav"    //�J�E���g(START)
#define EXPLOSION_SE_PATH		 "Data/SE/����1.wav"    //����
#define DAMAGE_SE_PATH		     "Data/SE/���p���`.wav"    //�_���[�W

//�\����
PlayerInfo playerInfo = { 0 };
PlayerHPInfo playerhpInfo[HP_MAX_NUM] = { 0 };
StartCountInfo startcountInfo = { 0 };

// �^�C���N���X
CntTimer cnttime;
//�{�[���N���X
//Ball ball[BALL_MAX_NUM];
Ball ball;
//�N���A�V�[���t���O
bool isNextClearScene = false;      //�N���A�����𖞂����Ă��邩
//�Q�[���I�[�o�[���X�g�b�v�p
int gameoverstopcount = 0;
int gameoverstopflag = false;
//�ŏ��̃J�E���g�_�E���p
bool startcountflag = false;
int startcount = 0;            //�ꎞ��~����
//�w�i
int HaikeiHandle = { 0 };        //�n���h��
//BGM
int bgmhundle = 0;
//SE�֘A
int startcountSEhundle = 0;
int startSEhundle = 0;
int ExplosionSEhundle = 0;
int DamageSEhundle = 0;

void InitPlay()
{
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;     //SCENE ID LOOP PLAY��
	//�w�i������
	HaikeiHandle= LoadGraph(HAIKEI_PATH);

	//�v���C���[������
	playerInfo.playerhandle = LoadGraph(PLAYER_PATH);           //�v���C���[�n���h��
	playerInfo.playerdiehandle = LoadGraph(PLAYER_DIE_PATH);    //�v���C���[�i�s���`���j�n���h��
	playerInfo.x = 320-33;       //X���W
	playerInfo.y = 240-33;       //Y���W
	playerInfo.playerhp = 3;     //�v���C���[HP�i 3 �j
	playerInfo.isballHit=false;   //�{�[���Ƀq�b�g�������ǂ���
	playerInfo.count = 0;        //���G���Ԃ̃J�E���^

	//HP�\��������
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
	int hndl_m = LoadGraph(BALL_PATH);
	//�J�E���g������
	startcountInfo.startcounthandle1 = LoadGraph(START_COUNT1_PATH);
	startcountInfo.startcounthandle2 = LoadGraph(START_COUNT2_PATH);
	startcountInfo.startcounthandle3= LoadGraph(START_COUNT3_PATH);
	startcountInfo.starthandle = LoadGraph(START_PATH);
	//�G�t�F�N�g������
	InitEffect();
	LoadEffect(EFFECT_TYPE_EXPLOSION, 10);    //�G�t�F�N�g�̓ǂݍ���
	//BGM
	bgmhundle = LoadSoundMem(BGM_PATH);
	//SE������
	startcountSEhundle = LoadSoundMem(START_COUNT_SE_PATH);
	startSEhundle = LoadSoundMem(START_SE_PATH);
	ExplosionSEhundle = LoadSoundMem(EXPLOSION_SE_PATH);
	DamageSEhundle = LoadSoundMem(DAMAGE_SE_PATH);

	cnttime.Init();
	ball.Init();
}

void StepPlay()
{
	if (startcountflag == false) {
		startcount++;               //�J�E���g��i�߂Ă���
		if (startcount == 30) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //�J�E���g3 SE
		}
		if (startcount == 100) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //�J�E���g2 SE
		}
		if (startcount == 170) {
			PlaySoundMem(startcountSEhundle, DX_PLAYTYPE_BACK, true);    //�J�E���g1 SE
		}
		if (startcount == 240) {
			PlaySoundMem(startSEhundle, DX_PLAYTYPE_BACK, true);    //START SE
		}
		if (startcount >= 310) {
			startcountflag = true;
		}
	}

	if (startcountflag == true) {
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
		if (playerInfo.x < SCREEN_SIZE_X / 2 - 300 + 90) {
			playerInfo.x = playerInfo.x + 1;         //����
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.x = playerInfo.x + 4;     //�_�b�V�����̏���
			}
		}
		if (playerInfo.x + 76 > SCREEN_SIZE_X / 2 + 200 + 10) {
			playerInfo.x = playerInfo.x - 1;         //�E��
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.x = playerInfo.x - 4;     //�_�b�V�����̏���
			}
		}
		if (playerInfo.y + 76 > SCREEN_SIZE_Y / 2 + 200 + 10) {
			playerInfo.y = playerInfo.y - 1;         //����
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.y = playerInfo.y - 4;     //�_�b�V�����̏���
			}
		}
		if (playerInfo.y < SCREEN_SIZE_Y / 2 - 300 + 90) {
			playerInfo.y = playerInfo.y + 1;         //���
			if (CheckHitKey(KEY_INPUT_RSHIFT)) {
				playerInfo.y = playerInfo.y + 4;     //�_�b�V�����̏���
			}
		}
		//�v���C���[�ƃ{�[���Ƃ̓����蔻��
		if (playerInfo.playerhp >= 2) {        //HP��2�ȏ�
			if (IsHitCircle(playerInfo.x + 38, playerInfo.y + 38, 19,
				ball.GetballposX(), ball.GetballposY(), 19)) {
				//�v���C���[�ƓG���������Ă���ꍇ
				playerInfo.isballHit = true;
				if (playerInfo.isballHit && playerInfo.count == 0) {
					playerInfo.playerhp--;  //HP�����炷
					PlaySoundMem(DamageSEhundle, DX_PLAYTYPE_BACK, true);  //�T�E���h
					playerInfo.count = 150;  //���G���ԃZ�b�g
				}

				//���̐��ɗ����Ƃ�
				if (playerInfo.playerhp <= 0) {
					gameoverstopflag = true;
					if (gameoverstopcount == 0) {
						PlaySoundMem(ExplosionSEhundle, DX_PLAYTYPE_BACK, true);  //�T�E���h(����)
						PlayEffect(EFFECT_TYPE_EXPLOSION, playerInfo.x + 38, playerInfo.y + 38);
					}
				}
			}
		}
		if (playerInfo.playerhp <= 1) {        //HP��1�ȉ�
			if (IsHitCircle(playerInfo.x + 46, playerInfo.y + 46, 19,
				ball.GetballposX(), ball.GetballposY(), 19)) {
				//�v���C���[�ƓG���������Ă���ꍇ
				playerInfo.isballHit = true;
				if (playerInfo.isballHit && playerInfo.count == 0) {
					playerInfo.playerhp--;  //HP�����炷
					playerInfo.count = 150;  //���G���ԃZ�b�g
				}

				//���̐��ɗ����Ƃ�
				if (playerInfo.playerhp <= 0) {
					gameoverstopflag = true;
					if (gameoverstopcount == 0) {
						PlaySoundMem(ExplosionSEhundle, DX_PLAYTYPE_BACK, true);  //�T�E���h(����)
						PlayEffect(EFFECT_TYPE_EXPLOSION, playerInfo.x + 38, playerInfo.y + 38);
					}
				}
			}
		}
		
		//���G���ԏ���
		if (playerInfo.count > 0) {
			--playerInfo.count;
			if (playerInfo.count <= 0) {
				//���G���ԏI���
				playerInfo.count = 0;
				playerInfo.isballHit = false;
			}
		}
		//�X�g�b�v���[�V����
		if (gameoverstopflag == true) {
			gameoverstopcount++;
			if (gameoverstopcount == 300) {
				playerInfo.playerhp = 0;
				g_CurrentSceneID = SCENE_ID_FIN_PLAY;   //FIN��
				isNextClearScene = false;
			}
		}

		//�N���A����
		if (cnttime.GetTimerClear() == true) {     //�������Ԃ��O�ɂȂ�����
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;    //FIN�Ɉړ�
			isNextClearScene = true;                 //�N���A�����𖞂���
		}
		//�G�t�F�N�g�ʏ폈��
		StepEffect();
		if (gameoverstopflag == false) {
			cnttime.Step();
		}
		ball.Step();
		//ball[BALL_MAX_NUM].Step();
	}
}

void DrawPlay()
{
	//�w�i�`��
	DrawGraph(-10, -10, HaikeiHandle, true);

	//����Test (����)
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 225, 225), false);	//��
	/*DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 - 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//����
	DrawBox(SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 300, SCREEN_SIZE_Y / 2 + 200, GetColor(0, 100, 225), true);		//�E��
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 - 300, GetColor(0, 100, 225), true);		//���
	DrawBox(SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 + 200,
		SCREEN_SIZE_X / 2 + 200, SCREEN_SIZE_Y / 2 + 300, GetColor(0, 100, 225), true);		//����*/

	//�v���C���[�̕`��
	if (playerInfo.playerhp >= 2) {
		DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerhandle, true);
	}
	if (playerInfo.playerhp == 1) {
		DrawGraph(playerInfo.x, playerInfo.y, playerInfo.playerdiehandle, true);
	}
	ball.Draw();

	/*if (cnttimeM_m == 1 && cnttimeS_m == 30) {
		ball[1].Draw();
	}
	if (cnttimeM_m == 1 && cnttimeS_m == 0) {
		ball[2].Draw();
	}
	if (cnttimeM_m == 0 && cnttimeS_m == 45) {
		ball[3].Draw();
	}
	if (cnttimeM_m == 1 && cnttimeS_m == 30) {
		ball[4].Draw();
	}*/
	//�͂��`��
	DrawBox(playerhpInfo[2].x - 4, playerhpInfo[2].y - 6,
		playerhpInfo[0].x + 34, playerhpInfo[0].y + 32 + 6, GetColor(250, 210, 0), true);	//HP(����)
	DrawBox(playerhpInfo[2].x - 4, playerhpInfo[2].y - 6,
		playerhpInfo[0].x + 34, playerhpInfo[0].y + 32 + 6, GetColor(60, 60, 200), false);  //HP(�O��)
	DrawBox(-5, -5, 80, 20, GetColor(250, 210, 0), true);	//�c�莞��(����)
	DrawBox(-5, -5, 80, 20, GetColor(60, 60, 200), false); //�c�莞��(�O��)

	//HP�`��
	for (int i = 0; i < HP_MAX_NUM; i++) {
		if (playerInfo.playerhp >= 1) {
			DrawGraph(playerhpInfo[0].x, playerhpInfo[0].y, playerhpInfo[0].handle, true);
		}
		if (playerInfo.playerhp >= 2) {
			DrawGraph(playerhpInfo[1].x, playerhpInfo[1].y, playerhpInfo[1].handle, true);
		}
		if (playerInfo.playerhp == 3) {
			DrawGraph(playerhpInfo[2].x, playerhpInfo[2].y, playerhpInfo[2].handle, true);
		}
	}

	//�ŏ��̃J�E���g�`��
	if (startcountflag == false) {
		if (startcount >= 30) {
			if (startcount <= 100) {
				DrawGraph(320 - 61, 240 - 61, startcountInfo.startcounthandle3, true);
			}
		}
		if (startcount >= 100) {
			if (startcount <= 170) {
				DrawGraph(320 - 64, 240 - 64, startcountInfo.startcounthandle2, true);
			}
		}
		if (startcount >= 170) {
			if (startcount <= 240) {
				DrawGraph(320 - 56, 240 - 56, startcountInfo.startcounthandle1, true);
			}
		}
		if (startcount >= 240) {
			if (startcount <= 310) {
				DrawGraph(320 - 162, 240 - 61, startcountInfo.starthandle, true);
			}
		}
	}
	//�R�����g�\��
	DrawFormatString(playerhpInfo[2].x-27, playerhpInfo[2].y-4, GetColor(30, 30, 30), "HP");   //HP
	DrawFormatString(0, 23, GetColor(0, 100, 0), "�c�莞��");                                //�c�莞��

	//�G�t�F�N�g�`�揈��
	DrawEffect();
	cnttime.Draw();

}

void FinPlay()
{
	if (isNextClearScene) {
		playerInfo.playerhp = 3;
		gameoverstopcount = 0;
		startcountflag = false;
		startcount = 0;
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;  //�N���A�V�[����
	}
	else {
		playerInfo.playerhp = 3;
		gameoverstopflag = false;
		gameoverstopcount = 0;
		startcountflag = false;
		startcount = 0;
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;  //�Q�[���I�[�o�[��
	}
	//�G�t�F�N�g�㏈��
	FinEffect();
	//SE�j��
	DeleteSoundMem(startcountSEhundle);
	DeleteSoundMem(startSEhundle);
	DeleteSoundMem(ExplosionSEhundle);
	DeleteSoundMem(DamageSEhundle);

	cnttime.Fin();
	ball.Fin();
	//ball[BALL_MAX_NUM].Fin();
}