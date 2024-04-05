#ifndef _SCENE_PLAY_H_
#define _SCENE_PLAY_H_

void InitPlay();

void StepPlay();

void DrawPlay();

void FinPlay();

//���@���\����
struct PlayerInfo
{
	int playerhandle;		          //�v���C���[�摜�n���h��
	int x, y;                         //�v���C���[���W
	int playerhp;            //�v���C���[��HP
};

//���@HP���\����
struct PlayerHPInfo
{
	int handle;		//�摜�n���h��
	int x, y;		//���W
};

struct TekiInfo
{
	int enemyhandle;
	int enemyx;
	int enemyy;
};

#endif