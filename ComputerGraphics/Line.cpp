#include "Header.h"

void swap(int& x1, int& x2, int& y1, int& y2) {
	int temp = x1;
	x1 = x2;
	x2 = temp;
	temp = y1;
	y1 = y2;
	y2 = temp;
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
			// call fun
			MidpointLine(hdc, x1, y1, x2, y2);
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
