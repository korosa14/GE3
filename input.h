#pragma once
#include<Windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include<wrl.h>


class input
{
public:

	//������
	void Initalize(HINSTANCE hInstance, HWND hwnd);
	//�X�V
	void Updete();

	//�C�ӂ̃{�^����������Ă���
	bool PushKey(BYTE keyNumber);
	//�C�ӂ̃{�^���������ꂽ�u��
	bool TriggerKey(BYTE keyNumber);
	//�C�ӂ̃{�^���������ꂽ�u��


private:
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

