//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//
//	renderer.cpp
//	Author:池田悠希
//
//・・・・・・・・・・・・・・・・・・・・・・・・・・・

//・・・・・・・・・・・・・・・・・・・・・・・・・・・
//インクルードファイル
//・・・・・・・・・・・・・・・・・・・・・・・・・・・
#include "renderer.h"

#include "debug.h"
#include "fade.h"
#include "manager.h"
#include "number.h"
#include "object.h"
#include "object2d.h"
CRenderer::CRenderer()
{
    m_pD3D       = NULL;
    m_pD3DDevice = NULL;
}

CRenderer::~CRenderer()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CRenderer::Init(HWND hWnd, bool bWindow)
{
    D3DPRESENT_PARAMETERS d3dpp;
    D3DDISPLAYMODE d3ddm;

    // Direct3Dオブジェクトの作成
    m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if(m_pD3D == NULL)
    {
        return E_FAIL;
    }

    // 現在のディスプレイモードを取得
    if(FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
    {
        return E_FAIL;
    }

    // デバイスのプレゼンテーションパラメータの設定
    ZeroMemory(&d3dpp, sizeof(d3dpp));                                 // ワークをゼロクリア
    d3dpp.BackBufferCount            = 1;                              // バックバッファの数
    d3dpp.BackBufferWidth            = SCREEN_WIDTH;                   // ゲーム画面サイズ(幅)
    d3dpp.BackBufferHeight           = SCREEN_HEIGHT;                  // ゲーム画面サイズ(高さ)
    d3dpp.BackBufferFormat           = d3ddm.Format;                   // カラーモードの指定
    d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;          // 映像信号に同期してフリップする
    d3dpp.EnableAutoDepthStencil     = TRUE;                           // デプスバッファ（Ｚバッファ）とステンシルバッファを作成
    d3dpp.AutoDepthStencilFormat     = D3DFMT_D16;                     // デプスバッファとして16bitを使う
    d3dpp.Windowed                   = bWindow;                        // ウィンドウモード
    d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;        // リフレッシュレート
    d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_DEFAULT;    // インターバル

    // デバイスの生成
    // ディスプレイアダプタを表すためのデバイスを作成
    // 描画と頂点処理をハードウェアで行なう
    if(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
                                   D3DDEVTYPE_HAL,
                                   hWnd,
                                   D3DCREATE_HARDWARE_VERTEXPROCESSING,
                                   &d3dpp,
                                   &m_pD3DDevice)))
    {
        // 上記の設定が失敗したら
        // 描画をハードウェアで行い、頂点処理はCPUで行なう
        if(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
                                       D3DDEVTYPE_HAL,
                                       hWnd,
                                       D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                       &d3dpp,
                                       &m_pD3DDevice)))
        {
            // 上記の設定が失敗したら
            // 描画と頂点処理をCPUで行なう
            if(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
                                           D3DDEVTYPE_REF,
                                           hWnd,
                                           D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                           &d3dpp,
                                           &m_pD3DDevice)))
            {
                // 生成失敗
                return E_FAIL;
            }
        }
    }

    // レンダーステートの設定
    m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);     //裏面をカリング
    m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);    //透明度を使うか
    m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);    //αデスティ
    // サンプラーステートの設定
    m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_MIRROR);
    m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_MIRROR);
    m_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);    //ドット絵のときはD3DTEXF_POINT
    m_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

    // テクスチャステージステートの設定
    m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

    srand((unsigned int)time(0));
    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CRenderer::Uninit(void)
{

    // デバイスの破棄
    if(m_pD3DDevice != NULL)
    {
        m_pD3DDevice->Release();
        m_pD3DDevice = NULL;
    }

    // Direct3Dオブジェクトの破棄
    if(m_pD3D != NULL)
    {
        m_pD3D->Release();
        m_pD3D = NULL;
    }
}

//=============================================================================
// 更新処理
//=============================================================================
void CRenderer::Update(void)
{
    // ポリゴンの更新処理
    CObject::UpdateAll();
}

//=============================================================================
// 描画処理
//=============================================================================
void CRenderer::Draw(void)
{
    // バックバッファ＆Ｚバッファのクリア
    m_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
    // Direct3Dによる描画の開始
    if(SUCCEEDED(m_pD3DDevice->BeginScene()))
    {
        // ポリゴンの描画処理
        CObject::DrawAll();
        //デバッグ情報の描画

        //フェード描画
        CManager::GetFade()->Draw();

#ifdef _DEBUG
        CDebug::Print("FPS:%d\n", GetFPS());
        CDebug::Draw();
#endif    // _DEBUG

        // Direct3Dによる描画の終了
        m_pD3DDevice->EndScene();
    }

    // バックバッファとフロントバッファの入れ替え
    m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
