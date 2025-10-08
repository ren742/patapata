#pragma once
/*
 * @file scene.h
 *
 * @brief �V�[�����w�b�_
 *
 * @author yone
 */

#include "aqua.h"

/*
 * @class IScene
 *
 * @brief �V�[�����N���X
 *
 * @author yone
 */

class IScene :public aqua::IGameObject
{
public:
	IScene(aqua::IGameObject* parent); // �R���X�g���N�^
	~IScene() = default; // �f�X�g���N�^

	void Initialize(); // ������
	void Update();	   // �X�V
	void Draw();	   // �`��
	void Finalize();   // ���

	void Change();	   // �V�[���؂�ւ�

private:
};