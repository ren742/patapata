/*
 * @file scene.cpp
 *
 * @brief �V�[�����t�@�C��
 *
 * @author yone
 */

#include "scene.h"

/*
 * @class IScene
 *
 * @brief �V�[�����N���X
 *
 * @author yone
 */

// �R���X�g���N�^
IScene::IScene(aqua::IGameObject* parent) : aqua::IGameObject(parent, "IScene")
{
}

// ������
void IScene::Initialize()
{
}

// �X�V
void IScene::Update()
{
}

// �`��
void IScene::Draw()
{
}

// ���
void IScene::Finalize()
{
}

// �V�[���؂�ւ�
void IScene::Change()
{
}
