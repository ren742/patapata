#include "player.h"

const int CPlayer::m_Speed = 1.0f;

CPlayer::CPlayer(aqua::IGameObject* parent)
	: IGameObject(parent, "Player")
	, m_Velocity(0.0f, 0.0f)
{
}

void CPlayer::Initialize(void)
{
	m_Player.Create("data\\object\\1player.png");

	m_Velocity = aqua::CVector2(1.0f, 0.0f);

	m_Player.anchor.x = m_Player.GetTextureWidth() / 2.0f;
	m_Player.anchor.y = m_Player.GetTextureHeight() / 2.0f;

	m_Label.Create(30, 1);
	
	m_Label.position=aqua::CVector2(100.0f,100.0f);

	
}

void CPlayer::Update(void)
{
	m_Velocity = aqua::CVector2(0.0f, 0.0f);

	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::W))
	{
		m_Velocity.y -= m_Speed;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
	{
		m_Velocity.x -= m_Speed;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::S))
	{
		m_Velocity.y += m_Speed;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
	{
		m_Velocity.x += m_Speed;
	}
	if (m_Velocity != aqua::CVector2(0.0f, 0.0f))
	{
		m_Velocity = m_Velocity.Normalize();
		m_Player.rotation = atan2(m_Velocity.y, m_Velocity.x) - aqua::DegToRad(90);
	}

	m_Player.position += m_Velocity;

	
	
	m_Label.text = std::to_string(aqua::RadToDeg(m_Player.rotation)+90);
}

void CPlayer::Draw(void)
{
	m_Player.Draw();
	m_Label.Draw();
}

void CPlayer::Finalize(void)
{
	m_Player.Delete();
	m_Label.Delete();
}
