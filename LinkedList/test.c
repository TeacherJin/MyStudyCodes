#include "linklist.h"

int main(int argc, char const *argv[])
{
	printf("-----------start-----------\n");
	LinkList L=LinkListCreate(5);
	LinkListPrint(L);
	return 0;
}
