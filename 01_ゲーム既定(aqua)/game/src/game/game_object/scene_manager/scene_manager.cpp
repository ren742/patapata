/*
 * @file scene_manager.cpp
 *
 * @brief シーン管理
 *
 * @author yone
 */

#include "scene_manager.h"

/*
 * @class CSceneManager
 *
 * @brief シーン管理クラス
 *
 * @author yone
 */

// コンストラクタ
CSceneManager::CSceneManager(aqua::IGameObject* parent) : aqua::IGameObject(parent, "SceneManager")
{
}

// 初期化
void CSceneManager::Initialize()
{
}

// 更新
void CSceneManager::Update()
{
}

// 描画
void CSceneManager::Draw()
{
}

// 解放
void CSceneManager::Finalize()
{
}

// シーン切り替え
void CSceneManager::Change()
{
}
