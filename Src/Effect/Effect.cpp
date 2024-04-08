#include <DxLib.h>
#include "effect.h"

//��x�ɕ\���ł���G�t�F�N�g�ő吔
#define EFFECT_MAX_NUM		(20)

//�G�t�F�N�g�̃A�j���ő吔
#define EFFECT_ANIME_MAX_NUM	(4)	

//�G�t�F�N�g���
struct EffectInfo
{
	//���G�t�F�N�g�̎��
	EFFECT_TYPE type;

	//���摜�n���h��
	int imageHandle[EFFECT_ANIME_MAX_NUM];

	//�����W
	int x, y;

	//���g�p�t���O
	bool isUse;

	//���A�j����
	int animeUseNum;

	//�����݂̃A�j���ԍ�
	int currentAnimeIndex;

	//���P��������̕\������
	float changeTime;

	//�����݂̃A�j������
	float currentAnimeTime;
};

//�G�t�F�N�g���
EffectInfo effectInfo[EFFECT_MAX_NUM];

//�G�t�F�N�g�̃t�@�C���p�X
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
};

//�e�G�t�F�N�g�̃A�j����
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
};

//�e�G�t�F�N�g�̉摜������ [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
};

//�G�t�F�N�g�̉摜�T�C�Y
const int effectImageSize[EFFECT_TYPE_NUM] =
{
	64,	//EFFECT_TYPE_EXPLOSION
};

//�e�G�t�F�N�g�̃A�j���摜�؂�ւ�����
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
};

//�G�t�F�N�g�̓ǂݍ���
//����	�F�G�t�F�N�g�̎�ށA�쐬��
void LoadEffect(EFFECT_TYPE type, int create_num)
{
	for (int currentAnimeIndex = 0; currentAnimeIndex < create_num; currentAnimeIndex++) {

		for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++) {
			//���ǂݍ��݂��Ă��Ȃ��G�t�F�N�g����������
			//���i�ЂƂڂ̉摜�n���h�����[���Ȃ�ǂݍ��݂���ĂȂ��j
			if (effectInfo[effectIndex].imageHandle[0] == 0) {

				int AnimeInfoNumX = effectImageSplitNum[type][0];
				int AnimeInfoNumY = effectImageSplitNum[type][1];

				//
				int ImageSize = effectImageSize[type];

				//���摜�𕪊��ǂݍ���
				int success_flg = LoadDivGraph(effectFilePath[type], effectAnimeImgNum[type], effectImageSplitNum[type][0], effectImageSplitNum[type][1], ImageSize, ImageSize, effectInfo[effectIndex].imageHandle);

				//��������
				if (success_flg == 0)
				{
					//���A�j�������i�[
					effectInfo[effectIndex].animeUseNum = effectAnimeImgNum[type];

					//���P��������̕\�����Ԃ�ݒ�
					effectInfo[effectIndex].changeTime = effectChageTime[type];

					//���G�t�F�N�g�̎�ނ�ݒ�
					effectInfo[effectIndex].type = type;
				}

				//�����ۂɂ�����炸������
				break;
			}
		}
	}
}

//�G�t�F�N�g�̏�����
void InitEffect()
{
	//�����ׂẴG�t�F�N�g���̕ϐ����N���A����i�[���ɂ���j
	for (int effect_Index = 0; effect_Index < EFFECT_ANIME_MAX_NUM; effect_Index++)
	{
		effectInfo[effect_Index].x = 0;
		effectInfo[effect_Index].y = 0;
		effectInfo[effect_Index].animeUseNum = 0;
		effectInfo[effect_Index].currentAnimeIndex = 0;
		effectInfo[effect_Index].currentAnimeTime = 0.0f;
		effectInfo[effect_Index].changeTime = 0.0f;
		effectInfo[effect_Index].isUse = false;
		//effectInfo[effectIndex].type = EFFECT_TYPE_EXPLOSION;
		for (int i = 0; i < EFFECT_ANIME_MAX_NUM; i++)
		{
			effectInfo[effect_Index].imageHandle[i] = 0;
		}
	}

}

//�G�t�F�N�g�ʏ폈��
void StepEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//���g�p���Ȃ�A�j�����Ԃ��o�߂����āA�A�j���ԍ����X�V����
		if (effectInfo[effect_index].isUse == true /*effectInfo[effect_index].changeTime*/)
		{
			//���摜�؂�ւ��ɕK�v�Ȏ��Ԍo�߂�����
			if (effectInfo[effect_index].currentAnimeTime >= effectInfo[effect_index].changeTime)
			{
				//�����̉摜��
				effectInfo[effect_index].currentAnimeIndex++;
				//���v�����ԃ��Z�b�g
				effectInfo[effect_index].currentAnimeTime = 0.0f;
				//�����̉摜�����������Ȃ�
				if (effectInfo[effect_index].currentAnimeIndex >= effectInfo[effect_index].animeUseNum)
				{
					//���g�p���t���O��OFF��
					effectInfo[effect_index].isUse = false;
					//���ȉ��̏����͕s�v
					continue;
				}
			}
			//�����ԍX�V
			effectInfo[effect_index].currentAnimeTime += 1.0f / FRAME_RATE;
		}
	}
}

//�G�t�F�N�g�`�揈��
void DrawEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//���g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
		if (effectInfo[effect_index].isUse == true) {
			int x = effectInfo[effect_index].x;
			int y = effectInfo[effect_index].y;
			int handleIndex = effectInfo[effect_index].currentAnimeIndex;
			int imageHandle = effectInfo[effect_index].imageHandle[handleIndex];

			DrawRotaGraph(x, y, 1.0f, 0.0f, imageHandle, true);
		}
	}
}

//�G�t�F�N�g�̌㏈��
void FinEffect()
{
	//�����ׂẴG�t�F�N�g���폜����
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�����ׂč폜����
		for (int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
		{
			//���[���ȊO�Ȃ�폜����
			if (effectInfo[effect_index].imageHandle[anime_index] != 0)
			{
				//���摜�폜������ݒ肷��
				DeleteGraph(effectInfo[effect_index].imageHandle[anime_index]);

				//���폜������[�������Ă���
				effectInfo[effect_index].imageHandle[anime_index] = 0;
			}
		}
	}
}

//�G�t�F�N�g�̍Đ�
//����	�F�G�t�F�N�g�̎��, �w���W, �x���W, �P��������̕\������
void PlayEffect(EFFECT_TYPE type, int x, int y)
{
	//�����g�p�G�t�F�N�g��T���čĐ�
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//���g�p���Ȃ�ȉ��s��Ȃ�
		if (!effectInfo[effect_index].isUse) {
			//���^�C�v����v���� 
			if (effectInfo[effect_index].type == type) {
				//�����W�ݒ�
				effectInfo[effect_index].x = x;
				effectInfo[effect_index].y = y;
				//���v���p�̕ϐ����N���A
				effectInfo[effect_index].currentAnimeIndex = 0;
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//���g�p���ɂ���
				effectInfo[effect_index].isUse = true;
				break;
			}
		}
	}
}