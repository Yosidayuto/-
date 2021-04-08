//=============================================================================
//
// �r���u���b�N [building block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "building block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CBuildingBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBuildingBlock::CBuildingBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBuildingBlock::~CBuildingBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CBuildingBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Hindrance/TowerBlock/TowerBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CBuildingBlock::Unload(void)
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
CBuildingBlock * CBuildingBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CBuildingBlock* pBuildingBlock = NULL;
	pBuildingBlock = new CBuildingBlock;

	//NULL�`�F�b�N
	if (pBuildingBlock != NULL)
	{
		//�ʒu�ݒ�
		pBuildingBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + HINDRANCE_HEIGHT, pos.z));
		//�����ݒ�
		pBuildingBlock->SetRotation(rot);
		//�J���[�ݒ�
		pBuildingBlock->SetScale(size);
		//���f���ݒ�
		pBuildingBlock->SetModelData(m_modeldata);
		//����������
		pBuildingBlock->Init();
	}

	return pBuildingBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CBuildingBlock::Init(void)
{
	CHindranceBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CBuildingBlock::Uninit(void)
{
	CHindranceBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CBuildingBlock::Update(void)
{
	CHindranceBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CBuildingBlock::Draw(void)
{
	CHindranceBlockBase::Draw();

}
