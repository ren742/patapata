#pragma once
#include"aqua.h"

enum class PLAYER_STATE
{
	ACTIVE,
	DOWN,
};

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

	void MoveArea(void);

private:

	void Shot(void);

	aqua::CSprite				m_Player;	//�X�v���C�g�I�u�W�F�N�g

	aqua::CVector2				m_Velocity;
    
	aqua::CLabel				m_Label;

	static const int			m_Speed;

	int							m_Count_ball;	// �{�[���̏�����
	int							m_Max_ball;		// �{�[���̍ő及����

	bool						m_RareFlag;		// ���A�ʂ̏����t���O
};
