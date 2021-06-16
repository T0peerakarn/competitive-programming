#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	stack<char> stk;
	while(n--)
	{
		char c;
		scanf(" %c",&c);
		if(!stk.empty() && stk.top() == c) stk.pop();
		else stk.push(c);
	}
	printf("%d\n",stk.size());
	if(!stk.size()) printf("empty\n");
	while(!stk.empty())
	{
		printf("%c",stk.top());
		stk.pop();
	}
	return 0;
}
