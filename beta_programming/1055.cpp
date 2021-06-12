#include <bits/stdc++.h>
using namespace std;

int v[110], sum[22];
bool out[110];

int main()
{
	int n, k, now = 0;
	scanf(" %d %d",&n,&k);
	for(int i=0 ; i<n ; i++) scanf(" %d",&v[i]);
	for(int i=0 ; i<n ; i++)
	{
		int p, cnt = 0;
		scanf(" %d",&p);
		p++;
		while(true)
		{
			if(!out[now]) cnt++;
			if(cnt == p) break;
			now++;
			now%=n;
		}
		out[now] = true;
		sum[i%k] += v[now];
	}
	for(int i=0 ; i<k ; i++) printf("%d\n",sum[i]);
	return 0;
}
