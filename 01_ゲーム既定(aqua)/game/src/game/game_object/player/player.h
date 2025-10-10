#pragma once
#include"aqua.h"

class CPlayer
	:public aqua::IGameObject
{
public:

	CPlayer(aqua::IGameObject* parent);
	~CPlayer() = default;

	void Initialize(void) override;

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;

private:

	aqua::CSprite				m_Player;	//スプライトオブジェクト

	aqua::CVector2				m_Velocity;

};
