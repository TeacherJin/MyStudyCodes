/*
将两个已排序的线性表（这里用两个不含0的数组表示）合并，不去掉重复元素
合并后的线性表仍然是排序的
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int LA[] = {3, 5, 8, 11};            //数组LA，第一个线性表
    int LenA = 4;                        //数组LA的长度
    int LB[] = {2, 6, 8, 9, 11, 15, 20}; //数组LB，第二个线性表
    int LenB = 7;                        //数组LB的长度
    int LC[11] = {0};                    //数组LC，存放LA和LB合并后的数据
    int LenC = 11;                       //数组LC的长度
    int indexA = 0;                      //记录LA中下标的变化
    int indexB = 0;                      //记录LB中下标的变化
    int indexC = 0;                      //记录LC中下标的变化
    //将LA和LB中的元素添加到LC中，直到一个数组中的所有元素被添加完为止
    while ((indexA < LenA) && (indexB < LenB))
    {
        if (LA[indexA] < LB[indexB])
        {
            LC[indexC] = LA[indexA];
            indexA++;
            indexC++;
        }
        else
        {
            LC[indexC] = LB[indexB];
            indexB++;
            indexC++;
        }
    }
    //将LA或LB（剩下的那个数组）添加到LC中
    while (indexA < LenA)
    {
        LC[indexC] = LA[indexA];
        indexA++;
        indexC++;
    }
    while (indexB < LenB)
    {
        LC[indexC] = LB[indexB];
        indexB++;
        indexC++;
    }
    //显示LC中的元素
    for (int index = 0; index < indexC; index++)
    {
        printf("LB[%d]=%d\n", index, LC[index]);
    }
    return 0;
}
