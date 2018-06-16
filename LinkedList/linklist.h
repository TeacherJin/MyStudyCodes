/*
本文件夹中的链表和书上的不同
书上的链表有一个头节点，不存储数据，仅用于指向后续节点
但本程序中的链表的第一个节点即可存储数据
*/
#include "def.h"
#include <stdlib.h>
#include <stdio.h>

//链表节点的数据结构
typedef struct LNode
{
	int data;			//节点中的数据，用整型表示
	struct LNode *next; //指向下一个节点
} LNode, *LinkList;

//在链表中插入一个节点，在头指针为L的链表的第i个节点前，插入数据e，生成一个新节点
Status LinkListInsert(LinkList L, int i, int e)
{
	int j = 0;
	//LinkList p = L;
	//将指针p指向第i-1号元素
	while (L && j < i - 1)
	{
		L = L->next;
		j++;
	}
	//判断i的位置是否合法，如果i超过了链表长度或小于1，均报错
	if (!L || j > i - 1)
	{
		return ERROR;
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));
	//分配失败的处理
	if (!s)
	{
		exit(OVERFLOW);
	}
	s->data = e;	   //将数据e存入新节点s
	s->next = L->next; //s节点的下一个节点地址指向原来i-1号节点的下一个节点地址
	L->next = s;
	//原来i-1号节点的下一个节点地址指向s
	return OK;
}

//从链表中删除一个节点，删除头指针为L的链表的第i个节点，其值赋给变量e
Status LinkListDelete(LinkList L, int i, int *e)
{
	int j = 0;
	LinkList p = L;
	//将指针p指向第i-1号元素
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	//判断i的位置是否合法，如果i超过了链表长度或小于1，均报错
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	LinkList q;		   //用于存储i号节点的指针，也就是即将删除的节点的指针
	q = p->next;	   //获取i号节点的指针
	p->next = q->next; //将p的next指针值改为即将删除的节点的next指针值，即i+1号节点的位置。如果i为最后一个节点，则为NULL
	*e = q->data;	  //将i号节点的值存入指针e对应的变量空间
	free(q);		   //释放i号节点的存储空间
	return OK;
}

//通过输入创建一个链表，包含i个节点，返回该链表的头指针
LinkList LinkListCreate(int i)
{
	LinkList L = NULL;
	LinkList p1, p2;
	for (int j = 1; j <= i; j++)
	{
		p1 = (LinkList)malloc(sizeof(LNode));
		if (!p1)
		{
			exit(OVERFLOW);
		}
		printf("请输入第%d个整数：", j);
		scanf("%d", &(p1->data));
		if(!L){
			L=p1;  //如果L为空链表，则将L指向p1对应的节点
			p1->next=NULL;  //p1节点的next项指向的地址为空
			p2=p1;  //p2指向p1节点 
		}else{
			p2->next=p1;  //p2节点指向p1节点
			p1->next=NULL;  //p1节点指向空地址
			p2=p1;  //p2指向p1节点 
		}
	}

	return L;
}

//打印链表中所有的节点的值，L是链表的头指针
void LinkListPrint(LinkList L)
{
	//i为计数器，表示正在输出第几个节点的值
	int i = 1;
	//如果L为空，表明要么是空链表，要么到了链表结尾，均停止输出
	while (L)
	{
		//L->data表示L指向的节点的data项
		printf("第%d个节点的值是%d\n", i, L->data);
		//跳到下一个节点
		L = L->next;
		i++;
	}
}
