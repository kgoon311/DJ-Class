#include "framework.h"


extern HINSTANCE hInst;
extern HWND	  hWndMain;
extern HDC	  ScreenDC, MemoryDC;
extern HBITMAP	hBitmap, hOldBitmap;
extern RECT  rtSystem;
extern BOOL	  bIsActive;
extern int	  nFPS;
extern int    nCount;
extern int    nMenuSel;
extern POINT ptKeyInput;
extern int nThetaX;
extern int nThetaY;
extern int nThetaZ;
extern float fSize;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    ScreenDC = GetDC(hWnd);
    MemoryDC = CreateCompatibleDC(ScreenDC);
    GetClientRect(hWnd, &rtSystem);
    hBitmap = CreateCompatibleBitmap(ScreenDC, rtSystem.right, rtSystem.bottom);
    hOldBitmap = (HBITMAP)SelectObject(MemoryDC, hBitmap); //�ĸ����,BackBuffer
    SetTimer(hWnd, 0, 1000, NULL);

    bIsActive = true;
    return 0;
}

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    nFPS = nCount;
    nCount = 0;
    return 0;
}

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
    case VK_UP:        ptKeyInput.y += 5;        break;
    case VK_DOWN:      ptKeyInput.y -= 5;        break;
    case VK_LEFT:      ptKeyInput.x -= 5;        break;
    case VK_RIGHT:     ptKeyInput.x += 5;        break;
    case 'R':          nThetaZ += 1;             break;
    case 'E':          nThetaZ -= 1;             break;
    case 'F':          nThetaY += 1;             break;
    case 'D':          nThetaY -= 1;             break;
    case 'V':          nThetaX += 1;             break;
    case 'C':          nThetaX -= 1;             break;
    case 'S':          fSize += 0.1f;           break;
    case 'A':          fSize -= 0.1f;           break;
    }

    if (nThetaX >= 360)   nThetaX = 0;
    if (nThetaY >= 360)   nThetaY = 0;
    if (nThetaZ >= 360)   nThetaZ = 0;

    return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    bIsActive = false;
    DeleteObject(hBitmap);
    DeleteObject(hOldBitmap);
    ReleaseDC(hWnd, MemoryDC);
    ReleaseDC(hWnd, ScreenDC);
    PostQuitMessage(0);
    return 0;
}

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    int wmId = LOWORD(wParam);
    // �޴� ������ ���� �м��մϴ�:
    switch (wmId)
    {
    case ID_VIEW_NONE:
        nMenuSel = NONE;
        break;
    case ID_VIEW_CROSS1:
        nMenuSel = CROSS1;
        break;
    case ID_VIEW_CROSS2:
        nMenuSel = CROSS2;
        break;
    case ID_VIEW_GRID:
        nMenuSel = GRID;
        break;
    case IDM_ABOUT:
        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
        break;
    case IDM_EXIT:
        DestroyWindow(hWnd);
        break;
    default:
        return DefWindowProc(hWnd, WM_COMMAND, wParam, lParam);
    }
    return 0;
}

int OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    DeleteObject(hBitmap);
    DeleteObject(hOldBitmap);
    ReleaseDC(hWnd, MemoryDC);
    ReleaseDC(hWnd, ScreenDC);

    ScreenDC = GetDC(hWnd);
    MemoryDC = CreateCompatibleDC(ScreenDC);
    GetClientRect(hWnd, &rtSystem);
    hBitmap = CreateCompatibleBitmap(ScreenDC, rtSystem.right, rtSystem.bottom);
    hOldBitmap = (HBITMAP)SelectObject(MemoryDC, hBitmap); //�ĸ����,BackBuffer

    return  0;
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
    case WM_CREATE:     return OnCreate(hWnd, wParam, lParam);
    case WM_SIZE:       return OnSize(hWnd, wParam, lParam);
    case WM_TIMER:      return OnTimer(hWnd, wParam, lParam);
    case WM_KEYDOWN:    return OnKeyDown(hWnd, wParam, lParam);
    case WM_COMMAND:    return OnCommand(hWnd, wParam, lParam);
    case WM_DESTROY:    return OnDestroy(hWnd, wParam, lParam);
    default:            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
