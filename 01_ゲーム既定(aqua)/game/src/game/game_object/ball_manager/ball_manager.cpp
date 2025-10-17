#include "ball_manager.h"
#include "ball/normal_ball/normal_ball.h"

CBallManager::CBallManager(aqua::IGameObject* parent)
	:IGameObject(parent, "BallManager", "Manager")
{
}

void CBallManager::Create(aqua::CVector2& position, float angle, float speed)
{
	CBall* normal_ball = nullptr;
	CBallEase* ball_ease = nullptr;

	switch (id)
	{
	case BALL_ID::NORMAL:
		ball = aqua::CreateGameObject<CBall>(this);

		if (!ball)
		{
			return;
		}

		ball->Initialize(position, angle, speed);

		break;
	case BALL_ID::EASE:
		ball_ease = aqua::CreateGameObject<CBallEase>(this);

		if (!ball_ease)
		{
			return;
		}

		ball_ease->Initialize(position);

		break;
	default:
		break;
	}

}