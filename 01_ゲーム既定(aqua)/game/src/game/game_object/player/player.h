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

	aqua::CSprite				m_Player;	//�X�v���C�g�I�u�W�F�N�g

	aqua::CVector2				m_Velocity;

};
