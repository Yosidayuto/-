//=============================================================================
//
// �S�~�u���b�N [garbage block.h]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "garbage block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CGarbageBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGarbageBlock::CGarbageBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGarbageBlock::~CGarbageBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CGarbageBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/GarbageBlock/GarbageBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CGarbageBlock::Unload(void)
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
CGarbageBlock * CGarbageBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CGarbageBlock* pGarbageBlock = NULL;
	pGarbageBlock = new CGarbageBlock;

	//NULL�`�F�b�N
	if (pGarbageBlock != NULL)
	{
		//�ʒu�ݒ�
		pGarbageBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT, pos.z));
		//�����ݒ�
		pGarbageBlock->SetRotation(rot);
		//�J���[�ݒ�
		pGarbageBlock->SetScale(size);
		//���f���ݒ�
		pGarbageBlock->SetModelData(m_modeldata);
		//����������
		pGarbageBlock->Init();
	}

	return pGarbageBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CGarbageBlock::Init(void)
{
	CItemBlockBase::Init();

	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CGarbageBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CGarbageBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CGarbageBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
