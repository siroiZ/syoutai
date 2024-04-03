#ifndef _SCENE_H_
#define _SCENE_H_

#define	SCREEN_SIZE_X	640	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	480	// Y方向の画面サイズを指定

//シーン情報
#define SCENE_ID_INIT_TITLE  (100)     //タイトルシーンのID
#define SCENE_ID_LOOP_TITLE (101)
#define SCENE_ID_FIN_TITLE (102)

#define SCENE_ID_INIT_PLAY   (200)     //プレイシーンID
#define SCENE_ID_LOOP_PLAY   (201)
#define SCENE_ID_FIN_PLAY   (202)

extern int g_CurrentSceneID;  //現在のシーンID

#endif