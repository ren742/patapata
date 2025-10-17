#pragma once

#include"aqua.h"

class CTitleScene :public aqua::IGameObject
{
public:
	CTitleScene(aqua::IGameObject* parent); // コンストラクタ
	~CTitleScene() = default; // デストラクタ

	void Initialize(); // 初期化

	void Update();	   // 更新

	void Draw();	   // 描画

	void Finalize();   // 解放

private:
};