#include <bits/stdc++.h>
using namespace std;

#define N 50005
#define pb push_back

struct QUERY
{
	int no, l, r;
	bool operator < (const QUERY & o) const
	{
		if(l/223 == o.l/223) return r < o.r;
		return l/223 < o.l/223;
	}
};

int arr[N], ans[N*10], cnt[N];
map<int, int> cmp;
vector<QUERY> query;

int main()
{
	int n;
	scanf(" %d",&n);
	vector<int> v;
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %d",&arr[i]);
		v.pb(arr[i]);
	}
	sort(v.begin(), v.end());
	int sz = 0;
	for(int i=0 ; i<n ; i++)
		if(!cmp.count(v[i])) cmp[v[i]] = ++sz;
	for(int i=1 ; i<=n ; i++)
		arr[i] = cmp[arr[i]];
	int q;
	scanf(" %d",&q);
	for(int i=1 ; i<=q ; i++)
	{
		int a, b;
		scanf(" %d %d",&a,&b);
		a++, b++;
		query.pb({i, a, b});
	}
	sort(query.begin(), query.end());
	int l = query[0].l, r = query[0].r, cou = 0;
	for(int i=l ; i<=r ; i++)
	{
		cnt[arr[i]]++;
		if(cnt[arr[i]] > 1) cou++;
	}
	ans[query[0].no] = cou;
	for(int i=1 ; i<q ; i++)
	{
		while(query[i].l < l)
		{
			l--;
			cnt[arr[l]]++;
			if(cnt[arr[l]] > 1) cou++;
		}
		while(r < query[i].r)
		{
			r++;
			cnt[arr[r]]++;
			if(cnt[arr[r]] > 1) cou++;
		}
		while(l < query[i].l)
		{
			cnt[arr[l]]--;
			if(cnt[arr[l]] > 0) cou--;
			l++;
		}
		while(query[i].r < r)
		{
			cnt[arr[r]]--;
			if(cnt[arr[r]] > 0) cou--;
			r--;
		}
		ans[query[i].no] = cou;
	}
	for(int i=1 ; i<=q ; i++)
		printf("%d\n",ans[i]);
	return 0;
}
