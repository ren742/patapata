#include "ball_manager.h"
#include "ball/normal_ball/normal_ball.h"

CBallManager::CBallManager(aqua::IGameObject* parent)
	:IGameObject(parent, "BallManager", "Manager")
{
}

void CBallManager::Create(aqua::CVector2& position, float angle, float speed)
{
	CNormalBall* ball = aqua::CreateGameObject<CNormalBall>(this);

	if (!ball)
	{
		return;
	}

	ball->Initialize(position, angle, speed);
}