#include "Movie.h"
#include "DxLib.h"

// シングルトンインスタンス取得
Movie& Movie::GetInstance()
{
    static Movie instance;
    return instance;
}

// DXライブラリ初期化
void Movie::Initialize()
{
    DxLib_Init();
}

// DXライブラリ終了処理
void Movie::Finalize()
{
    // 動画ハンドルが有効なら解放
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }
    DxLib_End();
}

// 動画ファイルをロード（再生はしない）
bool Movie::Load(const std::string& filepass)
{
    // 既存の動画を解放
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }

#ifndef UNICODE
    // ファイル名から動画をロード
    m_Handle = OpenMovieToGraph(filepass.c_str(), TRUE);
#else
    // UNICODEの場合はwstringに変換してロード
    std::wstring wfilepass(filepass.begin(), filepass.end());
    m_Handle = OpenMovieToGraph(wfilepass.c_str(), TRUE);
#endif

    // ロード失敗時
    if (m_Handle == -1)
    {
        m_IsPlaying = false;
        return false;
    }

    m_FilePass = filepass;
    m_IsPlaying = false; // 再生はしない
    return true;
}

// 動画をロードしてすぐ再生
bool Movie::Play(const std::string& filepass)
{
    // 既存の動画を解放
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }

#ifndef UNICODE
    // ファイル名から動画をロード
    m_Handle = OpenMovieToGraph(filepass.c_str(), TRUE);
    // ロード成功時に再生開始
    if (m_Handle != -1) PlayMovieToGraph(m_Handle, DX_PLAYTYPE_BACK);
#else
    // UNICODEの場合はwstringに変換してロード
    std::wstring wfilepass(filepass.begin(), filepass.end());
    m_Handle = OpenMovieToGraph(wfilepass.c_str(), TRUE);
    if (m_Handle != -1) PlayMovieToGraph(m_Handle, DX_PLAYTYPE_BACK);
#endif

    // ロードまたは再生失敗時
    if (m_Handle == -1)
    {
        m_IsPlaying = false;
        return false;
    }

    m_FilePass = filepass;
    m_IsPlaying = true;
    return true;
}

// 動画を指定座標に描画
void Movie::Display(int x, int y)
{
    if (m_Handle != -1 && m_IsPlaying)
    {
        // 再生中なら描画
        if (GetMovieStateToGraph(m_Handle) == 1) 
        {
            DrawGraph(x, y, m_Handle, FALSE);
        }
        else {
            // 再生が終わったらフラグを下げる
            m_IsPlaying = false;
        }
    }
}

// 再生停止（先頭に戻す）
void Movie::Stop()
{
    if (m_Handle != -1)
    {
        SeekMovieToGraph(m_Handle, 0); // 先頭にシーク
        m_IsPlaying = false;
    }
}

// 再生中かどうかを返す
bool Movie::IsPlaying() const
{
    return m_IsPlaying;
}