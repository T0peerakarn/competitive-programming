#include <bits/stdc++.h>
using namespace std;

struct range
{
	int no, len;
	char c;
	bool operator < (const range & o) const
	{
		return (len == o.len) ? (no == o.no) ? c > o.c : no > o.no : len < o.len;
	}
};

int p[100005], h[100005];
priority_queue<range> heap;

int push_left(int i, int n)
{
	int pos = p[i] - h[i];
	while(i > 1)
	{
		if(pos < p[i-1])
		{
			pos = min(pos, p[i-1] - h[i-1]);
			i--;
		}
		else break;
	}
	return i;
}

int push_right(int i, int n)
{
	int pos = p[i] + h[i];
	while(i < n)
	{
		if(p[i+1] < pos)
		{
			pos = max(pos, p[i+1] + h[i+1]);
			i++;
		}
		else break;
	}
	return i;
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) scanf(" %d %d",&p[i],&h[i]);
	for(int i=n ; i>=1 ; i--)
	{
		int j = push_left(i, n);
		heap.push({i, i-j+1, 'L'});
		i = j;
	}
	for(int i=1 ; i<=n ; i++)
	{
		int j = push_right(i, n);
		heap.push({i, j-i+1, 'R'});
		i = j;
	}
	printf("%d %c\n",heap.top().no,heap.top().c);
	return 0;
}
