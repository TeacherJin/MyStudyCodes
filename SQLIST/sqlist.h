#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1      //infeasible:不可实行的;
#define OVERFLOW -2        //overflow:溢出
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量

typedef int Status;

typedef struct
{
    int *elem;    //这里用整型数据表示数据元素，elem表示存储空间基址
    int length;   //当前线性表长度
    int listsize; //当前分配的存储容量
} SqList;
//初始化一个线性表，空的
Status InitListSq(SqList *L)
{
    L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    //分配空间失败时的处理
    if (!L->elem)
    {
        exit(OVERFLOW);
    }
    L->length = 0;                //初始长度为0，实际元素个数
    L->listsize = LIST_INIT_SIZE; //当前分配的存储容量，单位是元素个数
    return OK;
}
//使用数组初始化一个线性表,L为待初始化线性表，a为数组，al为数组长度
//将数组a中索引为0到al（不包含al）的元素存放到线性表L中
Status InitListSqByArray(SqList *L,int a[],int al){
    int maxsize=al>LIST_INIT_SIZE?al:LIST_INIT_SIZE;
    L->elem = (int *)malloc(maxsize * sizeof(int));
       
    //分配空间失败时的处理
    if (!L->elem)
    {
        exit(OVERFLOW);
    }
    L->length = 0;                //初始长度为0，实际元素个数
    L->listsize = maxsize; //当前分配的存储容量，单位是元素个数
    for(int i=0;i<al;i++){
        *(L->elem+i)=a[i];
        (L->length)++;
    }
    return OK;
}
//向一个线性表L中的索引为i的位置插入数据e，即现有索引为i的元素的前面
//这里索引从1开始，正好和线性表长度匹配
Status ListInsertSq(SqList *L, int i, int e)
{
    //判断i的合法性，i应该大于等于1且小于等于现有长度+1
    if (i < 1 || i > L->length + 1)
        return ERROR;
    //判断存储空间是否已满
    if (L->length >= L->listsize)
    {
        int *newbase = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
        //判断是否分配成功，这是因为如果分配失败，就会返回NULL,所以不能直接把
        //重新分配的返回值赋值给elem
        if (!newbase)
        {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        //改变L的存储容量大小
        L->listsize += LISTINCREMENT;
    }
    int *q = L->elem + i - 1;         //新元素的插入位置
    int *p = L->elem + L->length - 1; //最后一个元素的地址
    for (; p >= q; p--)
    {
        *(p + 1) = *p; //插入位置之后的元素向后移动一个位置
    }
    *q = e; //插入e
    L->length++;
    return OK;
}
//删除线性表L中索引为i的元素e
Status ListDeleteSq(SqList *L, int i, int e)
{
    //判断i的合法性，i应该大于等于1且小于等于现有长度
    if (i < 1 || i > L->length)
        return ERROR;

    int *p = L->elem + i - 1;         //被删除元素的地址
    e = *p;                           //如果单纯删除i号元素，这行无意义;除非是想知道删掉的元素值
    int *q = L->elem + L->length - 1; //最后一个元素的位置
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p; //元素前移
    }
    L->length--;
    return OK;
}
//取出线性表中索引为i的元素
Status ListGetSq(SqList *L, int i)
{
    //判断i的合法性，i应该大于等于1且小于等于现有长度
    if (i < 1 || i > L->length)
        return ERROR;

    return *(L->elem + i - 1);
}
//在线性表中查找一个元素e，存在则返回其索引，不存在返回ERROR
int LocateElemSq(SqList *L,int e){
    int index=1;
    for(;index<=L->length;index++){
        if(e==*(L->elem+index-1)){
            break;
        }
    }
    if(index<=L->length){
        return index;
    }else{
        return ERROR;
    }
}

//输出一个线性表中的所有元素
void ListPrintSq(SqList *L){
    for(int i=1;i<=L->length;i++){
        printf("%d\n",*(L->elem+i-1));
    }
}