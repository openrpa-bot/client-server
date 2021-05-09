// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <windows.h>
#include <stdio.h>

HHOOK hMouseHook;
HHOOK hKeyboardHook;

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    MOUSEHOOKSTRUCT* pMouseStruct = (MOUSEHOOKSTRUCT*)lParam;
    if (pMouseStruct != NULL) {
        if (wParam == WM_LBUTTONDOWN)
        {
            printf("clicked");
        }
        printf("Mouse position X = %d  Mouse Position Y = %d\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
    }
    return CallNextHookEx(hMouseHook, nCode, wParam, lParam);
}
LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT* pKeyboardStruct = (KBDLLHOOKSTRUCT*)lParam;
    if (pKeyboardStruct != NULL) {
        printf("Keystroke vCode = %c  Keystroke scancode = %c\n", pKeyboardStruct->vkCode, pKeyboardStruct->scanCode);
    }
    return CallNextHookEx(hMouseHook, nCode, wParam, lParam);
}

DWORD WINAPI MyMouseLogger(LPVOID lpParm)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // here I put WH_MOUSE instead of WH_MOUSE_LL
    hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, hInstance, NULL);
    hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardProc, hInstance, NULL);

    MSG message;
    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    UnhookWindowsHookEx(hKeyboardHook);
    UnhookWindowsHookEx(hMouseHook);
    return 0;
}

int main(int argc, char** argv)
{
    HANDLE hThread;
    DWORD dwThread;

    hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MyMouseLogger, (LPVOID)argv[0], NULL, &dwThread);
    if (hThread)
        return WaitForSingleObject(hThread, INFINITE);
    else
        return 1;

}