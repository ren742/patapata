/*!
 *  @file   scene_manager.h
 *
 *  @brief  �V�[���Ǘ��w�b�_�[
 *
 *  @author yone
 */

#pragma once
#include "vivid.h"
#include "scne_id.h"

/*!
 *  @class CSceneManager
 * 
 *  @brief �V�[���Ǘ��N���X
 */
class CSceneManager
{
public:
    static CSceneManager& GetInstance(void); // �C���X�^���X�擾


    void Initialize(void); // ������
    void Update(void);     // �X�V
    void Draw(void);       // �`��
    void Finalize(void);   // ���
    void ChangeScene(SCENE_ID nextScene); // �V�[���ύX����

private:
    SCENE_ID curr_scene; //!< ���݂̃V�[��

    // �ȉ��R���X�g���N�^��
    CSceneManager() = default;
    ~CSceneManager() = default;

    CSceneManager(const CSceneManager& rhs) = delete;
    CSceneManager& operator=(const CSceneManager& rhs) = delete;
};