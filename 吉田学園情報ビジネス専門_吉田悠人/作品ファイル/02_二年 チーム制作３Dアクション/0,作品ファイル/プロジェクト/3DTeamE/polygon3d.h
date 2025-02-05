//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//
//	polygon3d
//	Author:池田悠希
//
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
#ifndef _POLYGON3D_H_
#define _POLYGON3D_H_
#include "main.h"
#include "object3d.h"
class CPolygon3D : public CObject3D
{
public:
    CPolygon3D();
    ~CPolygon3D();
    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static CPolygon3D* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
private:
    LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;    // 頂点バッファへのポインタ
    LPDIRECT3DTEXTURE9 m_pTexture;
};
#endif
