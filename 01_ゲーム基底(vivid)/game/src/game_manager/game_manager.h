#pragma once

/*
 * @file game_manager.h
 *
 * @brief ゲーム管理ヘッダ
 *
 * @author yone
 */

#include "vivid.h"

 /*
  * @class CGameManager
  *
  * @brief ゲーム管理クラス
  *
  * @author yone
  */

class CGameManager
{
public:
	static CGameManager& GetInstance(); // インスタンス取得

	void Initialize(); // 初期化
	void Update();	   // 更新
	void Draw();	   // 描画
	void Finalize();   // 解放

private:

	// 以下コンストラクタ類
	CGameManager() = default;
	~CGameManager() = default;

	CGameManager(const CGameManager& rhs) = delete;
	CGameManager& operator=(const CGameManager& rhs) = delete;
};