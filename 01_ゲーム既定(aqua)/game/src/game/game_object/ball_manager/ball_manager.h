#pragma once
#include "aqua.h"

class CBallManager :public aqua::IGameObject
{
public:
	CBallManager(aqua::IGameObject* parent);
	~CBallManager(void) = default;

	void Create(aqua::CVector2& position, float angle, float speed);
};
