#pragma once
#include "aqua.h"

class CStage
	:public::aqua::IGameObject
{
public:
	CStage(aqua::IGameObject* parent); // コンストラクタ
	~CStage() = default; // デストラクタ

	void Initialize(); // 初期化
	void Update();	   // 更新
	void Draw();	   // 描画
	void Finalize();   // 解放

	void Change();	   // シーン切り替え

private:
	aqua::CSprite	m_StageSprite;
	aqua::CVector2	m_Position;
	aqua::CVector2	m_Velocity;

};