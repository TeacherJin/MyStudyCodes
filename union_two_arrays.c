/*
将两个线性表（这里用两个不含0的数组表示）合并，并去掉重复元素
*/
#include <stdio.h>
//声明在数组中查找元素的方法
int getElem(int a[],int LenA,int x);
int main(int argc, char const *argv[])
{
    int LA[]={3,5,8,11};//数组LA，第一个线性表
    int LenA=4;//数组LA的长度
    int LB[]={2,6,8,9,11,15,20};//数组LB，第二个线性表
    int LenB=7;//数组LB的长度
    int LC[11]={0};//数组LC，存放LA和LB合并后的数据
    int index;//循环中的LA或LB 的下标
    int indexC=0;//记录LC中下标的变化
    //将LA中的元素添加到LC中
    for(index=0;index<LenA;index++){
        LC[index]=LA[index];
        indexC++;
    }
    //将LB中的元素添加到LC中，但不添加LA中已经存在的元素
    for(index=0;index<LenB;index++){
        if(getElem(LA,LenA,LB[index])==-1){
            LC[indexC++]=LB[index];
        }
    }
    //显示LC中的元素
    for(index=0;index<indexC;index++){
        printf("LB[%d]=%d\n",index,LC[index]);
    }
    return 0;
}
/*a为待检测数组，LenA为数组a的长度，x为要查找的元素，找得到返回索引，找不到返回-1*/
int getElem(int a[],int LenA,int x){

    int index=0;

    for(;index<LenA;index++){
        if(x==a[index]){
            return index;
        }
    }
    return -1;
}
