#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20][20], di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool visit[20][20];

int count(int i, int j, int num)
{
	int ret = 1;
	visit[i][j] = true;
	for(int k=0 ; k<4 ; k++)
	{
		int ii = i+di[k], jj = j+dj[k];
		if(ii < 1 || jj < 1 || ii > n || jj > n || visit[ii][jj] || arr[ii][jj] != num) continue ;
		ret += count(ii, jj, num);
	}
	return ret;
}

bool check(int i, int j)
{
	if(arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j]) return true;
	if(arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+1][j-1]) return true;
	if(arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j+1]) return true;
	if(arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+1][j+1]) return true;
	return false;	
}

int main()
{
	int ans = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			scanf(" %d",&arr[i][j]);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
		{
			if(visit[i][j]) continue;
			int cnt = count(i, j, arr[i][j]);
			if(cnt != 3) continue;
			if(check(i, j)) ans++;
		}
	printf("%d\n",ans);
	return 0;
}
