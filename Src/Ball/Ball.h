#pragma once

// �{�[���N���X
class Ball {
private:
	float posX_m, posY_m;	// �{�[���̍��W
public:
	void Init();	// ������
	void Step();	// �ʏ�
	void Draw();	// �`��
	void Fin();		// �I��
};