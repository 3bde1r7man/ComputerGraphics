#include "../Header.h"
// draw circle using bresenham's 2nd order algorithm
void CircleBresenham(HDC hdc, int xc, int yc, int r) {

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
