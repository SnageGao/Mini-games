#include "Xprint.h"

int Xprint( int board[Hight][Width], int die, int score){

    system("cls");
    for(int i=0;i<Width+9;i++) printf("--");
    printf("\n");
    for(int i=Hight-1;i>=0;i--){
        printf("|");
        for(int j=0;j<Width;j++){
            if(board[i][j]) printf("■");
            else printf("□");
        }
        if(i==Hight-3)              printf("|  score：%04d  |\n",score);
        else if(i==Hight-7&&!die)   printf("|   Come  on!   |\n");
        else if(i==Hight-7&& die)   printf("|   You  lose   |\n");
        else if(i==2)               printf("|   Design by   |\n");
        else if(i==1)               printf("|    Snage G    |\n");
        else                        printf("|               |\n");
    }
    for(int i=0;i<Width+8;i++) printf("--");
    printf("\n");

    return 0;
}

