#include "player.h"

CPlayer::CPlayer(aqua::IGameObject* parent)
	: IGameObject(parent, "Player")
	, m_Velocity(0.0f, 0.0f)
{
}

void CPlayer::Initialize(void)
{
	m_Velocity = aqua::CVector2(1.0f, 0.0f);

	m_Player.Create("data//1player.png");
}

void CPlayer::Update(void)
{
	m_Player.position += m_Velocity;
	
	m_Player.rotation += aqua::DegToRad(10.0f);
}

void CPlayer::Draw(void)
{
	m_Player.Draw();
}

void CPlayer::Finalize(void)
{
	m_Player.Delete();
}
