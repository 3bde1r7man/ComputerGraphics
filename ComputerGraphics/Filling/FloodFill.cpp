#include "../Header.h"
#include <queue>



struct Point
{
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

void nonRecursiveFloodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF borderColor)
{
	queue<Point> q;
	q.push(Point(x, y));
	while (!q.empty())
	{
		Point p = q.front();
		q.pop();
		COLORREF color = GetPixel(hdc, p.x, p.y);
		if(color == borderColor || color == fillColor)
			continue;
		SetPixel(hdc, p.x, p.y, fillColor);
		q.push(Point(p.x + 1, p.y));
		q.push(Point(p.x - 1, p.y));
		q.push(Point(p.x, p.y + 1));
		q.push(Point(p.x, p.y - 1));
	}

}

