//=============================================================================
//
// �j�t��(������) [small tree.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "small tree.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CSmallTree::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSmallTree::CSmallTree()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSmallTree::~CSmallTree()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CSmallTree::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Hindrance/WoodSmallBlock/WoodSmall.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSmallTree::Unload(void)
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
CSmallTree * CSmallTree::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CSmallTree* pSmallTree = NULL;
	pSmallTree = new CSmallTree;

	//NULL�`�F�b�N
	if (pSmallTree != NULL)
	{
		//�ʒu�ݒ�
		pSmallTree->SetPosition(D3DXVECTOR3(pos.x, pos.y + HINDRANCE_HEIGHT, pos.z));
		//�����ݒ�
		pSmallTree->SetRotation(rot);
		//�J���[�ݒ�
		pSmallTree->SetScale(size);
		//���f���ݒ�
		pSmallTree->SetModelData(m_modeldata);
		//����������
		pSmallTree->Init();
	}

	return pSmallTree;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CSmallTree::Init(void)
{
	CHindranceBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CSmallTree::Uninit(void)
{
	CHindranceBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CSmallTree::Update(void)
{
	CHindranceBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CSmallTree::Draw(void)
{
	CHindranceBlockBase::Draw();

}
