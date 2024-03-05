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

void drawCircle(HDC hdc, int x, int y, int r) {
	int xc = x, yc = y;

	double dtheata = 1.0 / r;
	// calculate the sine and cosine of the angle only once
	double c = cos(dtheata); 
	double s = sin(dtheata);
	double x1 = r, y1 = 0;
	draw8points(hdc, x1, y1, xc, yc);
	while (x1 > y1) {
		double x2 = x1 * c - y1 * s;
		y1 = x1 * s + y1 * c;
		x1 = x2;
		draw8points(hdc, round(x1), round(y1), xc, yc);
	}
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
		drawCircle(hdc, x, y, 200);
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
