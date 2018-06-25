#include "StaticLinkList.h"

int main(int argc, char const *argv[])
{
    //创建一个静态链表SL，并初始化，此时所有的节点均在备用链表中
    SLinkList SL;
    InitSL(SL);
    //申请第一个节点，位置保存在start中
    int start = MallocSL(SL);
    int r = start;
    //int t = start;
    //输入两个链表中元素的个数
    int a, b;
    printf("输入第1个链表中元素的个数：\n");
    scanf("%d", &a);
    printf("输入第2个链表中元素的个数：\n");
    scanf("%d", &b);
    //建立链表A
    int index;
    for (int i = 0; i < a; i++)
    {
        //index = MallocSL(SL);
        printf("请输入链表A第%d个元素：\n", i + 1);
        scanf("%d", &SL[r].data);
        r=SL[r].cur;
    }
    SL[r].cur = 0; //尾节点的指针为0,表示为空
   
    //插入链表B的节点，如果已经存在则删除，如果不存在则插入
    int temp; //临时存储输入的链表B的一个节点的值
    //tIndex表示表示该元素的位置，k表示该元素的前一个元素的位置
    int tIndex, k; //检测一个值是否已经存在于链表A中的查询结果，存在则保存其下标，不存在则为0

    for (int i = 0; i < b; i++)
    {
        printf("请输入链表B第%d个元素：\n", i + 1);
        scanf("%d", &temp);
        tIndex = start;
        k = SL[tIndex].cur;
        while (k != SL[r].cur && SL[k].data != temp)
        {
            tIndex = k;
            k = SL[k].cur;
        }

        if (k != SL[r].cur)  //该元素存在，删除
        {
            SL[tIndex].cur = SL[k].cur;
            FreeSL(SL, k);
            if (r == k)
                r = tIndex;
        }
        else
        { //该元素不存在
            index = MallocSL(SL);
            SL[index].data = temp;
            SL[index].cur = SL[r].cur; //新元素放到原链表的结尾
            SL[r].cur = index;
        }
    }
    SL[r].cur=0; //为最后一个节点添加结束标志
    int x=start;
    while(SL[x].cur){
        printf("%d\n",SL[x].data);
        x=SL[x].cur;
    }
    return 0;
}
