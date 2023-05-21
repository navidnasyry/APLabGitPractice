#include<stdio.h>
int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int* ptr1 = arr;
    int* ptr2 = arr + 5;
    printf("%d\n", (*ptr2 - *ptr1));
    char s = (*ptr2 - *ptr1) + '0';
    printf("%c", s);
    return 0;
}