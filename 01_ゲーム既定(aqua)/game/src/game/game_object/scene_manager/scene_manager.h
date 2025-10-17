#pragma once

/* 
 * @file scene_manager.h
 * 
 * @brief シーン管理ヘッダ
 * 
 * @author yone
 */

#include "aqua.h"
#include "scenes/scene.h"
#include "../scene_manager/scenes/title_scene/title_scene.h"

/*
 * @class CSceneManager
 *
 * @brief シーン管理クラス
 *
 * @author yone
 */

class CSceneManager : public aqua::IGameObject
{
public:
	CSceneManager(aqua::IGameObject* parent); // コンストラクタ
	~CSceneManager() = default; // デストラクタ

	void Initialize(); // 初期化
	void Update();	   // 更新
	void Draw();	   // 描画
	void Finalize();   // 解放

	void Change();	   // シーン切り替え

private:
	std::vector<IScene*> m_Scenes; // シーンの木構造（子シーンリスト）
	IScene* m_CurrentScene;		   // 現在のシーン
};