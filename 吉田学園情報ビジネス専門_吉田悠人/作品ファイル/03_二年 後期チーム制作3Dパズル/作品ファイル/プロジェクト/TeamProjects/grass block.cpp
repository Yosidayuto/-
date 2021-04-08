//=============================================================================
//
// ���u���b�N���� [grass block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "grass block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CGrassBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGrassBlock::CGrassBlock()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGrassBlock::~CGrassBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CGrassBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Stage/GrassBlock/GrassBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CGrassBlock::Unload(void)
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
CGrassBlock * CGrassBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//�������m��
	CGrassBlock* pTileBlock = NULL;
	pTileBlock = new CGrassBlock;

	//NULL�`�F�b�N
	if (pTileBlock != NULL)
	{
		//�ʒu�ݒ�
		pTileBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y - BLOCK_HEIGHT, pos.z));
		//�����ݒ�
		pTileBlock->SetRotation(rot);
		//�J���[�ݒ�
		pTileBlock->SetScale(size);
		//���f���ݒ�
		pTileBlock->SetModelData(m_modeldata);
		//����������
		pTileBlock->Init();
	}

	return pTileBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CGrassBlock::Init(void)
{
	CTileBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CGrassBlock::Uninit(void)
{
	CTileBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CGrassBlock::Update(void)
{
	CTileBlockBase::Update();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CGrassBlock::Draw(void)
{
	CTileBlockBase::Draw();

}

