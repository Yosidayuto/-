//=============================================================================
//
//	背景[bg.h]
//	Author:吉田　悠人
//
//=============================================================================

#ifndef _Bakground_H_
#define _Bakground_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "scene2d.h"
#include "manager.h"

//=============================================================================
// クラス定義
//=============================================================================
class CBgc :public CScene2d
{
public:

	CBgc(int nPriorit = PRIORITY_SCENE);			//コンストラクタ
	~CBgc();						//デストラクタ

	HRESULT			Init(void);		//初期化処理
	void			Uninit(void);	//終了処理
	void			Update(void);	//更新処理
	void			Draw(void);		//描画処理

	void			ScrollY(float fScroll);	//Y方向画面スクロール
	void			ScrollX(float fScroll);	//X方向画面スクロール

private:
	int					m_nCounterAnim;	//アニメーションカウンター
	int					m_nPatternAnim;	//アニメーションパターンNo
};
#endif