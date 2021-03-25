//=============================================================================
//
// タイトルロゴ処理 [titlelogo.cpp]
// Author : 二階堂汰一
//
//=============================================================================

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "titlelogo.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// 静的メンバ変数の初期化
//*****************************************************************************
LPDIRECT3DTEXTURE9 CTitleLogo::m_pTexture = NULL;

//=============================================================================
// コンストラクタ
//=============================================================================
CTitleLogo::CTitleLogo() : CObject2D(2)
{
	D3DXVECTOR3	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DCOLOR	m_col = D3DCOLOR_RGBA(255, 255, 255, 255);
	for (int nCount = 0; nCount < NUM_VERTEX; nCount++)
	{
		m_texpos[nCount] = D3DXVECTOR2(0.0f, 0.0f);
	}
}

//=============================================================================
// デストラクタ
//=============================================================================
CTitleLogo::~CTitleLogo()
{
}

//=============================================================================
// テクスチャ読み込み関数
//=============================================================================
HRESULT CTitleLogo::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// テクスチャの生成
	D3DXCreateTextureFromFile(pDevice,				// デバイスへのポインタ
		"Data/Texture/titlelogo.png",								// ファイルの名前
		&m_pTexture);								// 読み込むメモリー
	return S_OK;
}

//=============================================================================
// テクスチャ破棄関数
//=============================================================================
void CTitleLogo::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//=============================================================================
// 生成関数
//=============================================================================
CTitleLogo * CTitleLogo::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CTitleLogo* pTitleLogo = NULL;
	pTitleLogo = new CTitleLogo;
	pTitleLogo->m_pos = pos;
	pTitleLogo->m_size = size;
	pTitleLogo->Init();

	return pTitleLogo;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CTitleLogo::Init(void)
{
	SetPos(m_pos);
	SetSize(m_size);
	SetCol(m_col);
	BindTexture(m_pTexture);	//テクスチャの割り当て
	CObject2D::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CTitleLogo::Uninit(void)
{
	CObject2D::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CTitleLogo::Update(void)
{
	////カウントインクリメント
	//m_nCounterAnim++;
	////カウントが4以上になった場合
	//if (m_nCounterAnim > 4)
	//{
	//	//カウントを0にする
	//	m_nCounterAnim = 0;

	//	//パターンのインクリメント
	//	m_nPatternAnim++;
	//	//パターンが8になった場合
	//	if (m_nPatternAnim > 8)
	//	{
	//		//終了
	//		Uninit();
	//		return;
	//	}
	//}

	//m_texpos[0] = D3DXVECTOR2(m_nPatternAnim * 0.125f, 0.0f);
	//m_texpos[1] = D3DXVECTOR2(m_nPatternAnim * 0.125f + 0.125f, 0.0f);
	//m_texpos[2] = D3DXVECTOR2(m_nPatternAnim * 0.125f, 1.0f);
	//m_texpos[3] = D3DXVECTOR2(m_nPatternAnim * 0.125f + 0.125f, 1.0f);

	//SetTexPos(m_texpos);
}

//=============================================================================
// 描画関数
//=============================================================================
void CTitleLogo::Draw(void)
{
	CObject2D::Draw();
}

