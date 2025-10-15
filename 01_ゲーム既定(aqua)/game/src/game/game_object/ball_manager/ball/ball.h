#pragma once
#include "aqua.h"

class CBall :public aqua::IGameObject
{
public:
	CBall(aqua::IGameObject* parent);
	~CBall(void) = default;

	void Initialize(const aqua::CVector2& position, float angle, float speed);

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;

private:

	aqua::CSprite	m_Sprite;
	aqua::CVector2	m_Position;
	aqua::CVector2	m_Velocity;
};