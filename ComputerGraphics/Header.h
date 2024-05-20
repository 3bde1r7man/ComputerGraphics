#pragma once
#include <Windows.h>
#include <math.h>


// Circle
LRESULT WINAPI Circle(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);
void draw8points(HDC hdc, int x, int y, int xc, int yc);
void CircleDirect(HDC hdc, int xc, int yc, int R);
void CirclePolar(HDC hdc, int xc, int yc, int R);
void CircleBresenham(HDC hdc, int xc, int yc, int r);

// Line
LRESULT WINAPI Line(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);
void swap(int& x1, int& x2, int& y1, int& y2);
void SimpleDDA(HDC hdc, int Xs, int Ys, int Xe, int Ye);
void NaiveLine(HDC hdc, int Xs, int Ys, int Xe, int Ye);
void BresenhamLine(HDC hdc, int x1, int y1, int x2, int y2);

// MAIN FUNCTION
int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns);
