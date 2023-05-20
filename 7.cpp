#include<stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int *p = arr;
	++*p;
	p += 2;
	printf("%d", *p);
	// at first we add 1 to p[0] and then we went to the p[2] so the output is 3

	return 0;
}
