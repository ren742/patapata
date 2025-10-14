#include "ball_manager.h"

CBallManager::CBallManager(aqua::IGameObject* parent)
	:IGameObject(parent, "BallManager", "Manager")
{
}

void CBallManager::Create(aqua::CVector2& position, float angle, float speed)
{
	//CBall* ball = aqua::CreateGameObject<CBall>(this);

	//if (!ball)
	//{
	//	return;
	//}

	//ball->Initialize(position, angle, speed);
}
