#include <bits/stdc++.h>
using namespace std;

char str[10005];

int main()
{
	scanf(" %s",str);
	int len = strlen(str), t = 0;
	for(int i=0 ; i<len ; i++)
	{
		if('a' <= str[i] && str[i] <= 'z') t |= 1;
		if('A' <= str[i] && str[i] == 'Z') t |= 2;
	}	
	if(t == 1) printf("All Small Letter\n");
	else if(t == 2) printf("All Capital Letter\n");
	else printf("Mix\n");
	return 0;
}
