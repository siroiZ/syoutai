#pragma once

// �{�[���N���X
class Ball {
private:
	float posX_m, posY_m;		// �{�[���̍��W
	float speedX_m, speedY_m;	// 
	int hndl_m;					// �摜�n���h��
public:
	void Init();				// ������
	void Step();				// �ʏ�
	void Draw();				// �`��
	void Fin();					// �I��

	float GetballposX() { return posX_m; };	// �i�{�[���̍��W����������擾�j
	float GetballposY() { return posY_m; };	

	void SetballspeedX(float x);	// �{�[���X�s�[�h�ݒ�
	void SetballspeedY(float y);

};

//�{�[�����\����
///*
struct BallInfo
{
	int handle;                       //�G�摜�n���h��
	int x, y;                         //�G���W
};
//*/