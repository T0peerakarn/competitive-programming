#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[10005];

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n, np, nf, ans = 0;
		scanf(" %d",&n);
		for(int i=1 ; i<=n ; i++) scanf(" %d %d",&arr[i].first,&arr[i].second);
		sort(arr+1, arr+n+1);
		scanf(" %d %d",&np,&nf);
		priority_queue<int> heap;
		for(int i=n ; i>=1 ; i--)
		{
			while(!heap.empty() && np-nf > arr[i].first)
			{
				nf += heap.top();
				ans++;
				heap.pop();
			}
			if(np-nf <= arr[i].first) heap.push(arr[i].second);
		}
		while(!heap.empty() && np > nf)
		{
			nf += heap.top();
			ans++;
			heap.pop();
		}
		printf((np <= nf) ? "%d\n" : "-1\n",ans);
	}
	return 0;
}
