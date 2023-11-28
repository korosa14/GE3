#pragma once
#include<Windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include<wrl.h>


class input
{
public:

	//初期化
	void Initalize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Updete();

private:
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
};

