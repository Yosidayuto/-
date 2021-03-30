//=============================================================================
//
// ��u���b�N [seeds block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "seeds block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CSeedsBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSeedsBlock::CSeedsBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSeedsBlock::~CSeedsBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CSeedsBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/SeedBlock/SeedBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSeedsBlock::Unload(void)
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
CSeedsBlock * CSeedsBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CSeedsBlock* pSeedsBlock = NULL;
	pSeedsBlock = new CSeedsBlock;

	//NULL�`�F�b�N
	if (pSeedsBlock != NULL)
	{
		//�ʒu�ݒ�
		pSeedsBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT, pos.z));
		//�����ݒ�
		pSeedsBlock->SetRotation(rot);
		//�J���[�ݒ�
		pSeedsBlock->SetScale(size);
		//���f���ݒ�
		pSeedsBlock->SetModelData(m_modeldata);
		//����������
		pSeedsBlock->Init();
	}

	return pSeedsBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CSeedsBlock::Init(void)
{
	CItemBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CSeedsBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CSeedsBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CSeedsBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
