//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//
//	camera.cpp
//	Author:池田悠希
//
//・・・・・・・・・・・・・・・・・・・・・・・・・・・

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//インクルードファイル
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
#include "camera.h"

#include "input.h"
#include "inputkeyboard.h"
#include "main.h"
#include "manager.h"
#include "object.h"
#include "player.h"
#include "renderer.h"
#include "sound.h"
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//コンストラクタ
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
CCamera::CCamera()
{
}
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//デストラクタ
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
CCamera::~CCamera()
{
}

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//初期化処理
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
HRESULT CCamera::Init(void)
{
    //カメラの初期(位置・注意点・上方向)設定
    m_posV = D3DXVECTOR3(20, 40, -100);
    m_posR = m_posV + D3DXVECTOR3(0, 0, 500);
    m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    //カメラの向き設定
    m_rot = D3DXVECTOR3(45.0f, 180.0f, 0.0f);
    //カメラのプレイヤーからの距離設定
    m_fDistanceFromPlayer = CAMERA_DISTANCE_FROM_PLAYER;
    //視点-注意点の距離の計算
    m_fDistance = (float)sqrt(
      pow(m_posV.x - m_posR.x, 2.0f) + pow(m_posV.z - m_posR.z, 2.0f));
    //マネージャーにカメラ情報を保存
    CManager::BindCamera(this);
    return S_OK;
}

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//終了処理
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
void CCamera::Uninit(void)
{
}

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//更新処理
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
void CCamera::Update(void)
{
    CPlayer* pPlayer = NULL;
    //プレイヤーのポインタ取得
    pPlayer = CManager::GetPlayer();
    //キーボード入力の取得
    CInputKeyboard* pInput = (CInputKeyboard*)CManager::GetInputKey();
    //プレイヤーの状態によってカメラ距離を制御
    switch(pPlayer->GetState())
    {
        case CPlayer::STATE_AIM:
            m_fDistanceFromPlayerDest = CAMERA_DISTANCE_FROM_PLAYER_AIM;
            break;
        default:
            m_fDistanceFromPlayerDest = CAMERA_DISTANCE_FROM_PLAYER_STAND;
            break;
    }
    //カメラ距離の変化を補完
    m_fDistanceFromPlayer += (m_fDistanceFromPlayerDest - m_fDistanceFromPlayer) / 3;
    //カメラ回転の中心をプレイヤーの横に持ってくる
    m_RotateCenter = pPlayer->GetPos() + D3DXVECTOR3(sinf(D3DXToRadian(m_rot.y - 90)) * CAMERA_DISTANCE_FROM_PLAYER, PLAYER_HEAD_HEIGHT, cosf(D3DXToRadian(-m_rot.y - 90)) * CAMERA_DISTANCE_FROM_PLAYER);
    //カメラが地面を貫通してしまう場合地面に這わせるように
    if(m_RotateCenter.y + sinf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer > 0)
    {
        m_posV = m_RotateCenter + D3DXVECTOR3(sinf(D3DXToRadian(-m_rot.y)) * cosf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer, sinf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer, cosf(D3DXToRadian(-m_rot.y)) * cosf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer);
    }
    else
    {
        m_posV = m_RotateCenter + D3DXVECTOR3(sinf(D3DXToRadian(-m_rot.y)) * cosf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer, -m_RotateCenter.y + 1, cosf(D3DXToRadian(-m_rot.y)) * cosf(D3DXToRadian(m_rot.x)) * m_fDistanceFromPlayer);
    }
    //注視点を回転の中心にあわせる
    m_posR = m_RotateCenter;
}
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//カメラによる描画
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
void CCamera::SetCamera(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();    //デバイスへのポインタ
    //ビューマトリックスの初期化
    D3DXMatrixIdentity(&m_mtxView);
    //ビューマトリックスの作成
    D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);
    //ビューマトリックスの設定
    pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
    //プロジェクションマトリックスの初期化
    D3DXMatrixIdentity(&m_mtxProjection);
    //プロジェクションマトリックスの作成
    D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, CAMERA_VIEW_RANGE);
    //プロジェクションマトリックスの設定
    pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//ゲッター関数
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
D3DXVECTOR3 CCamera::GetRot(void)
{
    return m_rot;
}

D3DXVECTOR3 CCamera::GetPosR(void)
{
    //注視点を距離分の長さに補正して出力
    D3DXVECTOR3 vec;
    D3DXVec3Normalize(&vec, &(m_posR - m_posV));
    vec = vec * m_fDistance + m_posV;
    return vec;
}

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//セッター関数
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
void CCamera::SetRot(D3DXVECTOR3 rot)
{
    m_rot = rot;
}
