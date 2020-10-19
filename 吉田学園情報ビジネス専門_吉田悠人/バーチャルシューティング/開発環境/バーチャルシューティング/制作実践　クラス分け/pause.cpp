#include "pause.h"
#include "sound.h"
#include "manager.h"
#include "renderer.h"
#include "inputmouse.h"
#include "inihkeyboard.h"
//----------------------------------
//静的メンバー変数
//----------------------------------
LPDIRECT3DTEXTURE9 CPause::m_pTexture;
bool CPause::m_bPause=false;
//----------------------------------
//コンストラクタ
//----------------------------------
CPause::CPause()
{
	m_pVtxBuff = NULL;
}

//----------------------------------
//デストラクタ
//----------------------------------
CPause::~CPause()
{
}

//----------------------------------
//テクスチャ読み込み処理
//----------------------------------
HRESULT CPause::Load(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "TEXTURE/CLICK画面.png", &m_pTexture);
	return S_OK;
}

//----------------------------------
//テクスチャ破棄処理
//----------------------------------
void CPause::Unload(void)
{
		//テクスチャの破棄
		if (m_pTexture != NULL)
		{
			m_pTexture->Release();
			m_pTexture = NULL;
		}

}

//----------------------------------
//生成処理
//----------------------------------
CPause * CPause::Create(void)
{
	CPause *pPause;
	pPause = new CPause;
	pPause->Init();
	m_bPause = true;
	return pPause;
}

//----------------------------------
//初期化処理
//----------------------------------
HRESULT CPause::Init(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "TEXTURE/CLICK画面.png", &m_pTexture);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,//バッファサイズ
		D3DUSAGE_WRITEONLY,//(固定)
		FVF_VERTEX_2D,//頂点フォーマット
		D3DPOOL_MANAGED,//（固定）
		&m_pVtxBuff,//変数名が変わると変更が必要
		NULL);
	VERTEX_2D *pVtx;//頂点情報へのポインター

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点バッファの生成
	pVtx[0].pos = D3DXVECTOR3(0, 0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	// テクスチャの生成
	pVtx[0].tex = D3DXVECTOR2(0, 0);
	pVtx[1].tex = D3DXVECTOR2(1, 0);
	pVtx[2].tex = D3DXVECTOR2(0, 1);
	pVtx[3].tex = D3DXVECTOR2(1, 1);


	// 頂点情報を設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//rhwの設定（値は１，０で固定）
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点データをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//----------------------------------
//終了処理
//----------------------------------
void CPause::Uninit(void)
{
	// 頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}
//----------------------------------
//更新処理
//----------------------------------
void CPause::Update(void)
{
	CInihMouse *pMouse= CManager::GetMouse();
	CInihKeyboard *pKey = CManager::GetKeyboard();
	if (m_bPause == false)
	{
		if (pKey->GetKeyPressTrigger(DIK_SPACE))
		{
			m_bPause = true;
		}
	}
	if (m_bPause == true)
	{
		if (pMouse->GetClickTrigger(0))
		{
			m_bPause = false;
		}
	}
}

//----------------------------------
//描画処理
//----------------------------------
void CPause::Draw(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	if (m_bPause= true)
	{
		// 頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

		// 頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_2D);
		// テクスチャの設定
		pDevice->SetTexture(0, m_pTexture);

		// ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	}

}
