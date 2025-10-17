#include "stage.h"

CStage::CStage(aqua::IGameObject* parent)
	:IGameObject(parent, "Stage")
{
}

void CStage::Initialize()
{
	m_StageSprite.Create("date\\map\\stage.png");
}

void CStage::Update()
{
}

void CStage::Draw()
{
	m_StageSprite.Draw();
}

void CStage::Finalize()
{
}

void CStage::Change()
{
}
