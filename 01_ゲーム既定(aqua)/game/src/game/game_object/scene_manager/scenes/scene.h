#pragma once
/*
 * @file scene.h
 *
 * @brief シーン基底ヘッダ
 *
 * @author yone
 */

#include "aqua.h"

/*
 * @class IScene
 *
 * @brief シーン基底クラス
 *
 * @author yone
 */

class IScene :public aqua::IGameObject
{
public:
	IScene(aqua::IGameObject* parent); // コンストラクタ
	~IScene() = default; // デストラクタ

	void Initialize(); // 初期化
	void Update();	   // 更新
	void Draw();	   // 描画
	void Finalize();   // 解放

	void Change();	   // シーン切り替え

private:
};