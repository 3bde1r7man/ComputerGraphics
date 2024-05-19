#pragma once
#include <Windows.h>
#include <math.h>


void swap(int& x1, int& x2, int& y1, int& y2);

// Path: ComputerGraphics/MidpointLine.cpp
LRESULT WINAPI MidpointLine(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);

// Path: ComputerGraphics/circle.cpp
LRESULT WINAPI Circle(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);

// Path: ComputerGraphics/main.cpp
int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns);
