#include<stdio.h>

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("%d\n", (*ptr2 - *ptr1));
    printf("%c", (char)(*ptr2 - *ptr1));
	// at first ptr1 points to the first house of arr so the first output is the answer of 60-10 that is 50!
	// then we cast 50 to char that equals to '2'!
	
    return 0;
}
