#include "Header.h"

void swap(int& x1, int& x2, int& y1, int& y2) {
	int temp = x1;
	x1 = x2;
	x2 = temp;
	temp = y1;
	y1 = y2;
	y2 = temp;
}

void NaiveLine(HDC hdc, int Xs, int Ys, int Xe, int Ye) {
	int dx = Xe - Xs;
	int dy = Ye - Ys;
	if (abs(dx) >= abs(dy)) {
		if(Xs > Xe)
			swap(Xs, Xe, Ys, Ye);
		int x = Xs;
		while (x < Xe)
		{
			int y = round(Ys + dy * (x - Xs) / dx);
			SetPixel(hdc, x, y, RGB(0, 0, 0));
			x++;
		}
	}
	else {
		if(Ys > Ye)
			swap(Xs, Xe, Ys, Ye);
		int y = Ys;
		while (y < Ye)
		{
			int x = round(Xs + dx * (y - Ys) / dy);
			SetPixel(hdc, x, y, RGB(0, 0, 0));
			y++;
		}
	}
}
