//=============================================================================
//
// ��u���b�N [sprout block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "sprout block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CSproutBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSproutBlock::CSproutBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSproutBlock::~CSproutBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CSproutBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Stage/BudsBlock/BudsBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

	if (m_modeldata.pBuffMat != NULL)
	{
		pMat = (D3DXMATERIAL *)m_modeldata.pBuffMat->GetBufferPointer();

		for (int nCountMat = 0; nCountMat < (int)m_modeldata.nNumMat; nCountMat++)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCountMat].pTextureFilename, &m_modeldata.pTexture[nCountMat]);
		}

	}
	return S_OK;
}

//=============================================================================
// ���f���j���֐�
//=============================================================================
void CSproutBlock::Unload(void)
{
	if (m_modeldata.pBuffMat != NULL)
	{
		m_modeldata.pBuffMat->Release();
	}

	if (m_modeldata.pMesh != NULL)
	{
		m_modeldata.pMesh->Release();
	}

	for (int nCountTex = 0; nCountTex < MAX_MATERIAL; nCountTex++)
	{
		if (m_modeldata.pTexture[nCountTex] != NULL)
		{
			m_modeldata.pTexture[nCountTex]->Release();
		}
	}
}

//=============================================================================
// �����֐�
//=============================================================================
CSproutBlock * CSproutBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CSproutBlock* pSproutBlock = NULL;
	pSproutBlock = new CSproutBlock;

	//NULL�`�F�b�N
	if (pSproutBlock != NULL)
	{
		//�ʒu�ݒ�
		pSproutBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y - BLOCK_HEIGHT, pos.z));
		//�����ݒ�
		pSproutBlock->SetRotation(rot);
		//�J���[�ݒ�
		pSproutBlock->SetScale(size);
		//���f���ݒ�
		pSproutBlock->SetModelData(m_modeldata);
		//����������
		pSproutBlock->Init();
	}

	return pSproutBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CSproutBlock::Init(void)
{
	CTileBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CSproutBlock::Uninit(void)
{
	CTileBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CSproutBlock::Update(void)
{
	CTileBlockBase::Update();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CSproutBlock::Draw(void)
{
	CTileBlockBase::Draw();

}

