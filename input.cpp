#include "input.h"

#include<cassert>


using namespace Microsoft::WRL;

void input::Initalize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    // DirectInput�̏�����
    ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // �L�[�{�[�h�f�o�C�X�̐���
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // ���̓f�[�^�`���̃Z�b�g
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    assert(SUCCEEDED(result));
    // �r�����䃌�x���̃Z�b�g
    result = keyboard->SetCooperativeLevel(
        hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void input::Updete()
{
    //keyPre�̒���key�̏����R�s�[����
    memcpy(keyPre, key, sizeof(key));

    // �L�[�{�[�h���̎擾�J�n
    keyboard->Acquire();
    // �S�L�[�̓��͏�Ԃ��擾����
    keyboard->GetDeviceState(sizeof(key), key);

}

bool input::PushKey(BYTE keyNumber)
{
    //�w��L�[�������Ă���΂�true�Ԃ�
    if (key[keyNumber]) {
        return true;
    }
    //�����łȂ����false��Ԃ�
    return false;
}

bool input::TriggerKey(BYTE keyNumber)
{
    if (key[keyNumber]&& keyPre[keyNumber] == 0) {
        return true;
    }
    return false;
}
