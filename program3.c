// 3. Write a C program to implement a structure.

#include<stdio.h>

struct point
{
	int x;
	int y;
};

int main()
{
	struct point p1 = {0,1};
	printf("%d\n", p1.x);
	printf("%d\n", p1.y);
	return 0;
}
