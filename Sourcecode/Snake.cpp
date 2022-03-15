#include "snake.h"



//=====================================================================================================================================
int Snake(){
    printf("游戏说明：\n  按“R”以开始或重置游戏，按“Esc”以退出游戏\n  按“A”“D”“W”“S”以控制方向\n  按“Space”以移动\n\n");
    Snake_struct snake;
    Snake_Reset(&snake);

    char key;
    while(1){
        key=getch();
        fflush(stdin);

        switch(key){
            case K_R:   {Snake_Reset(&snake);	break;}
                //"R"
            case K_W:
            case K_Up:  {snake.dect = (snake.dect==Down)? Down: Up;	break;}
                //"up"
            case K_S:
            case K_Dn:  {snake.dect = (snake.dect==Up)? Up: Down;	break;}
                //"down"
            case K_D:
            case K_Rt:  {snake.dect = (snake.dect==Left)? Left: Right;	break;}
                //"right"
            case K_A:
            case K_Lt:  {snake.dect = (snake.dect==Right)? Right: Left;	break;}
                //"left"

            case K_Sp:  {Snake_Move (&snake);	break;}
                //"Space"         //ʱ���ж�
            case K_Ec: return 0;
                //"Esc"
            default: break;
        }
        Snake_print(&snake);
    }
}


int Snake_Reset(Snake_struct *snake){
    for(int i=0;i<Hight;i++){
        for(int j=0;j<Width;j++){
            snake->matrix[i][j]= 0;
        }
    }

    snake->body[0] = {(int)Hight/2,(int)Width/2};
    snake->headi = snake->taili = 0;
    snake->die = 0;
    snake->dect = Up;
    snake->length = 1;
    snake->matrix[ snake->body[snake->headi].Y][ snake->body[snake->headi].X] = 1;

    Snake_new( snake);
}


//=====================================================================================================================================
int Snake_Move (Snake_struct *snake){
    if(snake->die) return 0;

    //---Nextaddr Part---------------------------------------------------------------
    Point next;
    next = P_move(snake->body[snake->headi],snake->dect);
    
    //---Decision Part---------------------------------------------------------------
    if(snake->length == Hight*Width-1) snake->die = 2;                                              //win
    else if(snake->die = ( snake->matrix[next.Y][next.X]==1&& !P_comp(snake->body[snake->taili],next))      //eat self
                      || ( next.Y<0|| next.Y>=Hight|| next.X<0|| next.X>=Width)|| snake->die);            //hit wall


    //---Movement Part---------------------------------------------------------------
    else switch(snake->matrix[next.Y][next.X]){
            case 1:
            case 0:{                          //normal movement
                snake->matrix[snake->body[snake->taili].Y][snake->body[snake->taili].X] = 0;
                snake->matrix[next.Y][next.X] = 1;

                snake->headi= (snake->headi==Hight*Width-1)? 0: snake->headi+1;
                snake->taili= (snake->headi==Hight*Width-1)? 0: snake->taili+1;
                snake->body[snake->headi] = next;

                break;
            }

            case 2:{                          //food eating
                snake->matrix[next.Y][next.X] = 1;

                snake->headi= (snake->headi==Hight*Width-1)? 0: snake->headi+1;
                snake->body[snake->headi] = next;
                snake->length += 1;

                Snake_new(snake);

                break;
            }
            default: break;
        }
}

///-------------------------------------------
int Snake_new(Snake_struct *snake){
    srand((unsigned)time(NULL));
    while(1){
        snake->food = {rand()%Hight,rand()%Width};
        if(!snake->matrix[snake->food.Y][snake->food.X]) break;
    }
    snake->matrix[snake->food.Y][snake->food.X] = 2;

    return 0;
}


//=================================================================
int Snake_print(Snake_struct *snake){
    Xprint( snake->matrix, snake->die, snake->length);

    return 0;
}