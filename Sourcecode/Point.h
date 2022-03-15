#ifndef TETRIS_POINT_H
#define TETRIS_POINT_H

struct Point{
    int Y;
    int X;
};

const Point P0 = {0,0};

const int Right	= 1;
const int Left 	= 2;
const int Up 	= 3;
const int Down 	= 4;

const char K_Up = 72;
const char K_Dn = 80;
const char K_Lt = 75;
const char K_Rt = 77;

const char K_W = 119;
const char K_S = 115;
const char K_A = 97;
const char K_D = 100;

const char K_R = 114;
const char K_Sp = 32;
const char K_Ec = 27;

Point P_plus( Point P1, Point P2);
Point P_spin( Point P1);
Point P_move( Point L, int op);
int P_comp( Point P1, Point P2);



#endif //TETRIS_POINT_H
