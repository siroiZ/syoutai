#ifndef _SCENE_H_
#define _SCENE_H_

#define	SCREEN_SIZE_X	640	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	480	// Y�����̉�ʃT�C�Y���w��

//�V�[�����
#define SCENE_ID_INIT_TITLE  (100)     //�^�C�g���V�[����ID
#define SCENE_ID_LOOP_TITLE (101)
#define SCENE_ID_FIN_TITLE (102)

#define SCENE_ID_INIT_PLAY   (200)     //�v���C�V�[��ID
#define SCENE_ID_LOOP_PLAY   (201)
#define SCENE_ID_FIN_PLAY   (202)

extern int g_CurrentSceneID;  //���݂̃V�[��ID

#endif