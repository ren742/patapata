#pragma once
#include <string>

class Movie
{
public:
    static Movie& GetInstance();

    void Initialize();      // DX���C�u����������
    void Finalize();        // DX���C�u�����I��
    bool Load(const std::string& filepass); // ���惍�[�h
    bool Play(const std::string& filepass); // ����Đ�
    void Display(int x, int y);             // ����`��
    void Stop();                            // �Đ���~
    bool IsPlaying() const;                 // �Đ������ǂ���

private:
    std::string m_FilePass;   //!< �t�@�C���p�X
    int m_Handle = -1;        //!< ���惍�[�h(-1=�����[�h�E����)
    bool m_IsPlaying = false; //!< �v���C���t���O

    // �ȉ��R���X�g���N��
    Movie() = default;
    ~Movie() = default;
    Movie(const Movie&) = delete;
    Movie& operator=(const Movie&) = delete;
};