#include "../Header.h"

void SimpleDDA(HDC hdc, int Xs, int Ys, int Xe, int Ye) {
    int dx = Xe - Xs;
    int dy = Ye - Ys;
    SetPixel(hdc, Xs, Ys, RGB(0, 0, 0));
    if(abs(dx) >= abs(dy)){
        int x= Xs, xinc = dx > 0 ? 1 : -1;
        double y = Ys, yinc = (double)dy / dx * xinc;
        while(x != Xe){
            x += xinc;
            y += yinc;
            SetPixel(hdc, x, round(y), RGB(0, 0, 0));
        }
    }else {
        int y = Ys, yinc = dy > 0 ? 1 : -1;
        double x = Xs, xinc = (double)dx / dy * yinc;
        while(y != Ye){
            y += yinc;
            x += xinc;
            SetPixel(hdc, round(x), y, RGB(0, 0, 0));
        }
    }
}