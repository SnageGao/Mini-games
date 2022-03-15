#include"Tetris.h"

//-------------------------------------------------------------
int Tetris(){
    printf("游戏说明：\n  按“R”以开始或重置游戏，按“Esc”以退出游戏\n  按“A”“D”以平移方块\n  按“S”“Space”以下落方块\n  按“W”以旋转方块\n\n");
    Tetris_struct tetris;
    Tetris_reset( &tetris);

    char key;
    while(1){
        key= getch();
        fflush(stdin);

        switch(key){
            case K_R:{Tetris_reset( &tetris);	break;}
                //"R"
            case K_Up:
            case K_W: {Tetris_op( &tetris, Up);	break;}
                //"up"
            case K_Rt:
            case K_D: {Tetris_op( &tetris, Right);	break;}
                //"right"
            case K_Lt:
            case K_A: {Tetris_op( &tetris, Left);	break;}
                //"left"
            case K_Sp:
                //"Space"         //ʱ���ж�
            case K_Dn:
            case K_S: {Tetris_op( &tetris, Down);	break;}
                //"down"
            case K_Ec: return 0;
                //"Esc"
            default: break;
        }
        Tetris_print( &tetris);
    }
}

//--------------------------------------------------------------------------
int Tetris_reset( Tetris_struct* tetris){
    for(int i=0;i<Hight+4;i++){
        for(int j=0;j<Width;j++){
            tetris->matrix[i][j]= 0;
        }
    }
    tetris->score = 0;
    tetris->die = 0;
    tetris->locat = P0;
    tetris->shape[0] = P0;
    tetris->shape[1] = P0;
    tetris->shape[2] = P0;

    Tetris_new( tetris);
    return 0;
}

int Tetris_op( Tetris_struct* tetris, int op){
    if(tetris->die==1) return 0;

    Point tempL;
    Point tempS[3];
    Point tempF[4];

    if(op==Up) {
        tempL = tetris->locat;
        for(int i=0;i<3;i++) tempS[i]=P_spin(tetris->shape[i]);
    }
    else{
        tempL = P_move( tetris->locat, op);
        for(int i=0;i<3;i++) tempS[i]=tetris->shape[i];
    }
    tempF[0] = tempL;
    for(int i=1;i<4;i++) tempF[i]=P_plus(tempL,tempS[i-1]);

    int impact;
    impact = Tetris_impact( tetris, tempF);

    if(op==Down){
        switch(impact){
            case 0:{
                tetris->locat = tempL;
                for(int i=0;i<3;i++) tetris->shape[i]=tempS[i];
                for(int i=0;i<4;i++) tetris->form[i]=tempF[i];
                break;
            }
            case 1:{
                Point* pf;
                pf = tetris->form;
                for(int i=0;i<4;i++) tetris->matrix[pf[i].Y][pf[i].X]=1;

                Tetris_new( tetris);
                break;
            }
            case 2:{
                tetris->die=1;
                break;
            }
            default:	break;
        }
    }
    else{
        if(impact==0){
            tetris->locat = tempL;
            for(int i=0;i<3;i++) tetris->shape[i]=tempS[i];
            for(int i=0;i<4;i++) tetris->form[i]=tempF[i];
        }
        else{

        }
    }

    return 0;
}

//--------------------------------------------------------------------------
int Tetris_impact( Tetris_struct* tetris, Point* form){
    int impact;
    int isout, isimp, istop;

    isout = 0;
    for(int i=0;i<4;i++) isout += ( form[i].X<0 || form[i].X>Width-1 || form[i].Y<0);
    isimp = 0;
    for(int i=0;i<4;i++) isimp += ( tetris->matrix[form[i].Y][form[i].X]);
    istop = 0;
    for(int i=0;i<4;i++) istop += ( form[i].Y > Hight-1);

    impact = (isout||isimp)? (istop?2:1): 0;

    return impact;
}

int Tetris_new( Tetris_struct* tetris){
    for(int i=Hight-1;i>=0;i--){
        int sum=0;
        for(int j=0;j<Width;j++) sum+=tetris->matrix[i][j];
        if(sum==Width){
            tetris->score++;
            for(int k=i;k<Hight-1;k++)
                for(int m=0;m<Width;m++)
                    tetris->matrix[k][m]=tetris->matrix[k+1][m];
            for(int m=0;m<Width;m++)
                tetris->matrix[Hight-1][m]=0;
        }
    }

    int R1,R2;
    srand((unsigned)time(NULL));
    R1 = rand()%7; R2 = rand()%4;

    tetris->locat = {Hight+1,(int)(Width/2-0.5)};
    tetris->form[0] = {Hight+1,(int)(Width/2-0.5)};
    for(int i=0;i<3;i++){
        tetris->shape[i] = PreShape[R1][i];
        for(int j=0;j<R2;j++){
            tetris->shape[i] = P_spin(tetris->shape[i]);
            tetris->form[i+1] = P_plus(tetris->locat,tetris->shape[i]);
        }
    }

    return 0;
}
//-------------------------------------------------------------
int Tetris_print( Tetris_struct* tetris){
    int board[Hight][Width];
    for(int i=0;i<Hight;i++){
        for(int j=0;j<Width;j++){
            board[i][j] = tetris->matrix[i][j];
        }
    }
    Point* pf;
    pf = tetris->form;
    for(int i=0;i<4;i++) if(pf[i].Y<Hight) board[pf[i].Y][pf[i].X]=1;

    Xprint( board, tetris->die, tetris->score);

    return 0;
}

