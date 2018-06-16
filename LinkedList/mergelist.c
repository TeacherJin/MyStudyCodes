/*
使用链表将两个有序链表归并
但会导致这两个链表的结构发生变化
*/
#include "linklist.h"

int main(int argc, char const *argv[])
{
    //创建两个有序链表LA和LB，这里由用户保证升序，不涉及排序问题
    printf("输入第一个有序链表各节点的值：\n");
    LinkList LA = LinkListCreate(3);
    printf("输入第二个有序链表各节点的值：\n");
    LinkList LB = LinkListCreate(5);
    //创建空链表LC，用于访问归并后的链表
    LinkList LC;
    //pa,pa指向待比较的链表中的节点
    LinkList pa = LA;
    LinkList pb = LB;
    LinkList pc;
    //LC指向LA和LB中第一个节点值较小的那个节点
    if (pa->data <= pb->data)
    {
        LC=pc=pa;
        pa=pa->next;
    }else{
        LC=pc=pb;
        pb=pb->next;
    }
    //如果pa和pb都不为空
    while (pa && pb)
    {
        //比较两个指针所指向节点的值
        if (pa->data <= pb->data)
        {
            //pc指向的节点连接到pa上
            pc->next=pa;
            //pc指向pa
            pc=pa;
            //pa指向LA中下一个节点
            pa=pa->next;
        }else{
            //pc指向的节点连接到pb上
            pc->next=pb;
            //pc指向pb
            pc=pb;
            //pb指向LB中下一个节点
            pb=pb->next;
        }
    }
    //当一个链表中的数据处理完毕后，直接将另一个链表中的数据挂在LC上即可
    pc->next=pa?pa:pb;
    printf("输出排序后的链表：\n");
    LinkListPrint(LC);
    printf("输出第一个链表：\n");
    LinkListPrint(LA);
    printf("输出第二个链表：\n");
    LinkListPrint(LB);
    return 0;
}
