#pragma once
#include <Windows.h>
#include <math.h>

// Path: ComputerGraphics/line.cpp
LRESULT WINAPI Line(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);

// Path: ComputerGraphics/circle.cpp
LRESULT WINAPI Circle(HWND hwnd, UINT m, WPARAM wp, LPARAM lp);

// Path: ComputerGraphics/main.cpp
int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns);
