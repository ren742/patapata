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

	aqua::CSprite				m_Player;	//スプライトオブジェクト

	aqua::CVector2				m_Velocity;
    
	aqua::CLabel				m_Label;

	static const int			m_Speed;

	int							m_Count_ball;	// ボールの所持数
	int							m_Max_ball;		// ボールの最大所持数

	bool						m_RareFlag;		// レア玉の所持フラグ
};
