#include <stdio.h>
#include <stdlib.h>

//链表节点的数据结构
typedef struct LNode
{
	int data;  //节点中的数据，用整型表示
	struct LNode *next;  //指向下一个节点
}LNode,*LinkList;


int main(int argc, char const *argv[])
{
	LinkList s=(LinkList)malloc(sizeof(LNode));
	printf("%d\n",s);
	printf("NULL=%d\n",NULL);
	return 0;
}
