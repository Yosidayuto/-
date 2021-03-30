//=============================================================================
//
// �r���i����j�u���b�N [building break block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "building break block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CBuildingBreakBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBuildingBreakBlock::CBuildingBreakBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBuildingBreakBlock::~CBuildingBreakBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CBuildingBreakBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Hindrance/TowerBreakBlock/TowerBreakBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CBuildingBreakBlock::Unload(void)
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
CBuildingBreakBlock * CBuildingBreakBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CBuildingBreakBlock* pBuildingBreakBlock = NULL;
	pBuildingBreakBlock = new CBuildingBreakBlock;

	//NULL�`�F�b�N
	if (pBuildingBreakBlock != NULL)
	{
		//�ʒu�ݒ�
		pBuildingBreakBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + HINDRANCE_HEIGHT, pos.z));
		//�����ݒ�
		pBuildingBreakBlock->SetRotation(rot);
		//�J���[�ݒ�
		pBuildingBreakBlock->SetScale(size);
		//���f���ݒ�
		pBuildingBreakBlock->SetModelData(m_modeldata);
		//����������
		pBuildingBreakBlock->Init();
	}

	return pBuildingBreakBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CBuildingBreakBlock::Init(void)
{
	CHindranceBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CBuildingBreakBlock::Uninit(void)
{
	CHindranceBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CBuildingBreakBlock::Update(void)
{
	CHindranceBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CBuildingBreakBlock::Draw(void)
{
	CHindranceBlockBase::Draw();

}
