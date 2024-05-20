#include "Header.h"

void CirclePolar(HDC hdc, int xc, int yc, int R) {
	int x = R, y = 0;
	double theta = 0, dtheta = 1.0 / R;
	draw8points(hdc, x, y, xc, yc);
	while (x > y)
	{
		theta += dtheta;
		x = round(R * cos(theta));
		y = round(R * sin(theta));
		draw8points(hdc, x, y, xc, yc);
	}
}
