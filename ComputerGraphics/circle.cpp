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
// draw circle using bresenham's 2nd order algorithm
void drawCircle(HDC hdc, int xc, int yc, int r) {
	
	int d = 1 - r;
	int x = 0, y = r;
	draw8points(hdc, x, y, xc, yc);
	int ch1 = 3, ch2 = 5 - 2 * r;
	while (x < y) {
		if (d < 0) {
			d += ch1;
			ch2 += 2;
		}
		else {
			d += ch2;
			ch2 += 4;
			y--;
		}
		ch1 += 2;
		x++;
		draw8points(hdc, x, y, xc, yc);
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
