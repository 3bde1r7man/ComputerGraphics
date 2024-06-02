#include "Header.h"

void draw8points(HDC hdc, int x, int y, int xc, int yc) {
	SetPixel(hdc, xc + x, yc + y, RGB(0, 0, 0));
	SetPixel(hdc, xc - x, yc + y, RGB(0, 0, 0));
	SetPixel(hdc, xc + x, yc - y, RGB(0, 0, 0));
	SetPixel(hdc, xc - x, yc - y, RGB(0, 0, 0));
	SetPixel(hdc, xc + y, yc + x, RGB(0, 0, 0));
	SetPixel(hdc, xc - y, yc + x, RGB(0, 0, 0));
	SetPixel(hdc, xc + y, yc - x, RGB(0, 0, 0));
	SetPixel(hdc, xc - y, yc - x, RGB(0, 0, 0));
}


LRESULT WINAPI Circle(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
	HDC hdc;
	int x = 0, y = 0;
	switch (m)
	{
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		x = LOWORD(lp);
		y = HIWORD(lp);
		CircleBresenham(hdc, x, y, 200);
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
