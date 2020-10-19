#ifndef _PAUSE_H_
#define _PAUSE_H_
//----------------------------------------------
//�w�b�_�[�t�@�C��
//----------------------------------------------
#include "main.h"
#include "scene2d.h"
//----------------------------------------------
//�}�N����`
//----------------------------------------------

//----------------------------------------------
//�O�u����
//----------------------------------------------

//------------------------------------
//�N���X����
//------------------------------------
class CPause 
{
public:
	CPause();							//�R���X�g���N�^
	~CPause();							//�f�X�g���N�^

	//�e�N�X�`�����

	static HRESULT	Load(void);		//�e�N�X�`���ǂݍ���
	static void		Unload(void);	//�e�N�X�`���̔j��
	static CPause*	Create(void);	//��������

	HRESULT			Init(void);		//����������
	void			Uninit(void);	//�I������
	void			Update(void);	//�X�V����
	void			Draw(void);		//�`�揈��

private:
	static bool					m_bPause;
	static LPDIRECT3DTEXTURE9	m_pTexture;		//�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9		m_pVtxBuff;		//���_�o�b�t�@�ւ̃|�C���^
	
};



#endif