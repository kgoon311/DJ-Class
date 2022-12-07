#include "pch.h"

extern HINSTANCE hInst;
extern BOOL bIsActive;
extern BOOL bIsQuit;

HDC hScreenDC, hImageDC;
HBITMAP hBM;
POINT ptCoord = { 0, 0 };

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{ 
    return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

    EndPaint(hWnd, &ps);
    return 0;
}
int OnCoomand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    bIsQuit = true;
    bIsActive = false;
    PostQuitMessage(0);
    return 0;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:         return OnCreate(hWnd, wParam, lParam);
    case WM_TIMER:          return OnTimer(hWnd, wParam, lParam);
    case WM_RBUTTONUP:      return OnCoomand(hWnd, wParam, lParam);
    case WM_PAINT:          return OnPaint(hWnd, wParam, lParam);
    case WM_DESTROY:        return OnDestroy(hWnd, wParam, lParam);
    default:                return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void GameRun()
{
    //BitBlt(hScreenDC, ptCoord.x, ptCoord.y, 300, 300, hImageDC, 0, 0, SRCCOPY);
    BitBlt(hScreenDC, 0, 0, 300, 300, hImageDC, ptCoord.x, ptCoord.y, SRCCOPY);
    //StretchBlt(hScreenDC, 0, 0, 600, 600, hImageDC, 0, 0, 300, 300, SRCCOPY);
}
