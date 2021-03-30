//=============================================================================
//
// ���\�[�X�}�l�[�W���[ [reource manager.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "main.h"
#include "manager.h"
//=============================================================================
// �N���X��`
//=============================================================================
class CResource
{
public:

	CResource();
	~CResource();

	HRESULT Init(void);
	void	Uninit(void);
	//void	TextureLoad(void);	// �e�N�X�`�����[�h
	//void	XFail(void);		// X�t�@�C���ǂݍ��݃t�@�C��
	//void	TextureFail(void);	// �e�N�X�`���ǂݍ��݃t�@�C��

private:
	char**				m_pcTextureName;	// �t�@�C���̖��O
	int*				m_npTexture;		// �e�N�X�`���ԍ�
	int					m_nMaxTexture;		// �e�N�X�`���̑���
	LPDIRECT3DTEXTURE9*	m_pTexture;			// �e�N�X�`���ւ̃|�C���^

};
#endif
