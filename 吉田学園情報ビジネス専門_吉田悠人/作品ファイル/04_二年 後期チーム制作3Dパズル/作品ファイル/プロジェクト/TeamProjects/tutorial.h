//=============================================================================
//
//	�`���[�g���A�� [tutorial.h]
//	Author : ��؁@����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

//====================================
//�C���N���[�h
//====================================
#include "main.h"
#include "ui.h"

//====================================
// �N���X��`
//====================================

//UI�N���X
class CTutorial : public CUi
{
public:
	CTutorial(int nPriorit = PRIORITY_UI_0);
	~CTutorial();

	static CTutorial *Create(void);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void TutorialUninit(void);
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	CObject2D* m_pObject2d;
};
#endif // !_UI_H_