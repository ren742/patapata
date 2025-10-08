/*!
 *  @file   scene_manager.h
 *
 *  @brief  シーン管理ヘッダー
 *
 *  @author yone
 */

#pragma once
#include "vivid.h"
#include "scne_id.h"

/*!
 *  @class CSceneManager
 * 
 *  @brief シーン管理クラス
 */
class CSceneManager
{
public:
    static CSceneManager& GetInstance(void); // インスタンス取得


    void Initialize(void); // 初期化
    void Update(void);     // 更新
    void Draw(void);       // 描画
    void Finalize(void);   // 解放
    void ChangeScene(SCENE_ID nextScene); // シーン変更処理

private:
    SCENE_ID curr_scene; //!< 現在のシーン

    // 以下コンストラクタ類
    CSceneManager() = default;
    ~CSceneManager() = default;

    CSceneManager(const CSceneManager& rhs) = delete;
    CSceneManager& operator=(const CSceneManager& rhs) = delete;
};