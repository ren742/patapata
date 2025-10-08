/*
 * @file scene.cpp
 *
 * @brief シーン基底ファイル
 *
 * @author yone
 */

#include "scene.h"

/*
 * @class IScene
 *
 * @brief シーン基底クラス
 *
 * @author yone
 */

// コンストラクタ
IScene::IScene(aqua::IGameObject* parent) : aqua::IGameObject(parent, "IScene")
{
}

// 初期化
void IScene::Initialize()
{
}

// 更新
void IScene::Update()
{
}

// 描画
void IScene::Draw()
{
}

// 解放
void IScene::Finalize()
{
}

// シーン切り替え
void IScene::Change()
{
}
