#pragma once

// �J�E���g���ԃN���X
class CntTimer {
private:
	int cnttimeM_m;		// ���^�C�������o�ϐ�
	int cnttimeS_m;		// �b�^�C�������o�ϐ�
	int cnttimeMS_m;	// �~���b�^�C�������o�ϐ�
	float cnttimeball_m;// ���Ԍo�߂Ń{�[���̑��x�A�b�v
	bool timeclear_m;	// �c�莞��0�ɂȂ����Ƃ�true�ɂ���
	public:

		void Init();	// ����������
		void Step();	// �ʏ폈��
		void Draw();	// �`�揈��
		void Fin();		// �I������

		bool GetTimerClear() { return timeclear_m; };	// �N���A�ϐ��擾�i�c�莞�ԂO�ɂȂ�����N���A�ɂ��������߁j
		// float GetCountTime() { return cnttimeball_m; };	// ���Ԍo�߃{�[�����x�㏸�ϐ��擾

};