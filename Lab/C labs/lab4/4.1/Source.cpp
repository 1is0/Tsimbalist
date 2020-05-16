#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char str1[80], str2[80];
	printf("Enter first number: ");
	gets_s(str1);
	printf("Enter second number: ");
	gets_s(str2);
	printf("The sum is: %d", atoi(str1) + atoi(str2));
	return 0;
}