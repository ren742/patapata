#pragma once
/*
 * @file   IScene.h
 *
 * @brief  �e�V�[�����w�b�_
 *
 * @author yone
 */

#include "vivid.h"

 /*
  * @class IScene
  *
  * @brief �e�V�[���̊��N���X
  */

class IScene
{
public:
	IScene();  // �R���X�g���N
	~IScene(); // �f�X�g���N�^

	virtual void Initialize(); // ������
	virtual void Update();	   // �X�V
	virtual void Draw();	   // �`��
	virtual void Finalize();   // ���

protected:
	const float WINDOW_WIDTH = 1920.0f; //!< �E�B���h�E�̉���
	const float WINDOW_HEIGHT = 1080.0f; //!< �E�B���h�E�̏c��
};