/*!
 *  @file       main.cpp
 *  @brief      �G���g���[�|�C���g
 */

#include "vivid.h"
#include "game_manager/game_manager.h"

 /*!
  *  @brief      �`��֐�
  */
void Display(void)
{
    // �Q�[���}�l�[�W���[�X�V
    CGameManager::GetInstance().Update();

    // �Q�[���}�l�[�W���[�`��
    CGameManager::GetInstance().Draw();
}

/*!
 *  @brief      ���C���֐�
 */
int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;

    // vivid���C�u����������
    vivid::Initialize(hInst);

    // �Q�[���}�l�[�W���[������
    CGameManager::GetInstance().Initialize();

    // �X�V/�`��֐��o�^
    vivid::DisplayFunction(Display);

    // �Q�[�����[�v
    vivid::MainLoop();

    // �Q�[���}�l�[�W���[���
    CGameManager::GetInstance().Finalize();

    // vivid���C�u�������
    vivid::Finalize();
}