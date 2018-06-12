/*
合并两个线性表，并去掉重复元素
*/
#include "sqlist.h"

int main(int argc, char const *argv[])
{
    //两个数组，用于初始化线性表
    int a[]={3, 5, 8, 11}; 
    int b[]={2, 6, 8, 9, 11, 15, 20};
    //线性表LA、LB，用数组a和b初始化，然后存入到线性表LC中
    //只有LA和LB也行，两个线性表拼接即可，算法相同
    SqList LA;
    SqList *PLA=&LA;
    InitListSqByArray(PLA,a,4);

    SqList LB;
    SqList *PLB=&LB;
    InitListSqByArray(PLB,b,7);
    
    SqList LC;
    SqList *PLC=&LC;
    InitListSq(PLC);

    int i,j;
    //把LA的元素插入到LC中
    for(i=1;i<=LA.length;i++){
        ListInsertSq(PLC,i,*(LA.elem+i-1));
    }
    //把LB的元素插入到LC中，避免和现有元素重复
    for(j=1;j<=LB.length;j++){
        if(!(LocateElemSq(PLC,*(LB.elem+j-1)))){
            ListInsertSq(PLC,i,*(LB.elem+j-1));
            i++;
        }
    }
    //打印线性表中的元素
    ListPrintSq(PLC);
    printf("LC中元素的个数是：%d\n",LC.length);
    return 0;
}
