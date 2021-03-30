//=============================================================================
//
//	�Z���t�e�N���X [talk_bass.cpp]
//	Author:���� �r�H
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "talk_base.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "renderer.h"
#include "manager.h"
#include "sound.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define TEXTURE_PATH_TALK_1 "Data/Texture/talk_bass/serifu1.png"
#define TEXTURE_PATH_TALK_2 "Data/Texture/talk_bass/serifu2.png"
#define TEXTURE_PATH_TALK_3 "Data/Texture/talk_bass/serifu3.png"
#define TEXTURE_PATH_TALK_4 "Data/Texture/talk_bass/serifu4.png"
#define TEXTURE_PATH_TALK_5 "Data/Texture/talk_bass/serifu5.png"
#define TEXTURE_PATH_TALK_6 "Data/Texture/talk_bass/serifu6.png"
#define TEXTURE_PATH_TALK_7 "Data/Texture/talk_bass/serifu7.png"
#define TEXTURE_PATH_TALK_8 "Data/Texture/talk_bass/serifu8.png"
#define TEXTURE_PATH_TALK_9 "Data/Texture/talk_bass/serifu9.png"
#define TEXTURE_PATH_TALK_10 "Data/Texture/talk_bass/serifu10.png"
#define TEXTURE_PATH_TALK_11 "Data/Texture/talk_bass/serifu11.png"
#define TEXTURE_PATH_TALK_12 "Data/Texture/talk_bass/serifu12.png"

#define FADE_RATE 0.03f

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CTalkbase::m_apTexture[TALK_MAX] = {};
CTalkbase::TALK CTalkbase::m_Talk = CTalkbase::TALK_NONE;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTalkbase::CTalkbase(int nPriorit) :CUi(nPriorit)
{
	m_Fade		 = FADE_NONE;
	m_bTalkEnd	 = false;
	m_col		 = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
	m_nAppear	 = 0;
	m_nTalkCount = 0;
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTalkbase::~CTalkbase()
{
}

//=============================================================================
// ���[�h����
//=============================================================================
HRESULT CTalkbase::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	// �e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_1, &m_apTexture[TALK_1]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_2, &m_apTexture[TALK_2]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_3, &m_apTexture[TALK_3]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_4, &m_apTexture[TALK_4]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_5, &m_apTexture[TALK_5]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_6, &m_apTexture[TALK_6]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_7, &m_apTexture[TALK_7]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_8, &m_apTexture[TALK_8]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_9, &m_apTexture[TALK_9]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_10, &m_apTexture[TALK_10]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_11, &m_apTexture[TALK_11]);
	D3DXCreateTextureFromFile(pDevice, TEXTURE_PATH_TALK_12, &m_apTexture[TALK_12]);
	return S_OK;
}

//=============================================================================
// �A�����[�h����
//=============================================================================
void CTalkbase::Unload(void)
{
	for (int nCount = 0; nCount < TALK_MAX; nCount++)
	{
		if (m_apTexture[nCount] != NULL)
		{
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = NULL;
		}
	}
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTalkbase::Init(void)
{

	//�J���[�Z�b�g
	SetCol(m_col);
	//����������
	CUi::Init();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTalkbase::Uninit(void)
{
	CUi::Uninit();

	Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CTalkbase::Update(void)
{
	CUi::Update();
	//�g�[�N����
	Talk();
	//�t�F�[�h�C���E�A�E�g�̏���
	Blackout();
}

//=============================================================================
// �g�[�N�����ɐi�߂�֐�
//=============================================================================
void CTalkbase::Talk(void)
{
	//�L�[�{�[�h���͎擾
	CInputKeyboard* pKeyInput = (CInputKeyboard*)CManager::GetInputKey();
	//�R���g���[���[���͎擾
	CInputJoyStick* pJoyInput = (CInputJoyStick*)CManager::GetInputController();
	//���͊m�F�X�C�b�`
	bool bJoyStick = false;
	//�R���g���[���[���͊m�F
	if (pJoyInput != NULL)
	{
		if (pJoyInput->GetJoyStickTrigger(CInputJoyStick::JOY_BUTTON_A)) bJoyStick = true;
	}

	//�J�E���g�A�b�v
	m_nTalkCount++;

	//�J�E���g�����ɒB������ || �L�[����������||�{�^������������
	if (m_nTalkCount >= m_nAppear || pKeyInput->GetKeyTrigger(DIK_SPACE)|| bJoyStick)
	{
		//�t�F�[�h�󋵐ݒ�
		m_Fade = FADE_OUT;
	
		//�J�E���g������
		m_nTalkCount = 0;
	}

}

//=============================================================================
// �Ó]�̐ݒ�
//=============================================================================
void CTalkbase::Blackout(void)
{
	//�t�F�[�h�A�E�g��
	if (m_Fade == FADE_OUT)
	{
		//����
		m_col.a -= FADE_RATE;

		//��������
		if (m_col.a <= 0.0f)
		{
			//������
			m_col.a = 0.0f;
			m_Fade = FADE_NONE;
			m_bTalkEnd = true;
		}
	}
	// �t�F�[�h�C����
	else if (m_Fade == FADE_IN)
	{
		//�s������
		m_col.a += FADE_RATE;

		//�o���d�؂�����
		if (m_col.a >= 1.0f)
		{
			m_col.a = 1.0f;
		}

	}

	//�J���[�Z�b�g
	SetCol(m_col);

}

//=============================================================================
// �o�����ԃZ�b�^�[
//=============================================================================
void CTalkbase::SetAppear(int nAppear)
{
	m_nAppear = nAppear;
}

//=============================================================================
// �o�����ԃQ�b�^�[
//=============================================================================
int CTalkbase::GetAppear(void)
{
	return m_nAppear;
}

//=============================================================================
// �t�F�[�h��ԃZ�b�^�[
//=============================================================================
void CTalkbase::SetFade(TALK_FADE FadeStatus)
{
	m_Fade = FadeStatus;
}

//=============================================================================
// �t�F�[�h��ԃQ�b�^�[
//=============================================================================
CTalkbase::TALK_FADE CTalkbase::GetFade(void)
{
	return m_Fade;
}

//=============================================================================
// �I���t���O�Q�b�^�[
//=============================================================================
bool CTalkbase::GetTalkEnd(void)
{
	return m_bTalkEnd;
}


//=============================================================================
// �g�[�N�̐ݒ�
//=============================================================================
void CTalkbase::SetTalk(TALK talk)
{
	m_Talk = talk;
}

//=============================================================================
// �g�[�N�̃Q�b�^�[����
//=============================================================================
CTalkbase::TALK CTalkbase::GetTalk(void)
{
	return m_Talk;
}

//=============================================================================
// �e�N�X�`���̍X�V
//=============================================================================
void CTalkbase::BindTalkTexture(TALK talk)
{
	BindTexture(m_apTexture[talk]);
	SetTalk(talk);
	//BGM�̍Đ�
	CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_MESSAGE);
}

//=============================================================================
// �e�N�X�`���̐؂�ւ�
//=============================================================================
void CTalkbase::SetFlagTex(TALK talk)
{
	// �A���t�@�l���[���ɂȂ�܂ōX�V���Ȃ�
	if (m_col.a <= 0.0f)
	{
		BindTexture(m_apTexture[talk]);
		SetTalk(talk);
	}
}
