//=============================================================================
//
//	セリフNo1 [talk no1.cpp]
//	Author:筒井 俊稀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "talk_base.h"
#include "resource manager.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "renderer.h"
#include "manager.h"
#include "sound.h"
#include "talk no9.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define TALK_APPEAR (240)	//出現している時間

//=============================================================================
// コンストラクタ
//=============================================================================
CTalkNo9::CTalkNo9(int nPriorit)
{

}

//=============================================================================
// 生成処理
//=============================================================================
CTalkNo9 * CTalkNo9::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//メモリ確保
	CTalkNo9* pTalkNo9 = nullptr;
	pTalkNo9 = new CTalkNo9;
	//リソース確保
	CResource* pResource = CManager::GetResource();
	LPDIRECT3DTEXTURE9 Texture = pResource->TextureLoad(pTalkNo9->m_nTexture);

	if (pTalkNo9 != nullptr)
	{
		//位置設定
		pTalkNo9->SetPos(pos);
		//サイズ設定
		pTalkNo9->SetSize(size);
		//テクスチャ設定
		pTalkNo9->BindTexture(Texture);

		//初期化処理
		pTalkNo9->Init();
	}
	return pTalkNo9;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTalkNo9::Init(void)
{
	//出現している時間セット
	SetAppear(TALK_APPEAR);
	//フェード状況設定
	SetFade(FADE_IN);

	//初期化処理
	CTalkbase::Init();
	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void CTalkNo9::Update(void)
{
	CTalkbase::Update();
}
