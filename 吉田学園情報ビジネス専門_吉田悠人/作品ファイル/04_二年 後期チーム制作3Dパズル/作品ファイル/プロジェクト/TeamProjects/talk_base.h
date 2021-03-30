//=============================================================================
//
//	�Z���t�e�N���X[talk_bass.h]
//	Author:����@�r�H
//
//=============================================================================

// ��d�C���N���[�h�h�~
#ifndef _TALK_BASS_H_
#define _TALK_BASS_H_

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "ui.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CTalkbase :public CUi
{
public:

	// ��bUI�̎��
	typedef enum
	{
		TALK_NONE = -1,
		TALK_1,
		TALK_2,
		TALK_3,
		TALK_4,
		TALK_5,
		TALK_6,
		TALK_7,
		TALK_8,
		TALK_9,
		TALK_10,
		TALK_11,
		TALK_12,
		TALK_MAX
	}TALK;

	typedef enum
	{
		FADE_NONE = 0,
		FADE_IN,
		FADE_OUT,
		FADE_MAX
	}TALK_FADE;

	CTalkbase(int nPriorit = PRIORITY_UI_0);	// �R���X�g���N�^
	~CTalkbase();								// �f�X�g���N�^
	static HRESULT	Load(void);
	static void		Unload(void);

	HRESULT		Init(void);				// ����������
	void		Uninit(void);			// �I������
	void		Update(void);			// �X�V����

	virtual void Talk(void);			// �g�[�N�����ɐi�߂�֐�
	void		Blackout(void);			// �t�F�[�h�C���E�A�E�g�̏���

	void		SetAppear(int nAppear);		// �o�����ԃZ�b�^�[
	int			GetAppear(void);			// �o�����ԃQ�b�^�[
	void		SetFade(TALK_FADE FadeStatus);	// �t�F�[�h��ԃZ�b�^�[
	TALK_FADE	GetFade(void);					// �t�F�[�h��ԃQ�b�^�[
	bool		GetTalkEnd(void);				// �I�����Ă��邩

	void		SetTalk(TALK talk);			// �e�L�X�g�Z�b�^�[
	static TALK GetTalk(void);				// �e�L�X�g�Q�b�^�[
	void		BindTalkTexture(TALK talk);	// �e�L�X�g�摜�Z�b�g
	
	
	void SetFlagTex(TALK talk);
	void SetColTex(void) { m_col.a = 0.0f; }


private:
	D3DXCOLOR		m_col;			// �J���[
	bool			m_bTalkEnd;		// �I�����Ă��邩
	int				m_nAppear;		// �o������

protected:
	TALK_FADE					m_Fade;					// �����̓��ߏ�
	int							m_nTalkCount;			// �����܂ł̃J�E���g

	static TALK					m_Talk;					// �e�L�X�g�^�C�v
	static LPDIRECT3DTEXTURE9	m_apTexture[TALK_MAX];	// �e�N�X�`���f�[�^

};
#endif
