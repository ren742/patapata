#pragma once

#include"aqua.h"

class CTitleScene :public aqua::IGameObject
{
public:
	CTitleScene(aqua::IGameObject* parent); // �R���X�g���N�^
	~CTitleScene() = default; // �f�X�g���N�^

	void Initialize(); // ������

	void Update();	   // �X�V

	void Draw();	   // �`��

	void Finalize();   // ���

private:
};