#pragma once

// �J�E���g���ԃN���X
class CntTimer {
private:
	int cnttimeM_m;		// ���^�C�������o�ϐ�
	int cnttimeS_m;		// �b�^�C�������o�ϐ�
	int cnttimeMS_m;	// �~���b�^�C�������o�ϐ�
	public:

		void Init();	// ����������
		void Step();	// �ʏ폈��
		void Draw();	// �`�揈��

};