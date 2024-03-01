#include "Header.h"

/*
Date : 1 - 3 - 2024
Author : Abderhman Mostafa
Description : this is the Line drawing file using DDA algorithm
*/

void swap(int& x1, int& x2, int& y1, int& y2)
{
	int temp = x1;
	x1 = x2;
	x2 = temp;
	temp = y1;
	y1 = y2;
	y2 = temp;
}

void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;


	if (abs(dy) <= abs(dx)) { // slope <= 1
		if (dx == 0) {
			SetPixel(hdc, x1, y1, RGB(0, 0, 0)); // color black
			return;
		}
		float m = (float)dy / dx;
		if (x2 < x1)
		{
			swap(x1, x2, y1, y2);
		}
		int x;
		double y = y1;
		SetPixel(hdc, x1, y1, RGB(0, 0, 0)); // color black
		while (x1 < x2)
		{
			x1++;
			y += m;
			SetPixel(hdc, x1, round(y), RGB(0, 0, 0)); // color black
		}
	}
	else
	{
		if (y2 < y1)
		{
			swap(x1, x2, y1, y2);
		}
		int y;
		double x = x1;
		float mi = (float)dx / dy;
		SetPixel(hdc, x1, y1, RGB(0, 0, 0)); // color black
		while (y1 < y2)
		{
			y1++;
			x += mi;
			SetPixel(hdc, round(x), y1, RGB(0, 0, 0)); // color black
		}
	}
}

LRESULT WINAPI Line(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
	HDC hdc;
	static int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	static int mouseClicks = 0;
	switch (m)
	{
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		mouseClicks++;
		if (mouseClicks == 1)
		{
			x1 = LOWORD(lp);
			y1 = HIWORD(lp);

		}
		else if (mouseClicks == 2)
		{
			x2 = LOWORD(lp);
			y2 = HIWORD(lp);
			DrawLine(hdc, x1, y1, x2, y2);
			mouseClicks = 0;
		}
		ReleaseDC(hwnd, hdc);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hwnd, m, wp, lp);
	}
	return 0;
}