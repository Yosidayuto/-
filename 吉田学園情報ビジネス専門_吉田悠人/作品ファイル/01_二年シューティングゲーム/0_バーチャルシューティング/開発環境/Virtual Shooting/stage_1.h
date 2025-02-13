//=============================================================================
//
// ステージ1処理 [stage_1.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _STAGE_1_H_
#define _STAGE_1_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "main.h"
#include "stage.h"
//=============================================================================
//前方宣言
//=============================================================================
class CScore;
class CBossBase;
//=============================================================================
// クラス定義
//=============================================================================
class CStage1 :public CStage
{
public:

	CStage1();						// コンストラクタ
	~CStage1();						// デストラクタ
	static CStage1*	Create(void);	// 生成処理

	HRESULT	Init(void);			// 初期化処理
	void	Uninit(void);		// 終了処理
	void	Update(void);		// 更新処理
	void	StageMode(void);	// ステージの進行
	void	EnemyCreate(void);	// エネミーの生成
	void	BossCreate(void);	// ボス生成
private:

	STAGE_ENEMY		m_EnemyCreate;	// エネミーの出現モード
	STAGE_DATA		m_StageData;	// エネミーの出現データ
	int				m_nBossPhase;	// ボス出現データ

};


#endif