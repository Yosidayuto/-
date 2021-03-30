//=============================================================================
//
// ���\�[�X�}�l�[�W���[ [reource manager.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "renderer.h"
#include "resource manager.h"
#include <stdio.h>

#include "player.h"
#include "button.h"
#include "grass block.h"
#include "end button.h"
#include "restart button.h"
#include "start button.h"
#include "child.h"
#include "stagenumber.h"
#include "talk_base.h"
#include "red sand block.h"
#include "hole block.h"
#include "garbage block.h"
#include "building block.h"
#include "building break block.h"
#include "sand block.h"
#include "sprout block.h"
#include "seeds block.h"
#include "tutorial.h"
#include "press button ui.h"
#include "grass block.h"
#include "small tree.h"
#include "big tree.h"
#include "apple block.h"
#include "oranges block.h"
#include "grapes block.h"
#include "watermelon block.h"
#include "luggage block.h"
#include "sand block.h"
#include "watermelon block.h"
#include "title logo.h"
#include "particle.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

#include "sea.h"
//=============================================================================
// �}�N����`
//=============================================================================
#define TEXTURE_DATA ("Data/Text/TextureData.csv")

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CResource::CResource()
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CResource::~CResource()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CResource::Init(void)
{
	CGrassBlock::Load();
	CPlayer::Load();
	CEndButton::Load();
	CRestartButton::Load();
	CStartButton::Load();
	CTalkbase::Load();
	CTutorial::Load();
	CPressUi::Load();
	CTitleLoge::Load();
	CParticle::Load();


	CRedSandBlock::Load();
	CBuildingBlock::Load();
	CBuildingBreakBlock::Load();
	CGarbageBlock::Load();
	CSandBlock::Load();
	CSproutBlock::Load();
	CSeedsBlock::Load();
	CHoleBlock::Load();
	CAppleBlock::Load();
	COrangesBlock::Load();
	CGrapesBlock::Load();
	CWatermelonBlock::Load();
	CBigTree::Load();
	CSmallTree::Load();
	CStageNumber::Load();
	CLuggageBlock::Load();
	CSea::Load();

	//�}�b�v�ǂݍ���
	CStage1::Load();
	CStage2::Load();
	CStage3::Load();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CResource::Uninit(void)
{
	CGrassBlock::Unload();
	CPlayer::Unload();
	CRestartButton::Unload();
	CStartButton::Unload();
	CRedSandBlock::Unload();
	CBuildingBlock::Unload();
	CBuildingBreakBlock::Unload();
	CGarbageBlock::Unload();
	CSandBlock::Unload();
	CSproutBlock::Unload();
	CSeedsBlock::Unload();
	CLuggageBlock::Unload();
	CAppleBlock::Unload();
	COrangesBlock::Unload();
	CGrapesBlock::Unload();
	CWatermelonBlock::Unload();
	CBigTree::Unload();
	CSmallTree::Unload();
	CHoleBlock::Unload();
	CStageNumber::Unload();
	CTalkbase::Unload();
	CTutorial::Unload();
	CPressUi::Unload();
	CSea::Unload();
	CTitleLoge::Unload();
	CParticle::Unload();

}

////=============================================================================
//// �e�N�X�`�����[�h
////=============================================================================
//void CResource::TextureLoad(void)
//{
//	for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
//	{
//		//�f�o�C�X�擾
//		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//		//�e�N�X�`���̓ǂݍ���
//		D3DXCreateTextureFromFile(pDevice,
//			m_pcTextureName[m_npTexture[nTexture]],
//			&m_pTexture[m_npTexture[nTexture]]);
//	}
//}
//
////=============================================================================
//// �e�N�X�`���f�[�^�ǂݍ���
////=============================================================================
//void CResource::TextureFail(void)
//{
//	//�t�@�C���|�C���^
//	FILE*	pFile;
//	//�ǂݍ��ݗp�f�[�^
//	char cFileString[258];
//	//�����F��
//	int nFileText;
//	//��A�s
//	int nCol, nRow;
//	//������
//	memset(cFileString, 0, sizeof(cFileString));
//	nCol = 1;
//	nRow = 0;
//
//	//�t�@�C���ǂݍ���
//	fopen_s(&pFile, TEXTURE_DATA, "r");
//
//	if (pFile != NULL)
//	{
//		//�����ǂݍ���
//		//while ()
//		//{
//
//		//}
//		//�w�b�_�[�ǂݔ�΂�
//		while (fgetc(pFile) != '\n');
//
//		while (1)
//		{
//			while (1)
//			{
//				nFileText = fgetc(pFile);
//				//�����Ȃ烋�[�v�𔲂���B
//				if (nFileText == EOF)
//				{
//					goto out;
//				}
//				//�J���}�����s�łȂ���΁A�����Ƃ��ĂȂ���
//				if (nFileText != ',' && nFileText != '\n')
//				{
//					strcat_s(cFileString, (const char*)&nFileText);
//				}
//				//�J���}�����s�Ȃ烋�[�v������B
//				else
//				{
//					break;
//				}
//			}
//
//			//�ǂݍ���
//			if (nCol == 1)
//			{
//				//�e�N�X�`���ԍ��ǂݍ���
//				m_npTexture = new int;
//				m_npTexture[nRow] = atoi(cFileString);
//			}
//			if (nCol == 2)
//			{
//				//�e�N�X�`���p�X�ǂݍ���
//				m_pcTextureName = new char*();
//				m_pcTextureName[m_npTexture[nRow]] = cFileString;
//			}
//
//			//�o�b�t�@�̏�����
//			memset(cFileString, 0, sizeof(cFileString));
//
//			//�񐔂𑫂�
//			nCol++;
//
//			//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
//			if (nFileText == '\n')
//			{
//				//�s��������
//				nCol = 1;
//				//��̐i�s
//				nRow++;
//
//			}
//
//		}
//	out:							//�����Ȃ炱���ɒ���
//		m_nMaxTexture = nRow;		//�ő吔�擾
//		fclose(pFile);				//�t�@�C�������
//	}
//
//}
//
//
////=============================================================================
//// X�t�@�C���ǂݍ��݃t�@�C��
////=============================================================================
//void CResource::XFail(void)
//{
//}
//
