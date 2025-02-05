//=============================================================================
//
// ポーズ [pause.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
//インクルードファイル
//=============================================================================
#include "pause.h"
#include "object2d.h"
#include "pause button manager.h"
#include "sound.h"
#include "manager.h"
#include "pause bg.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CPause::CPause()
{
	pButtonManager	= NULL;
	m_pPauseBg		= NULL;
	bPause			= false;
}

//=============================================================================
// デストラクタ
//=============================================================================
CPause::~CPause()
{
}


//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPause::Init(void)
{
	//ポーズ状態に
	bPause = true;

	//背景生成
	m_pPauseBg = CPauseBg::Create(D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0)/2, D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0));

	//ボタン生成
	pButtonManager = CPauseButtonManager::Create();

	//BGMの再生
	CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_SHOW_POSE);
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPause::Uninit(void)
{
}

//=============================================================================
// 描画関数
//=============================================================================
void CPause::Draw(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
void CPause::Update(void)
{
	//ポーズ状態か
	if (bPause == true)
	{
		//ボタンマネージャーの更新
		if (pButtonManager != NULL)
		{
			pButtonManager->Update();
		}
		//背景用オブジェクトの更新
		if (m_pPauseBg != NULL)
		{
			m_pPauseBg->Update();
		}
	}
}

//=============================================================================
// ポーズ終了関数
//=============================================================================
void CPause::Delete(void)
{
	//背景用オブジェクト破棄
	if (m_pPauseBg != NULL)
	{
		m_pPauseBg->Uninit();
		m_pPauseBg = NULL;
	}

	//ボタンマネージャー破棄
	if (pButtonManager != NULL)
	{
		pButtonManager->Uninit();
		pButtonManager = NULL;
	}

	//ポーズ状態の解除
	bPause = false;

	//BGMの終了
	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_SHOW_POSE);
}

//=============================================================================
// ポーズ状況ゲッター
//=============================================================================
bool CPause::GetPause(void)
{
	return bPause;
}

