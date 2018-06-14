#include "def.h"
#include <stdlib.h>
#include <stdio.h>

//链表节点的数据结构
typedef struct LNode
{
	int data;  //节点中的数据，用整型表示
	struct LNode *next;  //指向下一个节点
}LNode,*LinkList;

//在链表中插入一个节点，在头指针为L的链表的第i个节点前，插入数据e，生成一个新节点
Status LinkListInsert(LinkList L,int i,int e){
	int j=0;
	LinkList p=L;
	//将指针p指向第i-1号元素
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	//判断i的位置是否合法，如果i超过了链表长度或小于1，均报错
	if(!p || j>i-1){
		return ERROR;
	}
	LinkList s=(LinkList)malloc(sizeof(LNode));
	//分配失败的处理
	if(!s){
		exit(OVERFLOW);
	}
	s->data=e;  //将数据e存入新节点s
	s->next=p->next;//s节点的下一个节点地址指向原来i-1号节点的下一个节点地址
	p->next=s;//原来i-1号节点的下一个节点地址指向s
	return OK;
}

//从链表中删除一个节点，删除头指针为L的链表的第i个节点，其值赋给变量e
Status LinkListDelete(LinkList L,int i,int *e){
	int j=0;
	LinkList p=L;
	//将指针p指向第i-1号元素
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	//判断i的位置是否合法，如果i超过了链表长度或小于1，均报错
	if(!p || j>i-1){
		return ERROR;
	}
	LinkList q;  //用于存储i号节点的指针，也就是即将删除的节点的指针
	q=p->next;  //获取i号节点的指针
	p->next=q->next;  //将p的next指针值改为即将删除的节点的next指针值，即i+1号节点的位置。如果i为最后一个节点，则为NULL
	*e=q->data;  //将i号节点的值存入指针e对应的变量空间
	free(q);  //释放i号节点的存储空间
	return OK;
}

//打印链表中所有的节点的值，L是链表的头指针
void LinkListPrint(LinkList L){
	while(L->next){
		printf("%d\n",L->next->data);
		L=L->next;
	}
}
