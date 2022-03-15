#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H


#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>

#include"Point.h"
#include"Xprint.h"

const Point PreShape[7][3] = {
        {{0,1}, {0,-1}, {0,-2}},
        {{-1,1}, {0,1}, {1,0}},
        {{1,1}, {0,1}, {-1,0}},
        {{0,1}, {1,0}, {-1,0}},
        {{-1,1}, {-1,0}, {0,1}},
        {{1,1}, {0,1}, {0,-1}},
        {{-1,1}, {0,1}, {0,-1}}
};

typedef struct{
    int matrix[Hight+4][Width];   //����
    Point locat;       	//λ��
    Point shape[3];     //
    Point form[4];

    int score;        //����
    int die;        //����
}Tetris_struct;




//-------------------------------------------------------------
int Tetris();

//--------------------------------------------------------------------------
int Tetris_reset( Tetris_struct* tetris);
int Tetris_op( Tetris_struct* tetris, int op);

//--------------------------------------------------------------------------
int Tetris_impact( Tetris_struct* tetris, Point* form);
int Tetris_new( Tetris_struct* tetris);
//----------------------------------------------------------------------------
int Tetris_print( Tetris_struct* tetris);

#endif //TETRIS_TETRIS_H
