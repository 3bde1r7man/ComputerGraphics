#include "../Header.h"

void drawLineLow(HDC hdc, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	int yi = 1;
	if (dy < 0) { // make sure y1 < y2
		yi = -1;
		dy = -dy;
	}
	int d = 2 * dy - dx;
	int dE = 2 * dy, dNE = 2 * (dy - dx);
	int x = x1, y = y1;
	SetPixel(hdc, x, y, RGB(0, 0, 0));
	while (x < x2) {
		if (d < 0) {
			d += dE;
		}
		else {
			d += dNE;
			y += yi;
		}
		x++;
		SetPixel(hdc, x, y, RGB(0, 0, 0));
	}
}

void drawLineHigh(HDC hdc, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	int xi = 1;
	if (dx < 0) { // make sure x1 < x2
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	int dN = 2 * dx, dNE = 2 * (dx - dy);
	int x = x1, y = y1;
	SetPixel(hdc, x, y, RGB(0, 0, 0));
	while (y < y2) {
		if (d < 0) {
			d += dN;
		}
		else {
			d += dNE;
			x += xi;
		}
		y++;
		SetPixel(hdc, x, y, RGB(0, 0, 0));
	}
}


// mid point line drawing algorithm
void BresenhamLine(HDC hdc, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	if (abs(dy) <= abs(dx)) { // slope < 1
		if(x1 > x2) // make sure x1 < x2
			swap(x1, x2, y1, y2);
		drawLineLow(hdc, x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2) // make sure y1 < y2
			swap(x1, x2, y1, y2);
		drawLineHigh(hdc, x1, y1, x2, y2);
	}
}



