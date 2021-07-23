#include "sockslib.h"
#include <bits/stdc++.h>
using namespace std;

bool mark[2002];

int main()
{
	int n = num();
	for(int i=1 ; i<=n+n ; i++)
	{
		if(mark[i]) continue;
		vector<int> arr;
		for(int j=i+1 ; j<=n+n ; j++)
		{
			if(mark[j]) continue;
			arr.push_back(j);
		}
		int l=0, r=arr.size()-1;
		while(l != r)
		{
			int mid = (l+r)>>1;
			vector<int> v;
			for(int j=0 ; j<=mid ; j++)
				v.push_back(arr[j]);
			int ret1 = ask(v);
			v.push_back(i);
			int ret2 = ask(v);
			(ret1 == ret2) ? r = mid : l = mid+1;
		}
		match(i, arr[l]);
		mark[i] = mark[arr[l]] = true;
	}
}
