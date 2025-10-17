#include "normal_ball.h"

CNormalBall::CNormalBall(aqua::IGameObject* parent)
	:IGameObject(parent, "Ball")
	, m_Position(0.0f, 0.0f)
	, m_Velocity(0.0f, 0.0f)
{
}

void CNormalBall::Initialize(const aqua::CVector2& position, float angle, float speed)
{
	m_Sprite.Create("data\\ball.png");

	m_Position = position;

	const float rad = aqua::DegToRad(angle);
	m_Velocity.x = cos(rad) * speed;
	m_Velocity.y = sin(rad) * speed;
}

void CNormalBall::Update(void)
{
	// à íuÇÃçXêV
	m_Position += m_Velocity * aqua::GetDeltaTime();

	// ï«ÇÃîªíË
	float w = (float)aqua::GetWindowWidth() - m_Sprite.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_Sprite.GetTextureHeight();

	if (m_Position.x < 0.0f)
	{
		m_Position.x = 0.0f - m_Position.x;
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.x > w)
	{
		m_Position.x = w - (m_Position.x - w);
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.y < 0.0f)
	{
		m_Position.y = 0.0f - m_Position.y;
		m_Velocity.y *= -1.0f;
	}
	if (m_Position.y > h)
	{
		m_Position.y = h - (m_Position.y - h);
		m_Velocity.y *= -1.0f;
	}

}

void CNormalBall::Draw(void)
{
	m_Sprite.position = m_Position;
	m_Sprite.Draw();
}

void CNormalBall::Finalize(void)
{
	m_Sprite.Delete();
}
