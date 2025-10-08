#pragma once
/*
 * @file   IScene.h
 *
 * @brief  各シーン基底ヘッダ
 *
 * @author yone
 */

#include "vivid.h"

 /*
  * @class IScene
  *
  * @brief 各シーンの基底クラス
  */

class IScene
{
public:
	IScene();  // コンストラク
	~IScene(); // デストラクタ

	virtual void Initialize(); // 初期化
	virtual void Update();	   // 更新
	virtual void Draw();	   // 描画
	virtual void Finalize();   // 解放

protected:
	const float WINDOW_WIDTH = 1920.0f; //!< ウィンドウの横幅
	const float WINDOW_HEIGHT = 1080.0f; //!< ウィンドウの縦幅
};