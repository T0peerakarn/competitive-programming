#include <bits/stdc++.h>
using namespace std;

int var[30];

int main()
{
	while(true)
	{
		char op;
		scanf(" %c",&op);
		if(op == '=')
		{
			char c;
			int d;
			scanf(" %c %d",&c,&d);
			var[c-'A'] = d;
		}
		else if(op == '#')
		{
			char c;
			scanf(" %c",&c);
			printf("%d\n",var[c-'A']);
		}
		else if(op == '+')
		{
			char a, b;
			scanf(" %c %c",&a,&b);
			var[a-'A'] += var[b-'A'];
		}
		else if(op == '-')
		{
			char a, b;
			scanf(" %c %c",&a,&b);
			var[a-'A'] -= var[b-'A'];
		}
		else if(op == '*')
		{
			char a, b;
			scanf(" %c %c",&a,&b);
			var[a-'A'] *= var[b-'A'];
		}
		else if(op == '/')
		{
			char a, b;
			scanf(" %c %c",&a,&b);
			var[a-'A'] /= var[b-'A'];
		}
		else
		{
			printf("!\n");
			return 0;
		}
	}
	return 0;
}
