#ifndef _PAUSE_H_
#define _PAUSE_H_
//----------------------------------------------
//ヘッダーファイル
//----------------------------------------------
#include "main.h"
#include "scene2d.h"
//----------------------------------------------
//マクロ定義
//----------------------------------------------

//----------------------------------------------
//前置処理
//----------------------------------------------

//------------------------------------
//クラス処理
//------------------------------------
class CPause 
{
public:
	CPause();							//コンストラクタ
	~CPause();							//デストラクタ

	//テクスチャ種類

	static HRESULT	Load(void);		//テクスチャ読み込み
	static void		Unload(void);	//テクスチャの破棄
	static CPause*	Create(void);	//生成処理

	HRESULT			Init(void);		//初期化処理
	void			Uninit(void);	//終了処理
	void			Update(void);	//更新処理
	void			Draw(void);		//描画処理

private:
	static bool					m_bPause;
	static LPDIRECT3DTEXTURE9	m_pTexture;		//テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9		m_pVtxBuff;		//頂点バッファへのポインタ
	
};



#endif