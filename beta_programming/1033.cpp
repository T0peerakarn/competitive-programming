#include <bits/stdc++.h>
using namespace std;

int arr[110][110], cnt[4], di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, 1, -1};
char walk[4][1005];
pair<int, int> pos[4];
map<char, int> mp;
bool player[110][110];

int main()
{
	int n, k;
	scanf(" %d %d",&n,&k);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			arr[i][j] = -1;
	for(int i=0 ; i<4 ; i++)
		for(int j=0 ; j<k ; j++)
			scanf(" %c",&walk[i][j]);

	mp['N'] = 0;
	mp['S'] = 1;
	mp['E'] = 2;
	mp['W'] = 3;

	arr[1][n] = 0;
	pos[0] = {1, n};
	cnt[0] = 1;
	player[1][n] = true;

	arr[n][n] = 1;
	pos[1] = {n, n};
	cnt[1] = 1;
	player[n][n] = true;

	arr[n][1] = 2;
	pos[2] = {n, 1};
	cnt[2] = 1;
	player[n][1] = true;

	arr[1][1] = 3;
	pos[3] = {1, 1};
	cnt[3] = 1;
	player[1][1] = true;

	for(int i=0 ; i<k*4 ; i++)
	{
		char c = walk[i%4][i/4];
		int ni = pos[i%4].first + di[mp[c]], nj = pos[i%4].second + dj[mp[c]];
		if(ni < 1 || nj < 1 || ni > n || nj > n || player[ni][nj]) continue;
		player[pos[i%4].first][pos[i%4].second] = false;
		player[ni][nj] = true;
		pos[i%4] = {ni, nj};
		if(arr[ni][nj] != -1) cnt[arr[ni][nj]]--;
		arr[ni][nj] = i%4;
		cnt[i%4]++;
	}

	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			if(arr[i][j] == -1)
			{
				printf("No\n");
				return 0;
			}
	int mx = -1, frq = 0;
	for(int i=0 ; i<4 ; i++)
	{
		if(cnt[i] > mx)
		{
			mx = cnt[i];
			frq = 1;
		}
		else if(cnt[i] == mx) frq++;
	}
	printf("%d %d\n",frq,mx);
	for(int i=0 ; i<4 ; i++) if(cnt[i] == mx) printf("%d\n",i+1);
	return 0;
}
