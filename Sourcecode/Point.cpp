#include"Point.h"

Point P_plus( Point P1, Point P2){
    Point R;
    R.X = P1.X+ P2.X;
    R.Y = P1.Y+ P2.Y;
    return R;
}

Point P_spin( Point P1){
    Point R;
    R.X = P1.Y;
    R.Y = -(P1.X);
    return R;
}

Point P_move( Point L, int op){
    Point R = L;
    switch(op){
        case Right	:{ R.X = L.X+1;	break;	}
        case Left 	:{ R.X = L.X-1;	break;	}
        case Up 	:{ R.Y = L.Y+1; break;	}
        case Down 	:{ R.Y = L.Y-1;	break;	}
        default:	break;
    }
    return R;
}

int P_comp( Point P1, Point P2){
    return (P1.Y==P2.Y)&&(P1.X==P2.X);
}
