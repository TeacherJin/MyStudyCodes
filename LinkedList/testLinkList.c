#include "linklist.h"

int main(int argc, char const *argv[])
{
    LNode H;
    H.next=NULL;
    H.data=NULL;
    InitLinkList(&H);
    PrintLinkList(&H);
    return 0;
}
