//=============================================================================
//
// �ו��u���b�N [luggage block.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _LUGGSGE_BLOCK_H_
#define _LUGGSGE_BLOCK_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "goal block base.h"
//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
// �O���錾
//=============================================================================
class CModel;
//=============================================================================
// �N���X��`
//=============================================================================
class CLuggageBlock : public CGoalBlockBase
{
public:
	CLuggageBlock();
	~CLuggageBlock();
	static HRESULT			Load(void);
	static void				Unload(void);
	static CLuggageBlock*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, CGame::MAP_TYPE MapType ,bool Goal = true);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
private:
	bool						bGoal;			//�S�[���Ƃ��ċ@�\���邩
	static CModel::MODELDATA	m_modeldata;	//���f���f�[�^
};
#endif