
#ifndef TETRIS_SNAKE_H
#define TETRIS_SNAKE_H

#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>

#include"Point.h"
#include"Xprint.h"

typedef struct{
    int matrix[Hight][Width];   //����
    Point body[Hight*Width];       	//λ��
    int headi;
    int taili;
    int dect;
    Point food;

    int length;        //����
    int die;            //����
}Snake_struct;





//=====================================================================================================================================
int Snake();
//=====================================================================================================================================
int Snake_Move (Snake_struct* snake);
int Snake_Reset(Snake_struct* snake);
int Snake_new(Snake_struct* snake);
int Snake_print(Snake_struct *snake);



#endif //TETRIS_SNAKE_H
