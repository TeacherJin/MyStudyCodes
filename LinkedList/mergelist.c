#include "linklist.h"

int main(int argc, char const *argv[])
{
    LNode LA,LB,LC;
    LinkList La,Lb,Lc;
    La=&LA;
    Lb=&LB;
    Lc=&LC;
    printf("现在开始初始化第1个链表\n");
    //InitLinkList(&LA);
    CreateLinkList(La,3);
    printf("现在开始初始化第2个链表\n");
    //InitLinkList(&LB);
    CreateLinkList(Lb,3);
    MergeLinkList(La,Lb,Lc);
    printf("输出合并后的链表\n");
    PrintLinkList(&LA);
    return 0;

}