#include"input.h"
#include"WinApp.h"
#include"DirectXCommon.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    //ポインタ変数
    input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;

#pragma region WindowsAPI初期化処理

    //windowsAPIの初期化
    winApp_ = new WinApp();
    winApp_->Initialize();
    
#pragma endregion

#pragma region DirectX初期化処理
    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

   //input生成、初期化
    input_=new input();
    input_->Initalize(winApp_);


    // ゲームループ
    while (true) {
        //更新
        if (winApp_->Update() == true) {
            break;
        }

        input_->Updete();

        dxCommon_->ProDraw();

        // ４．描画コマンドここまで
        dxCommon_->PostDraw();
        // DirectX毎フレーム処理　ここまで

    }

    delete  input_;
    delete dxCommon_;
    winApp_->Finalize();
    delete winApp_;
    return 0;
}
