//=============================================================================
//
// ショット処理 [shots.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "shots base.h"
#include "scene.h"
#include "scene2d.h"
#include "shots.h"
#include "enemy bullet.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define SHOTS_SPEED			(7.0f)		//弾速

//=============================================================================
// コンストラクト
//=============================================================================
CShots::CShots()
{
	m_nBullet = 0;
	memset(m_bBullet, false, sizeof(m_bBullet));
}

//=============================================================================
// デストラクト
//=============================================================================
CShots::~CShots()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CShots * CShots::Create(CScene2d* Scene2d)
{
	//メモリの確保
	CShots* pShots = NULL;
	pShots = new CShots;

	//NULLチェック
	if (pShots != NULL)
	{
		//ポインタ設定
		pShots->m_pScene2d = Scene2d;
		//位置設定
		pShots->SetPos(Scene2d->GetPos());
		//向き設定
		pShots->Tracking(SHOTS_SPEED);
		//初期化処理
		pShots->Init();

	}
	return pShots;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CShots::Init(void)
{
	CShotsBase::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CShots::Uninit(void)
{
	CShotsBase::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CShots::Update(void)
{
	CShotsBase::Update();
}

//=============================================================================
// ショット処理
//=============================================================================
void CShots::Shots(void)
{
	//位置取得
	D3DXVECTOR3 pos = m_pScene2d->GetPos();
	//向き取得
	D3DXVECTOR3 rot = GetRot();

	//カウントプラス
	m_nBullet++;

	//ショット処理
	for (int nBullet = 0; nBullet < MAX_SHOTS; nBullet++)
	{
		//弾丸を撃ちだすまでのカウント＆弾を撃ちだしたか
		if (m_nBullet >= 20 * (nBullet + 1)
			&& m_bBullet[nBullet] == false)
		{
			//バレット生成
			CEnemyBullet::Create(pos, rot);
			//バレット使用状態に
			m_bBullet[nBullet] = true;
		}
	}

	//終了
	if (m_bBullet[MAX_SHOTS - 1] == true)
	{
		SetShotsEnd(true);
		return;
	}
}

