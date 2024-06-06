#include "../Header.h"


union OutCode
{
	unsigned All : 4;
	struct { unsigned left : 1,top : 1,right : 1,bottom : 1; };
};

OutCode GetOutCode(double x, double y, int xLeft, int yTop, int xRight, int yBottom)
{
	OutCode out;
	out.All = 0;
	if (x < xLeft)out.left = 1; else if (x > xRight)out.right = 1;
	if (y < yTop)out.top = 1; else if (y > yBottom)out.bottom = 1;
	return out;
}


void VIntersect(double xs, double ys, double xe, double ye, int x, double* xi, double* yi)
{
	*xi = x;
	*yi = ys + (x - xs) * (ye - ys) / (xe - xs);
}

void HIntersect(double xs, double ys, double xe, double ye, int y, double* xi, double* yi)
{
	*yi = y;
	*xi = xs + (y - ys) * (xe - xs) / (ye - ys);
}

// Cohen-Sutherland 2 point clipping algorithm
void CohenSutherland(HDC hdc, double xs, double ys, double xe, double ye, int xLeft, int yTop, int xRight, int yBottom)
{
	OutCode out1 = GetOutCode(xs, ys, xLeft, yTop, xRight, yBottom);
	OutCode out2 = GetOutCode(xe, ye, xLeft, yTop, xRight, yBottom);
	bool accept = false;
	while (true)
	{
		if (!(out1.All | out2.All))
		{
			accept = true;
			break;
		}
		else if (out1.All & out2.All)
		{
			break;
		}
		else
		{
			double xi, yi;
			if (out1.All)
			{
				if (out1.left)VIntersect(xs, ys, xe, ye, xLeft, &xi, &yi);
				else if (out1.right)VIntersect(xs, ys, xe, ye, xRight, &xi, &yi);
				else if (out1.top)HIntersect(xs, ys, xe, ye, yTop, &xi, &yi);
				else if (out1.bottom)HIntersect(xs, ys, xe, ye, yBottom, &xi, &yi);
				xs = xi;
				ys = yi;
				out1 = GetOutCode(xs, ys, xLeft, yTop, xRight, yBottom);
			}
			else
			{
				if (out2.left)VIntersect(xs, ys, xe, ye, xLeft, &xi, &yi);
				else if (out2.right)VIntersect(xs, ys, xe, ye, xRight, &xi, &yi);
				else if (out2.top)HIntersect(xs, ys, xe, ye, yTop, &xi, &yi);
				else if (out2.bottom)HIntersect(xs, ys, xe, ye, yBottom, &xi, &yi);
				xe = xi;
				ye = yi;
				out2 = GetOutCode(xe, ye, xLeft, yTop, xRight, yBottom);
			}
		}
	}
	if (accept) {
		MoveToEx(hdc, round(xs), round(ys), NULL);
		LineTo(hdc, round(xe), round(ye));
	}
}
