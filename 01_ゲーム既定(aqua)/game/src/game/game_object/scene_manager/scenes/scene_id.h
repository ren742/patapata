#pragma once

/* 
 * @file scene_id.h
 * 
 * @brief シーンID定義ファイル
 * 
 * @author yone
 */

#include "aqua.h"

/* 
 * @enum SCENE_ID
 * 
 * @brief シーンID定義
 * 
 * @author yone
 */

enum class SCENE_ID
{
	DUMMY,
	TITLE,			// タイトル
	SLECTPLAYER,	// 人数選択
	GAMEMAIN,		// ゲームメイン
	RESULT,			// リザルト
};