#include "def.h"
#include <stdio.h>
#include <stdlib.h>

//单链表的节点的数据结构
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//向一个链表中插入一个节点，将数据e插入到链表H的第i个位置上，H为头指针
Status LinkListInsert(LinkList H, int i, int e)
{
    LinkList p = H;
    int j = 1;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//通过输入数据初始化一个链表，H表示头指针
Status InitLinkList(LinkList H)
{
    int i=0;
    LinkList p=H;
    while(i!=-1){
        printf("请输入一个整数，输入-1表示结束");
        scanf("%d",&i);
        LinkList s = (LinkList)malloc(sizeof(LNode));
        s->data=i;
        s->next=NULL;
        p->next=s;
        p=s;

    }
}
//打印一个链表
Status PrintLinkList(LinkList H){
    LinkList p=H;
    int i=1;
    while(p->next!=NULL){
        printf("链表的第%d个节点的值是：%d\n",i++,p->data);
        p=p->next;
    }
}
