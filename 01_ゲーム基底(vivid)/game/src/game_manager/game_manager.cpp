/*
 * @file GameManager.cpp
 *
 * @brief �Q�[���Ǘ�
 *
 * @author yone
 */

#include "game_manager.h"
#include "game_object/scene_manager/scene_manager.h"

 // �C���X�^���X�擾
CGameManager& CGameManager::GetInstance()
{
	static CGameManager instance;

	return instance;
}

// ������
void CGameManager::Initialize()
{
	CSceneManager::GetInstance().Initialize();
}

// �X�V
void CGameManager::Update()
{
	CSceneManager::GetInstance().Update();
}

// �`��
void CGameManager::Draw()
{
	CSceneManager::GetInstance().Draw();
}

// ���
void CGameManager::Finalize()
{
	CSceneManager::GetInstance().Finalize();
}
