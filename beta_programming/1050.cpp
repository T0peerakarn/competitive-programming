#include <bits/stdc++.h>
using namespace std;

struct Reactant
{
	int no, k;
	int prop[10];
	bool operator < (const Reactant & o) const
	{
		for(int i=0 ; i<k ; i++) if(prop[i] != o.prop[i]) return prop[i] < o.prop[i];
	}
};

Reactant arr[100005], target;
vector<Reactant> v;

int main()
{
	int n, k;
	scanf(" %d %d",&n,&k);
	for(int i=1 ; i<=n ; i++)
	{
		arr[i].no = i;
		arr[i].k = k;
		for(int j=0 ; j<k ; j++) scanf(" %d",&arr[i].prop[j]);
	}
	sort(arr+1, arr+n+1);
	for(int j=0 ; j<k ; j++) scanf(" %d",&target.prop[j]);
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=0 ; j<k ; j++) if(arr[i].prop[j] != target.prop[j]) goto out1;
		printf("%d\n",arr[i].no);
		return 0;
		out1: ;
	}
	for(int i=1 ; i<=n ; i++)
	{
		if(!v.empty())
		{
			int l, r, L = 0, R = v.size()-1;
			for(int j=0 ; j<k ; j++)
			{
				l = L, r = R;
				while(l != r)
				{
					int mid = (l+r)>>1;
					(target.prop[j] - arr[i].prop[j] <= v[mid].prop[j]) ? r = mid : l = mid+1;
				}
				L = l;

				l = L, r = R;
				while(l != r)
				{
					int mid = (l+r+1)>>1;
					(v[mid].prop[j] <= target.prop[j] - arr[i].prop[j]) ? l = mid : r = mid-1;
				}
				R = r;
			}
			for(int j=0 ; j<k ; j++) if(arr[i].prop[j] + v[l].prop[j] != target.prop[j]) goto out2;
			printf("%d %d\n",min(v[l].no, arr[i].no), max(v[l].no, arr[i].no));
			return 0;
			out2: ;
		}
		v.push_back(arr[i]);
	}
	printf("NO\n");
	return 0;
}
