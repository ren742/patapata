/*!
 *  @file   scene_manager.cpp
 *
 *  @brief  シーン管理ファイル
 *
 *  @author yone
 */

#include "scene_manager.h"

/*!
 * @brief インスタンス取得
 */
CSceneManager& CSceneManager::GetInstance()
{
	static CSceneManager instance;

	return instance;
}

/*!
 * @brief シーン初期化
 */
void CSceneManager::Initialize()
{
	switch (curr_scene)
	{
	// ダミー
	case SCENE_ID::DUMMY:
		break;
	
	// タイトル
	case SCENE_ID::TITLE:
		break;

	// ゲームメイン
	case SCENE_ID::GAMEMAIN:
		break;
		
	// リザルト
	case SCENE_ID::RESULT:
		break;

	// ゲームオーバー
	case SCENE_ID::GAMEOVER:
		break;

	// ランキング
	case SCENE_ID::RUNKING:
		break;
	default:
		break;
	}
}

/*!
 * @brief シーン更新
 */
void CSceneManager::Update()
{
	switch (curr_scene)
	{
	// ダミー
	case SCENE_ID::DUMMY:    
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::TITLE);
		}
#endif // _DEBUG
		break;

	// タイトル
	case SCENE_ID::TITLE:    
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::GAMEMAIN);
		}
#endif // _DEBUG
		break;

	// ゲームメイン
	case SCENE_ID::GAMEMAIN:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::RESULT);
		}
#endif // _DEBUG
		break;

	// リザルト
	case SCENE_ID::RESULT:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::GAMEOVER);
		}
#endif // _DEBUG
		break;
	
	// ゲームオーバー
	case SCENE_ID::GAMEOVER:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::RUNKING);
		}
#endif // _DEBUG
		break;

	// ランキング
	case SCENE_ID::RUNKING:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::DUMMY);
		}
#endif // _DEBUG
		break;
	}
}

/*!
 * @brief シーン描画
 */
void CSceneManager::Draw()
{
	switch (curr_scene)
	{
	// ダミー
	case SCENE_ID::DUMMY:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:ダミー", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// タイトル
	case SCENE_ID::TITLE:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:タイトル", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// ゲームメイン
	case SCENE_ID::GAMEMAIN:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:ゲームメイン", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// リザルト
	case SCENE_ID::RESULT:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:リザルト", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// ゲームオーバー
	case SCENE_ID::GAMEOVER:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:ゲームオーバー", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// ランキング
	case SCENE_ID::RUNKING:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:ランキング", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;
	default:
		float error_x = vivid::GetTextureWidth("data//error.png");
		float error_y = vivid::GetTextureHeight("data//error.png");

		vivid::Vector2 pos = { (vivid::GetWindowWidth() - error_x) / (2.0f),(vivid::GetWindowHeight() - error_y) / (2.0f) };

		vivid::DrawTexture("data//error.png", pos);
		break;
	}
}

/*!
 * @brief シーン開放
 */
void CSceneManager::Finalize()
{
	switch (curr_scene)
	{
	// ダミー
	case SCENE_ID::DUMMY:
		break;

	// タイトル
	case SCENE_ID::TITLE:
		break;

	// ゲームメイン
	case SCENE_ID::GAMEMAIN:
		break;

	// リザルト
	case SCENE_ID::RESULT:
		break;

	// ゲームオーバー
	case SCENE_ID::GAMEOVER:
		break;

	// ランキング
	case SCENE_ID::RUNKING:
		break;
	default:
		break;
	}
}

/*!
 * @brief シーン切り替え
 * 
 * @param 切り替え後のシーン
 */
void CSceneManager::ChangeScene(SCENE_ID nextScene)
{
	// 現在のシーンを開放
	CSceneManager::Finalize();

	// シーンを切り替える
	curr_scene = nextScene;

	// 切り替え後のシーンを初期化
	CSceneManager::Initialize();
}
