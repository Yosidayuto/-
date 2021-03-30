//=============================================================================
//
// �~�J���u���b�N [oranges block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "oranges block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA COrangesBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
COrangesBlock::COrangesBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
COrangesBlock::~COrangesBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT COrangesBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/OrangeBlock/OrangeBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void COrangesBlock::Unload(void)
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
COrangesBlock * COrangesBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	COrangesBlock* pOrangesBlock = NULL;
	pOrangesBlock = new COrangesBlock;

	//NULL�`�F�b�N
	if (pOrangesBlock != NULL)
	{
		//�ʒu�ݒ�
		pOrangesBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT, pos.z));
		//�����ݒ�
		pOrangesBlock->SetRotation(rot);
		//�J���[�ݒ�
		pOrangesBlock->SetScale(size);
		//���f���ݒ�
		pOrangesBlock->SetModelData(m_modeldata);
		//����������
		pOrangesBlock->Init();
	}

	return pOrangesBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT COrangesBlock::Init(void)
{
	CItemBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void COrangesBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void COrangesBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void COrangesBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
