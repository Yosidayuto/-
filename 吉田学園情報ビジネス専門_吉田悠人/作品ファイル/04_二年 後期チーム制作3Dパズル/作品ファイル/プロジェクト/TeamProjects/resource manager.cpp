//=============================================================================
//
// リソースマネージャー [reource manager.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
//インクルードファイル
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
// マクロ定義
//=============================================================================
#define TEXTURE_DATA ("Data/Text/TextureData.csv")

//=============================================================================
// コンストラクタ
//=============================================================================
CResource::CResource()
{
	m_nMaxTexture	= 0;
	m_npTexture		= NULL;
	m_pTexture		= NULL;
}
//=============================================================================
// デストラクタ
//=============================================================================
CResource::~CResource()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CResource::Init(void)
{
	//テクスチャロード
	TextureFail();

	CGrassBlock::Load();
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
	CPlayer::Load();

	//マップ読み込み
	CStage1::Load();
	CStage2::Load();
	CStage3::Load();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CResource::Uninit(void)
{
	//テクスチャアンロード
	TextureUnLoad();

	CPlayer::Unload();
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
	CSea::Unload();
	CGrassBlock::Unload();

}

//=============================================================================
// テクスチャロード
//=============================================================================
LPDIRECT3DTEXTURE9 CResource::TextureLoad(int nTexture)
{
	for (int nCountTexture = 0; nCountTexture < m_nMaxTexture; nCountTexture++)
	{
		//テクスチャ番号が一致したら
		if (m_npTexture[nCountTexture] == nTexture)
		{
			return m_pTexture[nCountTexture];
		}
	}
	return NULL;
}

//=============================================================================
// テクスチャアンロード
//=============================================================================
void CResource::TextureUnLoad(void)
{
	for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
	{
		//テクスチャの破棄
		if (m_pTexture[nTexture] != NULL)
		{
			m_pTexture[nTexture]->Release();
			m_pTexture[nTexture] = NULL;
		}
	}
}

//=============================================================================
// テクスチャデータ読み込み
//=============================================================================
void CResource::TextureFail(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//ファイルポインタ
	FILE*	pFile = NULL;
	//読み込み用データ
	char cFileString[258];
	char aData[256] = {};
	//行
	int nRow = 0;
	//初期化
	memset(cFileString, 0, sizeof(cFileString));

	//ファイル読み込み
	fopen_s(&pFile, TEXTURE_DATA, "r");

	if (pFile != NULL)
	{
		//総数読み込み
		fscanf_s(pFile, "MAX_DATA,%d", &m_nMaxTexture);
		
		//メモリ確保
		m_npTexture = new int [m_nMaxTexture];
		m_pTexture = new LPDIRECT3DTEXTURE9 [m_nMaxTexture];
		//初期化
		for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
		{
			m_npTexture[nTexture] = NULL;
			m_pTexture[nTexture] = NULL;
		}

		//行を読み飛ばし
		while (fgetc(pFile) != '\n');

		while (fscanf(pFile, "%d,%[^,],%s\n", &m_npTexture[nRow], m_pcTextureName, aData) != EOF)
		{
			// テクスチャの生成
			D3DXCreateTextureFromFile(pDevice,
				m_pcTextureName,
				&m_pTexture[nRow]);
			//行を進める
			nRow++;
		}
		fclose(pFile);				//ファイルを閉じる
	}

}




//=============================================================================
// Xファイル読み込みファイル
//=============================================================================
void CResource::XFail(void)
{
}

