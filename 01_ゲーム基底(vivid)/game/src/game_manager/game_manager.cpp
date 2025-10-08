/*
 * @file GameManager.cpp
 *
 * @brief ゲーム管理
 *
 * @author yone
 */

#include "game_manager.h"
#include "game_object/scene_manager/scene_manager.h"

 // インスタンス取得
CGameManager& CGameManager::GetInstance()
{
	static CGameManager instance;

	return instance;
}

// 初期化
void CGameManager::Initialize()
{
	CSceneManager::GetInstance().Initialize();
}

// 更新
void CGameManager::Update()
{
	CSceneManager::GetInstance().Update();
}

// 描画
void CGameManager::Draw()
{
	CSceneManager::GetInstance().Draw();
}

// 解放
void CGameManager::Finalize()
{
	CSceneManager::GetInstance().Finalize();
}
