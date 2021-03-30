//=============================================================================
//
// �ו��u���b�N [luggage block.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "luggage block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// �}�N����`
//=============================================================================
#define LUGGAGE_HEIGHT (-25.0f)	//��������

//=============================================================================
// �ÓI�����o�ϐ�������
//=============================================================================
CModel::MODELDATA CLuggageBlock::m_modeldata = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CLuggageBlock::CLuggageBlock()
{
	bGoal = false;
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CLuggageBlock::~CLuggageBlock()
{
}

//=============================================================================
// ���f���ǂݍ��݊֐�
//=============================================================================
HRESULT CLuggageBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Goal/BoxBlock/BoxBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CLuggageBlock::Unload(void)
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
CLuggageBlock * CLuggageBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, CGame::MAP_TYPE MapType, bool Goal)
{
	//�������m��
	CLuggageBlock* pLuggageBlock = NULL;
	pLuggageBlock = new CLuggageBlock;

	//NULL�`�F�b�N
	if (pLuggageBlock != NULL)
	{
		//�ʒu�ݒ�
		pLuggageBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + LUGGAGE_HEIGHT, pos.z));
		//�����ݒ�
		pLuggageBlock->SetRotation(rot);
		//�J���[�ݒ�
		pLuggageBlock->SetScale(size);
		//�}�b�v�ݒ�
		pLuggageBlock->SetMapType(MapType);
		//���f���ݒ�
		pLuggageBlock->SetModelData(m_modeldata);
		//�S�[���@�\�ݒ�
		pLuggageBlock->SetGoal(Goal);
		//����������
		pLuggageBlock->Init();
	}

	return pLuggageBlock;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CLuggageBlock::Init(void)
{
	CGoalBlockBase::Init();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CLuggageBlock::Uninit(void)
{
	CGoalBlockBase::Uninit();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CLuggageBlock::Update(void)
{
	CGoalBlockBase::Update();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CLuggageBlock::Draw(void)
{
	CGoalBlockBase::Draw();

}
