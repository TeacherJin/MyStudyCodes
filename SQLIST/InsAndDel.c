#include <stdio.h>
#include "sqlist.h"


int main(int argc, char const *argv[])
{
    SqList L;
    int e;
    SqList *PL=&L;
    InitListSq(PL);
    ListInsertSq(PL,1,5);
    for(int i=1;i<11;i++){
        ListInsertSq(PL,i,i*3);
    }
    ListDeleteSq(PL,5,e);
    for(int i=1;i<=L.length;i++){
        printf("%d\n",ListGetSq(PL,i));
    }
    return 0;
}
