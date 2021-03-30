//=============================================================================
//
//	���X�^�[�g�{�^��[restart button.cpp]
//	Author:�g�c�@�I�l
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "restart button.h"
#include "renderer.h"
#include "manager.h"
#include "sound.h"
#include "inputcontroller.h"
#include "inputkeyboard.h"
#include "fade.h"

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
TEXTURE_DATA CRestartButton::m_TextureData = { NULL,	"Data/Texture/button/restart.png", };

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRestartButton::CRestartButton()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRestartButton::~CRestartButton()
{
}

//=============================================================================
// �e�N�X�`���ǂݍ���
//=============================================================================
HRESULT CRestartButton::Load(void)
{
	//�f�o�C�X�擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		m_TextureData.m_cFileName,
		&m_TextureData.m_pTexture);

	return S_OK;
}

//=============================================================================
// �e�N�X�`���̔j��
//=============================================================================
void CRestartButton::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_TextureData.m_pTexture != NULL)
	{
		m_TextureData.m_pTexture->Release();
		m_TextureData.m_pTexture = NULL;
	}
}

//=============================================================================
// ��������
//=============================================================================
CRestartButton * CRestartButton::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//�������m��
	CRestartButton *pRestartButton = NULL;
	pRestartButton = new CRestartButton;

	//NULL�`�F�b�N
	if (pRestartButton != NULL)
	{
		//�ʒu�ݒ�
		pRestartButton->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
		//�T�C�Y�ݒ�
		pRestartButton->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
		//�e�N�X�`���ݒ�
		pRestartButton->BindTexture(m_TextureData.m_pTexture);
		//����������
		pRestartButton->Init();
	}
	return pRestartButton;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRestartButton::Init(void)
{

	CButton::Init();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CRestartButton::Uninit(void)
{
	CButton::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CRestartButton::Update(void)
{
	CButton::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CRestartButton::Draw(void)
{
	CButton::Draw();
}


//=============================================================================
// �v�b�V�����菈��
//=============================================================================
void CRestartButton::Push()
{
	//�t�F�C�h�擾
	CFade*	pBlackout = CManager::GetFadeout();
	//�L�[���͎擾
	CInputKeyboard* pInputKey = (CInputKeyboard*)CManager::GetInputKey();
	// �R���g���[���[���͂̎擾
	CInputJoyStick* pJoyInput = (CInputJoyStick*)CManager::GetInputController();
	bool bpush = false;

	if (pJoyInput != NULL)
	{
		if (pJoyInput->GetJoyStickTrigger(CInputJoyStick::JOY_BUTTON_A))bpush = true;
	}

	//�X�e�B�b�N����
	if (bpush || pInputKey->GetKeyTrigger(DIK_RETURN))
	{
		//�X�e�[�W���[�h
		pBlackout->SetWhiteout(CGame::GetMapMode());

		//BGM�̍Đ�
		CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_DECISION);
	}
}

