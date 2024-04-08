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

#define SCENE_ID_INIT_CLEAR   (300)    //�N���A�V�[����ID
#define SCENE_ID_LOOP_CLEAR   (301)
#define SCENE_ID_FIN_CLEAR   (302)

#define SCENE_ID_INIT_GAMEOVER   (400) //�Q�[���I�[�o�[�V�[����ID
#define SCENE_ID_LOOP_GAMEOVER   (401)
#define SCENE_ID_FIN_GAMEOVER   (402)


extern int g_CurrentSceneID;  //���݂̃V�[��ID
extern int cnttimeM_m;
extern int cnttimeS_m;

#endif