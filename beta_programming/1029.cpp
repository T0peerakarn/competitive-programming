#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, q;
	scanf(" %d %d %d",&m,&n,&q);
	vector<int> tmp;
	for(int i=0 ; i<n ; i++)
	{
		int a, b;
		scanf(" %d %d",&a,&b);
		tmp.push_back(a);
		tmp.push_back(a+b);
	}
	sort(tmp.begin(), tmp.end());
	deque<int> deq;
	for(auto x : tmp)
	{
		if(!deq.empty() && deq.back() == x) deq.pop_back();
		else deq.push_back(x);
	}
	if(deq.front() != 1) deq.push_front(1);
	deq.push_back(m+1);
	while(q--)
	{
		int x;
		scanf(" %d",&x);
		int l = 0, r = deq.size()-1;
		while(l != r)
		{
			int mid = (l+r+1)>>1;
			(deq[mid] <= x) ? l = mid : r = mid-1;
		}
		printf("%d\n",deq[l+1]-deq[l]);
	}
	return 0;
}
