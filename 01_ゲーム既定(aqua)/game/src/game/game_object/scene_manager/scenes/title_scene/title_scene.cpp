#include "title_scene.h"

CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IGameObject(parent, "TitelScene")
{
	m_Sprite.Create("data\\ball.png");
}

void CTitleScene::Initialize()
{
	m_Sprite.Create("data\\objectTitle.png");
}

void CTitleScene::Update()
{
	
}

void CTitleScene::Draw()
{
	m_Sprite.Draw();
}

void CTitleScene::Finalize()
{
	m_Sprite.Delete();
}
