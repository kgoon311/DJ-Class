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
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
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
