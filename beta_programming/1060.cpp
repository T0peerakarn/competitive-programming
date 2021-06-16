#include <bits/stdc++.h>
using namespace std;

pair<int, int> mountain[22];
char ans[100][100];

int main()
{
	int n, H = 0, W = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		int s, h;
		scanf(" %d %d",&s,&h);
		H = max(H, h);
		W = max(W, s+2*h-1);
		mountain[i] = {s, h};
	}
	for(int i=1 ; i<=H ; i++)
		for(int j=1 ; j<=W ; j++)
			ans[i][j] = '.';
	for(int i=1 ; i<=n ; i++)
	{
		int s = mountain[i].first, h = mountain[i].second;
		for(int sz=2*(h-1), ni = H ; sz>=0 ; sz-=2, ni--, s++)
		{
			if(ans[ni][s] == '.') ans[ni][s] = '/';
			else if(ans[ni][s] == '\\') ans[ni][s] = 'v';
			if(ans[ni][s+sz+1] == '.') ans[ni][s+sz+1] = '\\';
			else if(ans[ni][s+sz+1] == '/') ans[ni][s+sz+1] = 'v';
			for(int k=1 ; k<=sz ; k++) ans[ni][s+k] = 'X';
		}
	}
	for(int i=1 ; i<=H ; i++)
	{
		for(int j=1 ; j<=W ; j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
}
