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

//�G���\����
struct TekiInfo
{
	int handle;                       //�G�摜�n���h��
	int x, y;                         //�G���W
};

#endif