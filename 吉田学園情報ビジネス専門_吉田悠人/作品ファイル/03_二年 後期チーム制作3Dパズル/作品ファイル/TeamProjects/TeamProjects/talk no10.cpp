//=============================================================================
//
//	セリフNo10 [talk No10.cpp]
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
#include "talk no10.h"

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CTalkNo10::CTalkNo10(int nPriorit)
{
}

//=============================================================================
// 生成処理
//=============================================================================
CTalkNo10 * CTalkNo10::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//メモリ確保
	CTalkNo10* pTalkNo10 = nullptr;
	pTalkNo10 = new CTalkNo10;
	//リソース確保
	CResource* pResource = CManager::GetResource();
	LPDIRECT3DTEXTURE9 Texture = pResource->TextureLoad(pTalkNo10->m_nTexture);

	//NULLチェック
	if (pTalkNo10 != nullptr)
	{
		//位置設定
		pTalkNo10->SetPos(pos);
		//サイズ設定
		pTalkNo10->SetSize(size);
		//テクスチャ設定
		pTalkNo10->BindTexture(Texture);
		//初期化処理
		pTalkNo10->Init();
	}
	return pTalkNo10;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTalkNo10::Init(void)
{
	//出現している時間セット
	SetAppear(0);
	//フェード状況設定
	SetFade(FADE_IN);

	//初期化処理
	CTalkbase::Init();
	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void CTalkNo10::Update(void)
{
	CTalkbase::Update();
}

//=============================================================================
// トーク処理
//=============================================================================
void CTalkNo10::Talk(void)
{
	//個数
	int nCountItem = 0;
	//オブジェクト取得用
	CObject* pTop[PRIORITY_MAX] = {};
	//次チェックするオブジェクトのポインタ
	CObject* pNext = NULL;
	//topのアドレスを取得
	for (int nCount = 0; nCount < PRIORITY_MAX; nCount++)
	{
		pTop[nCount] = *(CObject::GetTop() + nCount);
	}


	//オブジェクト探査
	for (int nCount = 0; nCount < PRIORITY_MAX; nCount++)
	{
		if (pTop[nCount] != NULL)
		{
			pNext = pTop[nCount];
			//その描画優先度のオブジェクトがなくなるまでループ
			while (pNext != NULL)
			{
				//オブジェクトのタイプがアイテムなら
				if (pNext->GetObjType() == OBJTYPE_ITEM)
				{
					nCountItem++;
				}

				//次のオブジェクトのポインタを更新
				pNext = pNext->GetNext();
			}
		}
	}

	//アイテムが一つの時
	if (nCountItem == 1)
	{
		//透過状況を設定
		m_Fade = FADE_OUT;
	}

}
