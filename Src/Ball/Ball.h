#pragma once

// �{�[���N���X
class Ball {
private:
	float posX_m, posY_m;	// �{�[���̍��W
	int hndl_m;				// �摜�n���h��
public:
	void Init();	// ������
	void Step();	// �ʏ�
	void Draw();	// �`��
	void Fin();		// �I��
};

//�{�[�����\����
struct BallInfo
{
	int handle;                       //�G�摜�n���h��
	int x, y;                         //�G���W
};