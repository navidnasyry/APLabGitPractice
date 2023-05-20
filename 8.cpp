#include<stdio.h>

const char * f(const char **p) {
	auto q = (p + sizeof(char))[1];
	return q;
}
int main() {
	const char * str[] = { "Wish","You","Best",":D" };
	printf("%c%c ", *f(str), *(f(str) + 1));
	printf("%c%c%c%c\n", **str, *(*(str + 1) + 1), *((str + 2)[-1] + 1), **&*(&str[-1] + 1));
	//the size of char is 1 so,
	//the output is:
	//Be WooW
	
	
}
