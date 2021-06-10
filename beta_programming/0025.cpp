#include <bits/stdc++.h>
using namespace std;

char a[110], b[110], opr;
int main()
{
	scanf(" %s",a);
	scanf(" %c",&opr);
	scanf(" %s",b);
	int la = strlen(a), lb = strlen(b);
	if(opr == '*')
	{
		printf("1");
		for(int i=0 ; i<la+lb-2 ; i++) printf("0");
	}
	else
	{
		if(la == lb)
		{
			printf("2");
			for(int i=0 ; i<la-1 ; i++) printf("0");
		}
		else
		{
			int mx = max(la, lb);
			for(int i=1 ; i<=mx ; i++)
			{
				char c = '0';
				if(mx - la + 1 == i || mx - lb + 1 == i) c = '1';
				printf("%c",c);
			}
		}
	}
	return 0;
}
