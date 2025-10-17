#pragma once
#include "aqua.h"

class CNormalBall :public aqua::IGameObject
{
public:
	CNormalBall(aqua::IGameObject* parent);
	~CNormalBall(void) = default;

	void Initialize(const aqua::CVector2& position, float angle, float speed);

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;

private:

	aqua::CSprite	m_Sprite;
	aqua::CVector2	m_Position;
	aqua::CVector2	m_Velocity;
};