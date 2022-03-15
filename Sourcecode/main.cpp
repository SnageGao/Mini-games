#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>

#include "Point.h"
#include "Tetris.h"
#include "Snake.h"

using namespace std;


int main(){
    char key;
    system("chcp 65001 > nul");

    while(1){
        system("cls");
        printf("游戏说明：\n  按“1”:俄罗斯方块\n  按“2”:贪吃蛇\n  按“Esc”以结束程序\n\n");
        key= getch();
        fflush(stdin);
        printf("%d\n",key);
        switch(key){
            case 49: {Tetris();	break;}
                //"1.俄罗斯方块"
            case 50: {Snake();	break;}
                //"2.贪吃蛇"
            case 27: return 0;
                //"Esc"
            default: break;
        }
    }
}
