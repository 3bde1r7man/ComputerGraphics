#include "Header.h"


void CircleDirect(HDC hdc, int xc, int yc, int R) {
	int x = 0, y = R;
	int R2 = R * R;
	draw8points(hdc, x, y, xc, yc);
	while (x < y)
	{
		x++;
		y = round(sqrt((double)(R2 - x * x)));
		draw8points(hdc, x, y, xc, yc);
	}
}
