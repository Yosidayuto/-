//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//
//	scene.h
//	Author:池田悠希
//
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
#ifndef _SCENE_H_
#define _SCENE_H_

#include "main.h"

//オブジェクトクラス

class CObject
{
public:
    typedef enum
    {
        OBJTYPE_NONE = 0,
        OBJTYPE_PLAYER,
        OBJTYPE_ENEMY,
        OBJTYPE_MODEL,
        OBJTYPE_OBSTACLE,
        OBJTYPE_STAGE
    } OBJTYPE;
    CObject(int nPriority = 0);
    virtual ~CObject();
	
	//純粋仮想関数群
    virtual HRESULT Init(void) = 0;  
    virtual void Uninit(void)  = 0;
    virtual void Update(void)  = 0;
    virtual void Draw(void)    = 0;

    static void UpdateAll(void);    //全シーン処理群
    static void DrawAll(void);
    static void ReleaseAll(void);
    void SetObjType(OBJTYPE type);
    static CObject** GetTop(void);
    CObject* GetNext(void);
    CObject* GetPrev(void);
    OBJTYPE GetObjType(void);
    void SetCollisionBullet(bool bHit);
    bool GetCollisionBullet(void);

protected:
    void Release(void);    //シーンの開放

private:
    void Death(void);
    static CObject* m_pTop[PRIORITY_MAX];
    static CObject* m_pCur[PRIORITY_MAX];
    CObject* m_pPrev;
    CObject* m_pNext;
    int m_nPriority;
    bool m_bDestroy;
    OBJTYPE m_objType;
    bool bCollisionBullet;
};

#endif
