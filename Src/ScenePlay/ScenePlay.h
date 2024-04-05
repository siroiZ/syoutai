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
	int playerdiehandle;              //�v���C���[(�s���`)�摜�n���h��
	int x, y;                         //�v���C���[���W
	int playerhp;            //�v���C���[��HP
};

//���@HP���\����
struct PlayerHPInfo
{
	int handle;		//�摜�n���h��
	int x, y;		//���W
};

struct StartCountInfo
{
	int startcounthandle1;
	int startcounthandle2;
	int startcounthandle3;
	int starthandle;
};

#endif