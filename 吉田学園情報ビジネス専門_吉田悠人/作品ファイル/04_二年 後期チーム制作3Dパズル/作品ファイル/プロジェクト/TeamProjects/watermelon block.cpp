//=============================================================================
//
// �X�C�J�u���b�N [watermelon block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "watermelon block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CWatermelonBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CWatermelonBlock::CWatermelonBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CWatermelonBlock::~CWatermelonBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CWatermelonBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/WaterMelonBlock/WaterMelonBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CWatermelonBlock::Unload(void)
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
CWatermelonBlock * CWatermelonBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CWatermelonBlock* pWatermelonBlock = NULL;
	pWatermelonBlock = new CWatermelonBlock;

	//NULL�`�F�b�N
	if (pWatermelonBlock != NULL)
	{
		//�ʒu�ݒ�
		pWatermelonBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT+20, pos.z));
		//�����ݒ�
		pWatermelonBlock->SetRotation(rot);
		//�J���[�ݒ�
		pWatermelonBlock->SetScale(size);
		//���f���ݒ�
		pWatermelonBlock->SetModelData(m_modeldata);
		//����������
		pWatermelonBlock->Init();
	}

	return pWatermelonBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CWatermelonBlock::Init(void)
{
	CItemBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CWatermelonBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CWatermelonBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CWatermelonBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
