#include <bits/stdc++.h>
using namespace std;

char str[20];

int main()
{
	scanf(" %s",str);
	int len = strlen(str);

	for(int i=0 ; i<len ; i++)
	{
		char c = (i%3 == 2) ? '*' : '#';
		printf("..%c.",c);
	}
	printf(".\n");

	for(int i=0 ; i<len ; i++)
	{
		char c = (i%3 == 2) ? '*' : '#';
		printf(".%c.%c",c,c); 
	}
	printf(".\n");

	for(int i=0 ; i<len ; i++)
	{
		char c = (i%3 == 2 || (i-1)%3 == 2) ? '*' : '#';
		printf("%c.%c.",c,str[i]);
	}
	printf((len%3 == 0) ? "*\n" : "#\n");

	for(int i=0 ; i<len ; i++)
	{
		char c = (i%3 == 2) ? '*' : '#';
		printf(".%c.%c",c,c); 
	}
	printf(".\n");

	for(int i=0 ; i<len ; i++)
	{
		char c = (i%3 == 2) ? '*' : '#';
		printf("..%c.",c);
	}
	printf(".\n");

	return 0;
}
