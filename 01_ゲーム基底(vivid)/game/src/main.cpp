/*!
 *  @file       main.cpp
 *  @brief      エントリーポイント
 */

#include "vivid.h"
#include "game_manager/game_manager.h"

 /*!
  *  @brief      描画関数
  */
void Display(void)
{
    // ゲームマネージャー更新
    CGameManager::GetInstance().Update();

    // ゲームマネージャー描画
    CGameManager::GetInstance().Draw();
}

/*!
 *  @brief      メイン関数
 */
int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;

    // vividライブラリ初期化
    vivid::Initialize(hInst);

    // ゲームマネージャー初期化
    CGameManager::GetInstance().Initialize();

    // 更新/描画関数登録
    vivid::DisplayFunction(Display);

    // ゲームループ
    vivid::MainLoop();

    // ゲームマネージャー解放
    CGameManager::GetInstance().Finalize();

    // vividライブラリ解放
    vivid::Finalize();
}