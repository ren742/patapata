#pragma once

/* 
 * @file scene_manager.h
 * 
 * @brief �V�[���Ǘ��w�b�_
 * 
 * @author yone
 */

#include "aqua.h"
#include "scenes/scene.h"
#include "../scene_manager/scenes/title_scene/title_scene.h"

/*
 * @class CSceneManager
 *
 * @brief �V�[���Ǘ��N���X
 *
 * @author yone
 */

class CSceneManager : public aqua::IGameObject
{
public:
	CSceneManager(aqua::IGameObject* parent); // �R���X�g���N�^
	~CSceneManager() = default; // �f�X�g���N�^

	void Initialize(); // ������
	void Update();	   // �X�V
	void Draw();	   // �`��
	void Finalize();   // ���

	void Change();	   // �V�[���؂�ւ�

private:
	std::vector<IScene*> m_Scenes; // �V�[���̖؍\���i�q�V�[�����X�g�j
	IScene* m_CurrentScene;		   // ���݂̃V�[��
};