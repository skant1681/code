//adding two numbers in of base 14

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addbase14(char* n1, char* n2)
{

}

int main(int argc, char const *argv[])
{
	char n1[20], n2[20];

	printf("enter 1st number:\n");
	scanf("%s",n1);
	printf("enter 2nd number:\n");
	scanf("%s",n2);
	int len = strlen(n1);
	printf("%d\n",len);

	addbase14(n1,n2);

	return 0;
}
