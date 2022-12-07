#include "framework.h"

extern BOOL	 bIsActive;
extern HWND	hWndMain;
extern HDC	ScreenDC;
extern HDC	MemoryDC;
extern RECT	rtSystem;
extern int nFPS, nCount;
extern int nMenuSel;
extern POINT ptKeyInput;
extern int nTheta;
extern float fSize;

int GameLoop()
{
	MSG		msg;
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return (int)msg.wParam;
			}
		}
		else if (bIsActive)
		{
			BitBlt(MemoryDC,
				rtSystem.left, rtSystem.top, rtSystem.right, rtSystem.bottom,
				NULL, 0, 0, BLACKNESS); //화면을 초기화하는 작업

			gdi->StartDraw(MemoryDC);
			Run();
			gdi->StopDraw(MemoryDC);

			BitBlt(ScreenDC,
				rtSystem.left, rtSystem.top, rtSystem.right, rtSystem.bottom,
				MemoryDC, 0, 0, SRCCOPY); // 메모리에 그려진 영역 ==> 화면
		}
		else
		{
			WaitMessage();
		}
	}

	return 1;
}


void YellowDot(int x, int y)
{
	gdi->DrawDot(x + 0, y + 0, RGB(255, 255, 0));
	gdi->DrawDot(x + 0, y + 1, RGB(255, 255, 0));
	gdi->DrawDot(x + 1, y + 0, RGB(255, 255, 0));
	gdi->DrawDot(x + 1, y + 1, RGB(255, 255, 0));

	gdi->DrawDot(x + 0, y - 1, RGB(255, 255, 0));
	gdi->DrawDot(x + 1, y - 0, RGB(255, 255, 0));
	gdi->DrawDot(x + 1, y - 1, RGB(255, 255, 0));

	gdi->DrawDot(x - 0, y + 1, RGB(255, 255, 0));
	gdi->DrawDot(x - 1, y + 0, RGB(255, 255, 0));
	gdi->DrawDot(x - 1, y + 1, RGB(255, 255, 0));

	gdi->DrawDot(x - 0, y - 1, RGB(255, 255, 0));
	gdi->DrawDot(x - 1, y - 0, RGB(255, 255, 0));
	gdi->DrawDot(x - 1, y - 1, RGB(255, 255, 0));
}

void Cross()
{
	POINT ptMid;
	ptMid.x = (rtSystem.right - rtSystem.left) / 2;
	ptMid.y = (rtSystem.bottom - rtSystem.top) / 2;

	gdi->SetPenColor(gdi->ltgray);
	gdi->Line((int)ptMid.x, rtSystem.top, ptMid.x, rtSystem.bottom);
	gdi->Line((int)rtSystem.left, ptMid.y, rtSystem.right, ptMid.y);
}

void Cross(int x, int y)
{
	if (x == 0) x = (rtSystem.right - rtSystem.left) / 2;
	if (y == 0) y = (rtSystem.bottom - rtSystem.top) / 2;

	gdi->SetPenColor(gdi->ltgray);
	gdi->Line(x, rtSystem.top, x, rtSystem.bottom);
	gdi->Line(rtSystem.left, y, rtSystem.right, y);

	int c = 0;
	int k = 5;
	for (int i = x, j = x; i < rtSystem.right; i += 10, j -= 10)
	{
		gdi->YellowPen();
		if (!(c % 5))
		{
			gdi->SetPenColor(gdi->white);
			k = 10;
			char str[8];
			sprintf(str, "%d", i - (rtSystem.right / 2));
			gdi->TransparentText();
			gdi->TextAlignCenter();
			gdi->TextColor(gdi->yellow);
			gdi->TextAtPos(i, y + 20, str);
			gdi->TextAtPos(j, y + 20, str);
		}
		else k = 5;
		gdi->Line(i, y + k, i, y - k);
		gdi->Line(j, y + k, j, y - k);
		c++;
	}

	for (int i = y, j = y; i < rtSystem.bottom; i += 10, j -= 10)
	{
		gdi->YellowPen();
		if (!(c % 5))
		{
			gdi->SetPenColor(gdi->white);
			k = 10;
			char str[8];
			sprintf(str, "%d", i - (rtSystem.bottom / 2));
			gdi->TransparentText();
			gdi->TextAlignRight();
			gdi->TextColor(gdi->cyan);
			gdi->TextAtPos(x - 20, i - 4, str);
			gdi->TextAtPos(x - 20, j - 4, str);
		}
		else k = 5;
		gdi->Line(x + k, i, x - k, i);
		gdi->Line(x + k, j, x - k, j);
		c++;
	}
}

void Grid()
{
	int c = 0;
	for (int i = rtSystem.left; i <= rtSystem.right; i += 10)
	{
		gdi->SetPenColor(gdi->gray);
		if (!(c % 5))	gdi->SetPenColor(gdi->white);
		gdi->Line(i, rtSystem.top, i, rtSystem.bottom);
		c++;
	}
	c = 0;
	for (int j = rtSystem.top; j <= rtSystem.bottom; j += 10)
	{
		gdi->SetPenColor(gdi->gray);
		if (!(c % 5))	gdi->SetPenColor(gdi->white);
		gdi->Line(rtSystem.left, j, rtSystem.right, j);
		c++;
	}
}

void Run()
{
	switch (nMenuSel)
	{
	case CROSS1:	Cross();	break;
	case CROSS2:	Cross(0, 0);	break;
	case GRID:		Grid();		break;
	case NONE:	break;
	}
	

	Process();
	Render();
	Sleep(1000 / 33);
}

void Process()
{

}


void Render()
{ 
	POINT ptCenter = { (rtSystem.right - rtSystem.left) / 2, (rtSystem.bottom - rtSystem.top) / 2};

	Triangle tri, triS, triR, triM;
	tri.SetVertex(Vertex(0.f, 100.f, 0.f),
				 Vertex(-100.f, -100.f, 0.f),
				 Vertex(100.f, -100.f, 0.f));
	tri.SetIndex(0, 1, 2);

	Matrix44 CTM , KTM;
	CTM.Identity();

	KTM.m11 = 1.f;
	KTM.m12 = 2.f;
	KTM.m13 = 3.f;
	KTM.m14 = 4.f;
	KTM.m33 = 5.f;
	KTM.m44 = 6.f;

	KTM = CTM.Multiply(KTM);
	/*triS = tri;
	triS.V[0].x = tri.V[0].x * fSize;
	triS.V[0].y = tri.V[0].y * fSize;
	triS.V[1].x = tri.V[1].x * fSize;
	triS.V[1].y = tri.V[1].y * fSize;
	triS.V[2].x = tri.V[2].x * fSize;
	triS.V[2].y = tri.V[2].y * fSize;

	triR = triS;
	float theta = 3.141592f / 180.f * (float)nTheta;
	triR.V[0].x = triS.V[0].x * sin(theta) + triS.V[0].y * cos(theta);
	triR.V[0].y = triS.V[0].x * cos(theta) - triS.V[0].y * sin(theta);
	triR.V[1].x = triS.V[1].x * sin(theta) + triS.V[1].y * cos(theta);
	triR.V[1].y = triS.V[1].x * cos(theta) - triS.V[1].y * sin(theta);
	triR.V[2].x = triS.V[2].x * sin(theta) + triS.V[2].y * cos(theta);
	triR.V[2].y = triS.V[2].x * cos(theta) - triS.V[2].y * sin(theta);


	triM = triR;
	triM.V[0].x = triR.V[0].x + ptKeyInput.x;
	triM.V[0].y = triR.V[0].y + ptKeyInput.y;
	triM.V[1].x = triR.V[1].x + ptKeyInput.x;
	triM.V[1].y = triR.V[1].y + ptKeyInput.y;
	triM.V[2].x = triR.V[2].x + ptKeyInput.x;
	triM.V[2].y = triR.V[2].y + ptKeyInput.y;

	triM.Draw(ptCenter.x, ptCenter.y);*/

}