#pragma once
#include <string>

class Movie
{
public:
    static Movie& GetInstance();

    void Initialize();      // DXライブラリ初期化
    void Finalize();        // DXライブラリ終了
    bool Load(const std::string& filepass); // 動画ロード
    bool Play(const std::string& filepass); // 動画再生
    void Display(int x, int y);             // 動画描画
    void Stop();                            // 再生停止
    bool IsPlaying() const;                 // 再生中かどうか

private:
    std::string m_FilePass;   //!< ファイルパス
    int m_Handle = -1;        //!< 動画ロード(-1=未ロード・無効)
    bool m_IsPlaying = false; //!< プレイ中フラグ

    // 以下コンストラク類
    Movie() = default;
    ~Movie() = default;
    Movie(const Movie&) = delete;
    Movie& operator=(const Movie&) = delete;
};