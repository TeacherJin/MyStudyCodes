#include "def.h"
#include <stdio.h>
#define MAXSIZE 1000  //链表的最大长度

typedef struct{
    int data;  //数据部分
    int cur;  //下一个节点的数组下标
}component,SLinkList[MAXSIZE];  //component,成分，元件

//在链表S中查找第一个值为e的元素，并返回其下标；找不到则返回0
int LocateSL(SLinkList S,int e){
    int index=S[0].cur;
    while(index && S[index].data!=e){
        index=S[index].cur;
    }
    return index;
}
//将sl中所有的节点组合成备用链表，表示未使用的所有节点的集合
void InitSL(SLinkList sl){
    for (int i=0;i<MAXSIZE-1;i++){
        sl[i].cur=i+1;
    }
    sl[MAXSIZE-1].cur=0;
}

//分配空间，如果备用链表非空，返回分配的节点下标，否则返回0
//每次都取下下标为1的节点
int MallocSL(SLinkList sl){
    int index=sl[0].cur;
    if(sl[0].cur){
        sl[0].cur=sl[index].cur;
    }
    return index;
}

//释放一个节点，其下标为k，将释放的节点挂到第一个元素的后面
void FreeSL(SLinkList sl,int k){
    sl[k].cur=sl[0].cur;
    sl[0].cur=k;
}

//删除一个节点，删除下标为index的节点，并释放
/*
Status DELETESL(SLinkList SL,int index){

}
*/