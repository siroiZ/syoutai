#pragma once

// �{�[���N���X
class Ball {
private:
	float posX_m, posY_m;		// �{�[���̍��W
	float speedX_m, speedY_m;	// �{�[�����x
	int hndl_m;					// �摜�n���h��
	int flgx_m;					// x�ǂɓ�������
	int flgy_m;					// y��
public:
	void Init();				// ������
	void Step();				// �ʏ�
	void Draw();				// �`��
	void Fin();					// �I��

	float GetballposX() { return posX_m; };	// �i�{�[���̍��W����������擾�j
	float GetballposY() { return posY_m; };	

	void UpballspeedX(float x);	// �{�[�����x�A�b�v
	void UpballspeedY(float y);

};

//�{�[�����\����
///*
struct BallInfo
{
	int handle;                       //�G�摜�n���h��
	int x, y;                         //�G���W
};
//*/