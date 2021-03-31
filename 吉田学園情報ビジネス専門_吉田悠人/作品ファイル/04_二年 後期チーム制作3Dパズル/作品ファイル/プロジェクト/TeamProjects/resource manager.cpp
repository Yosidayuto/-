//=============================================================================
//
// ���\�[�X�}�l�[�W���[ [reource manager.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "renderer.h"
#include "resource manager.h"
#include <stdio.h>

#include "player.h"
#include "button.h"
#include "grass block.h"
#include "end button.h"
#include "restart button.h"
#include "start button.h"
#include "child.h"
#include "stagenumber.h"
#include "talk_base.h"
#include "red sand block.h"
#include "hole block.h"
#include "garbage block.h"
#include "building block.h"
#include "building break block.h"
#include "sand block.h"
#include "sprout block.h"
#include "seeds block.h"
#include "tutorial.h"
#include "press button ui.h"
#include "grass block.h"
#include "small tree.h"
#include "big tree.h"
#include "apple block.h"
#include "oranges block.h"
#include "grapes block.h"
#include "watermelon block.h"
#include "luggage block.h"
#include "sand block.h"
#include "watermelon block.h"
#include "title logo.h"
#include "particle.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

#include "sea.h"
//=============================================================================
// �}�N����`
//=============================================================================
#define TEXTURE_DATA ("Data/Text/TextureData.csv")

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CResource::CResource()
{
	m_nMaxTexture	= 0;
	m_npTexture		= NULL;
	m_pTexture		= NULL;
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CResource::~CResource()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CResource::Init(void)
{
	//�e�N�X�`�����[�h
	TextureFail();

	CGrassBlock::Load();
	CRedSandBlock::Load();
	CBuildingBlock::Load();
	CBuildingBreakBlock::Load();
	CGarbageBlock::Load();
	CSandBlock::Load();
	CSproutBlock::Load();
	CSeedsBlock::Load();
	CHoleBlock::Load();
	CAppleBlock::Load();
	COrangesBlock::Load();
	CGrapesBlock::Load();
	CWatermelonBlock::Load();
	CBigTree::Load();
	CSmallTree::Load();
	CStageNumber::Load();
	CLuggageBlock::Load();
	CSea::Load();
	CPlayer::Load();

	//�}�b�v�ǂݍ���
	CStage1::Load();
	CStage2::Load();
	CStage3::Load();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CResource::Uninit(void)
{
	//�e�N�X�`���A�����[�h
	TextureUnLoad();

	CPlayer::Unload();
	CRedSandBlock::Unload();
	CBuildingBlock::Unload();
	CBuildingBreakBlock::Unload();
	CGarbageBlock::Unload();
	CSandBlock::Unload();
	CSproutBlock::Unload();
	CSeedsBlock::Unload();
	CLuggageBlock::Unload();
	CAppleBlock::Unload();
	COrangesBlock::Unload();
	CGrapesBlock::Unload();
	CWatermelonBlock::Unload();
	CBigTree::Unload();
	CSmallTree::Unload();
	CHoleBlock::Unload();
	CStageNumber::Unload();
	CSea::Unload();
	CGrassBlock::Unload();

}

//=============================================================================
// �e�N�X�`�����[�h
//=============================================================================
LPDIRECT3DTEXTURE9 CResource::TextureLoad(int nTexture)
{
	for (int nCountTexture = 0; nCountTexture < m_nMaxTexture; nCountTexture++)
	{
		//�e�N�X�`���ԍ�����v������
		if (m_npTexture[nCountTexture] == nTexture)
		{
			return m_pTexture[nCountTexture];
		}
	}
	return NULL;
}

//=============================================================================
// �e�N�X�`���A�����[�h
//=============================================================================
void CResource::TextureUnLoad(void)
{
	for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nTexture] != NULL)
		{
			m_pTexture[nTexture]->Release();
			m_pTexture[nTexture] = NULL;
		}
	}
}

//=============================================================================
// �e�N�X�`���f�[�^�ǂݍ���
//=============================================================================
void CResource::TextureFail(void)
{
	//�f�o�C�X�擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�t�@�C���|�C���^
	FILE*	pFile = NULL;
	//�ǂݍ��ݗp�f�[�^
	char cFileString[258];
	char aData[256] = {};
	//�s
	int nRow = 0;
	//������
	memset(cFileString, 0, sizeof(cFileString));

	//�t�@�C���ǂݍ���
	fopen_s(&pFile, TEXTURE_DATA, "r");

	if (pFile != NULL)
	{
		//�����ǂݍ���
		fscanf_s(pFile, "MAX_DATA,%d", &m_nMaxTexture);
		
		//�������m��
		m_npTexture = new int [m_nMaxTexture];
		m_pTexture = new LPDIRECT3DTEXTURE9 [m_nMaxTexture];
		//������
		for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
		{
			m_npTexture[nTexture] = NULL;
			m_pTexture[nTexture] = NULL;
		}

		//�s��ǂݔ�΂�
		while (fgetc(pFile) != '\n');

		while (fscanf(pFile, "%d,%[^,],%s\n", &m_npTexture[nRow], m_pcTextureName, aData) != EOF)
		{
			// �e�N�X�`���̐���
			D3DXCreateTextureFromFile(pDevice,
				m_pcTextureName,
				&m_pTexture[nRow]);
			//�s��i�߂�
			nRow++;
		}
		fclose(pFile);				//�t�@�C�������
	}

}




//=============================================================================
// X�t�@�C���ǂݍ��݃t�@�C��
//=============================================================================
void CResource::XFail(void)
{
}

