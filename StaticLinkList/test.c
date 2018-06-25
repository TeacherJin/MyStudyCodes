#include "StaticLinkList.h"

int main(int argc, char const *argv[])
{
    SLinkList SL;
    InitSL(SL);
    int start = MallocSL(SL);
    int r = start;
    for (int i = 1; i < 5; i++)
    {
        SL[r].data = i * i;
        r = SL[r].cur;
    }
    SL[r].cur = 0;

    int t = start;
    int k;
    k = SL[t].cur;
    while (k != SL[r].cur && SL[k].data != 9)
    {
        t = k;
        k = SL[k].cur;
    }

    SL[t].cur = SL[k].cur;
    FreeSL(SL, k);

    int s = start;
    while (SL[s].cur)
    {
        printf("%d\n", SL[s].data);
        s = SL[s].cur;
    }
    return 0;
}
