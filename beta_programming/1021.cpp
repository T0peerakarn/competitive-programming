#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> heap;
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		char c;
		scanf(" %c",&c);
		if(c == 'P')
		{
			int d;
			scanf(" %d",&d);
			heap.push(d);
		}
		else
		{
			if(heap.empty()) printf("-1\n");
			else
			{
				printf("%d\n",heap.top());
				heap.pop();
			}
		}
	}
	return 0;
}
