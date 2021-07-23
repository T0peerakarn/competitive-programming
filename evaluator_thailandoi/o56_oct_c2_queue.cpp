#include <bits/stdc++.h>
using namespace std;

struct DATA
{
	int num, pri;
	bool operator < (const DATA & o) const
	{
		return pri > o.pri;
	}
};

int fw[100100], arr[100100];
priority_queue<DATA> heap;

void update(int i, int v)
{
	while(i <= 100000)
	{
		fw[i] += v;
		i += -i&i;
	}
}

int query(int i)
{
	int ret = 0;
	while(i)
	{
		ret += fw[i];
		i -= -i&i;
	}
	return ret;
}

int main()
{
	int n, num = 0;
	scanf(" %d",&n);
	while(n--)
	{
		int op;
		scanf(" %d",&op);
		if(op == 1)
		{
			num++;
			int p;
			scanf(" %d",&p);
			heap.push({num, p});
			update(p, 1);
			arr[num] = p;
		}
		else if(op == 2)
		{
			if(heap.empty()) printf("0\n");
			else
			{
				printf("%d\n",heap.top().num);
				update(heap.top().pri, -1);
				heap.pop();
			}
		}
		else
		{
			int d;
			scanf(" %d",&d);
			printf("%d\n",query(arr[d])-1);
		}
	}
	return 0;
}
