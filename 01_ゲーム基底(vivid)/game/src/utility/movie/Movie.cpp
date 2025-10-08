#include "Movie.h"
#include "DxLib.h"

// �V���O���g���C���X�^���X�擾
Movie& Movie::GetInstance()
{
    static Movie instance;
    return instance;
}

// DX���C�u����������
void Movie::Initialize()
{
    DxLib_Init();
}

// DX���C�u�����I������
void Movie::Finalize()
{
    // ����n���h�����L���Ȃ���
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }
    DxLib_End();
}

// ����t�@�C�������[�h�i�Đ��͂��Ȃ��j
bool Movie::Load(const std::string& filepass)
{
    // �����̓�������
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }

#ifndef UNICODE
    // �t�@�C�������瓮������[�h
    m_Handle = OpenMovieToGraph(filepass.c_str(), TRUE);
#else
    // UNICODE�̏ꍇ��wstring�ɕϊ����ă��[�h
    std::wstring wfilepass(filepass.begin(), filepass.end());
    m_Handle = OpenMovieToGraph(wfilepass.c_str(), TRUE);
#endif

    // ���[�h���s��
    if (m_Handle == -1)
    {
        m_IsPlaying = false;
        return false;
    }

    m_FilePass = filepass;
    m_IsPlaying = false; // �Đ��͂��Ȃ�
    return true;
}

// ��������[�h���Ă����Đ�
bool Movie::Play(const std::string& filepass)
{
    // �����̓�������
    if (m_Handle != -1)
    {
        DeleteGraph(m_Handle);
        m_Handle = -1;
    }

#ifndef UNICODE
    // �t�@�C�������瓮������[�h
    m_Handle = OpenMovieToGraph(filepass.c_str(), TRUE);
    // ���[�h�������ɍĐ��J�n
    if (m_Handle != -1) PlayMovieToGraph(m_Handle, DX_PLAYTYPE_BACK);
#else
    // UNICODE�̏ꍇ��wstring�ɕϊ����ă��[�h
    std::wstring wfilepass(filepass.begin(), filepass.end());
    m_Handle = OpenMovieToGraph(wfilepass.c_str(), TRUE);
    if (m_Handle != -1) PlayMovieToGraph(m_Handle, DX_PLAYTYPE_BACK);
#endif

    // ���[�h�܂��͍Đ����s��
    if (m_Handle == -1)
    {
        m_IsPlaying = false;
        return false;
    }

    m_FilePass = filepass;
    m_IsPlaying = true;
    return true;
}

// ������w����W�ɕ`��
void Movie::Display(int x, int y)
{
    if (m_Handle != -1 && m_IsPlaying)
    {
        // �Đ����Ȃ�`��
        if (GetMovieStateToGraph(m_Handle) == 1) 
        {
            DrawGraph(x, y, m_Handle, FALSE);
        }
        else {
            // �Đ����I�������t���O��������
            m_IsPlaying = false;
        }
    }
}

// �Đ���~�i�擪�ɖ߂��j
void Movie::Stop()
{
    if (m_Handle != -1)
    {
        SeekMovieToGraph(m_Handle, 0); // �擪�ɃV�[�N
        m_IsPlaying = false;
    }
}

// �Đ������ǂ�����Ԃ�
bool Movie::IsPlaying() const
{
    return m_IsPlaying;
}