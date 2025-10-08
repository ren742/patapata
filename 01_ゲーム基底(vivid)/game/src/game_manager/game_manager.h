#pragma once

/*
 * @file game_manager.h
 *
 * @brief �Q�[���Ǘ��w�b�_
 *
 * @author yone
 */

#include "vivid.h"

 /*
  * @class CGameManager
  *
  * @brief �Q�[���Ǘ��N���X
  *
  * @author yone
  */

class CGameManager
{
public:
	static CGameManager& GetInstance(); // �C���X�^���X�擾

	void Initialize(); // ������
	void Update();	   // �X�V
	void Draw();	   // �`��
	void Finalize();   // ���

private:

	// �ȉ��R���X�g���N�^��
	CGameManager() = default;
	~CGameManager() = default;

	CGameManager(const CGameManager& rhs) = delete;
	CGameManager& operator=(const CGameManager& rhs) = delete;
};