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
	int j = i, pos = p[i] - h[i];
	while(i > 1)
	{
		if(pos < p[i-1])
		{
			pos = min(pos, p[i-1] - h[i-1]);
			i--;
		}
		else break;
	}
	heap.push({j, j-i+1, 'L'});
	return i;
}

int push_right(int i, int n)
{
	int j = i, pos = p[i] + h[i];
	while(i < n)
	{
		if(p[i+1] < pos)
		{
			pos = max(pos, p[i+1] + h[i+1]);
			i++;
		}
		else break;
	}
	heap.push({j, i-j+1, 'R'});
	return i;
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) scanf(" %d %d",&p[i],&h[i]);
	for(int i=n ; i>=1 ; i = push_left(i, n)-1);
	for(int i=1 ; i<=n ; i = push_right(i, n)+1);
	printf("%d %c\n",heap.top().no,heap.top().c);
	return 0;
}
