//=============================================================================
//
//	�I���{�^��[end button.cpp]
//	Author:�g�c�@�I�l
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "end button.h"
#include "renderer.h"
#include "manager.h"
#include "fade.h"
#include "inputcontroller.h"
#include "inputkeyboard.h"
#include "sound.h"

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
TEXTURE_DATA CEndButton::m_TextureData = { NULL,	"Data/Texture/button/titlehe.png", };

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CEndButton::CEndButton()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CEndButton::~CEndButton()
{
}

//=============================================================================
// �e�N�X�`���ǂݍ���
//=============================================================================
HRESULT CEndButton::Load(void)
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
void CEndButton::Unload(void)
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
CEndButton * CEndButton::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//�������m��
	CEndButton *pEndButton = NULL;
	pEndButton = new CEndButton;

	//NULL�`�F�b�N
	if (pEndButton != NULL)
	{
		//�ʒu�ݒ�
		pEndButton->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
		//�T�C�Y�ݒ�
		pEndButton->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
		//�e�N�X�`���ݒ�
		pEndButton->BindTexture(m_TextureData.m_pTexture);
		//����������
		pEndButton->Init();
	}
	return pEndButton;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CEndButton::Init(void)
{
	CButton::Init();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CEndButton::Uninit(void)
{
	CButton::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CEndButton::Update(void)
{
	CButton::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CEndButton::Draw(void)
{
	CButton::Draw();
}


//=============================================================================
// �v�b�V�����菈��
//=============================================================================
void CEndButton::Push()
{
	//�t�F�C�h�擾
	CFade*			pFade = CManager::GetFadeout();
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
		pFade->SetBlackout(CManager::MODE_TITLE);

		//BGM�̍Đ�
		CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_DECISION);
	}
}
