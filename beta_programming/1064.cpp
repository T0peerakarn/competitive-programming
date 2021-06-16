#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int arr[70][70], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
char t[70][70];
bool mark[70];

void dfs(int i, int j, int no)
{
	arr[i][j] = no;
	for(int k=0 ; k<4 ; k++)
	{
		int ii = i+di[k], jj = j+dj[k];
		if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] != 'P') continue;
		t[ii][jj] = 'S';
		dfs(ii, jj, no);
	}
}

bool Check(int si, int sj, int ei, int ej)
{
	for(int i=si ; i<=ei ; i++)
		for(int j=sj ; j<=ej ; j++)
			if(t[i][j] == 'T') return false;
	return true;
}

int compute(int si, int sj, int ei, int ej)
{
	int ret = 0;
	for(int i=1 ; i<=cnt ; i++) mark[i] = 0;
	for(int i=si ; i<=ei ; i++) for(int j=sj ; j<=ej ; j++) if(arr[i][j] != 0 && !mark[arr[i][j]]) ret++, mark[arr[i][j]] = true;
	return ret;
}

int main()
{
	scanf(" %d %d",&m,&n);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			scanf(" %c",&t[i][j]);
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			if(t[i][j] == 'P')
			{
				t[i][j] = 'S';
				dfs(i, j, ++cnt);
			}
		}
	}
	int l = 0, r = min(n, m);
	while(l != r)
	{
		int mid = (l+r+1)>>1;
		for(int si=1 ; si<=n ; si++)
		{
			int ei = si+mid-1;
			if(ei > n) break;
			for(int sj=1 ; sj<=m ; sj++)
			{
				int ej = sj+mid-1;
				if(ej > m) break;
				if(Check(si, sj, ei, ej))
				{
					l = mid;
					goto out;
				}
			}
		}
		r = mid-1;
		out: ;
	}
	if(!l) printf("0 0\n");
	else
	{
		int mn = 70;
		for(int si=1 ; si<=n ; si++)
		{
			int ei = si+l-1;
			if(ei > n) break;
			for(int sj=1 ; sj<=m ; sj++)
			{
				int ej = sj+l-1;
				if(ej > m) break;
				if(Check(si, sj, ei, ej)) mn = min(mn, compute(si, sj, ei, ej));
			}
		}
		printf("%d %d\n",l*l,mn);
	}
	return 0;
}
