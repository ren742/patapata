#pragma once
#include "aqua.h"

class CStage
	:public::aqua::IGameObject
{
public:
	CStage(aqua::IGameObject* parent); // �R���X�g���N�^
	~CStage() = default; // �f�X�g���N�^

	void Initialize(); // ������
	void Update();	   // �X�V
	void Draw();	   // �`��
	void Finalize();   // ���

	void Change();	   // �V�[���؂�ւ�

private:
	aqua::CSprite	m_StageSprite;
	aqua::CVector2	m_Position;
	aqua::CVector2	m_Velocity;

};