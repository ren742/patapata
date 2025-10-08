/*!
 *  @file   scene_manager.cpp
 *
 *  @brief  �V�[���Ǘ��t�@�C��
 *
 *  @author yone
 */

#include "scene_manager.h"

/*!
 * @brief �C���X�^���X�擾
 */
CSceneManager& CSceneManager::GetInstance()
{
	static CSceneManager instance;

	return instance;
}

/*!
 * @brief �V�[��������
 */
void CSceneManager::Initialize()
{
	switch (curr_scene)
	{
	// �_�~�[
	case SCENE_ID::DUMMY:
		break;
	
	// �^�C�g��
	case SCENE_ID::TITLE:
		break;

	// �Q�[�����C��
	case SCENE_ID::GAMEMAIN:
		break;
		
	// ���U���g
	case SCENE_ID::RESULT:
		break;

	// �Q�[���I�[�o�[
	case SCENE_ID::GAMEOVER:
		break;

	// �����L���O
	case SCENE_ID::RUNKING:
		break;
	default:
		break;
	}
}

/*!
 * @brief �V�[���X�V
 */
void CSceneManager::Update()
{
	switch (curr_scene)
	{
	// �_�~�[
	case SCENE_ID::DUMMY:    
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::TITLE);
		}
#endif // _DEBUG
		break;

	// �^�C�g��
	case SCENE_ID::TITLE:    
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::GAMEMAIN);
		}
#endif // _DEBUG
		break;

	// �Q�[�����C��
	case SCENE_ID::GAMEMAIN:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::RESULT);
		}
#endif // _DEBUG
		break;

	// ���U���g
	case SCENE_ID::RESULT:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::GAMEOVER);
		}
#endif // _DEBUG
		break;
	
	// �Q�[���I�[�o�[
	case SCENE_ID::GAMEOVER:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::RUNKING);
		}
#endif // _DEBUG
		break;

	// �����L���O
	case SCENE_ID::RUNKING:
#ifdef _DEBUG
		if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Q))
		{
			CSceneManager::ChangeScene(SCENE_ID::DUMMY);
		}
#endif // _DEBUG
		break;
	}
}

/*!
 * @brief �V�[���`��
 */
void CSceneManager::Draw()
{
	switch (curr_scene)
	{
	// �_�~�[
	case SCENE_ID::DUMMY:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:�_�~�[", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// �^�C�g��
	case SCENE_ID::TITLE:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:�^�C�g��", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// �Q�[�����C��
	case SCENE_ID::GAMEMAIN:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:�Q�[�����C��", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// ���U���g
	case SCENE_ID::RESULT:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:���U���g", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// �Q�[���I�[�o�[
	case SCENE_ID::GAMEOVER:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:�Q�[���I�[�o�[", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;

	// �����L���O
	case SCENE_ID::RUNKING:
#ifdef _DEBUG
		vivid::DrawText(40, "scene:�����L���O", vivid::Vector2::ZERO, 0xffffffff);
#endif // DEBUG
		break;
	default:
		float error_x = vivid::GetTextureWidth("data//error.png");
		float error_y = vivid::GetTextureHeight("data//error.png");

		vivid::Vector2 pos = { (vivid::GetWindowWidth() - error_x) / (2.0f),(vivid::GetWindowHeight() - error_y) / (2.0f) };

		vivid::DrawTexture("data//error.png", pos);
		break;
	}
}

/*!
 * @brief �V�[���J��
 */
void CSceneManager::Finalize()
{
	switch (curr_scene)
	{
	// �_�~�[
	case SCENE_ID::DUMMY:
		break;

	// �^�C�g��
	case SCENE_ID::TITLE:
		break;

	// �Q�[�����C��
	case SCENE_ID::GAMEMAIN:
		break;

	// ���U���g
	case SCENE_ID::RESULT:
		break;

	// �Q�[���I�[�o�[
	case SCENE_ID::GAMEOVER:
		break;

	// �����L���O
	case SCENE_ID::RUNKING:
		break;
	default:
		break;
	}
}

/*!
 * @brief �V�[���؂�ւ�
 * 
 * @param �؂�ւ���̃V�[��
 */
void CSceneManager::ChangeScene(SCENE_ID nextScene)
{
	// ���݂̃V�[�����J��
	CSceneManager::Finalize();

	// �V�[����؂�ւ���
	curr_scene = nextScene;

	// �؂�ւ���̃V�[����������
	CSceneManager::Initialize();
}
