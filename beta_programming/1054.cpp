#include <bits/stdc++.h>
using namespace std;

struct circle
{
	int x, y, r;
};

circle arr[100005];
vector<int> v[40005][11];
vector<pair<int, int>> dif[11][11];

bool Check(int xi, int yi, int ri, int xj, int yj, int rj)
{
	return (xi-xj)*(xi-xj) + (yi-yj)*(yi-yj) < (ri+rj)*(ri+rj);
}

void Init()
{
	for(int ri=1 ; ri<=10 ; ri++)
		for(int rj=1 ; rj<=10 ; rj++)
			for(int i=-19 ; i<=19 ; i++)
			{
				for(int j=-19 ; j<=19 ; j++)
				{
					if(i == 0 && j == 0) continue;
					if(Check(0, 0, ri, i, j, rj))
					{
						dif[ri][rj].push_back({i, j});
						dif[ri][rj].push_back({i, -j});
						break;
					}
				}
			}
}

int main()
{
	Init();
	int n, ans = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ;i++)
	{
		int x, y, r;
		scanf(" %d %d %d",&x,&y,&r);
		arr[i] = {x, y, r};
		v[x+20000][r].push_back(y);
	}
	for(int i=0 ; i<=40000 ; i++) for(int j=1 ; j<=10 ; j++) if(!v[i][j].empty()) sort(v[i][j].begin(), v[i][j].end());
	for(int i=1 ; i<=n ; i++)
	{
		ans -= 1;
		for(int j=1 ; j<=10 ; j++)
		{
			int sz = dif[arr[i].r][j].size();
			for(int k=0 ; k<sz ; k+=2)
			{
				int x = 20000 + arr[i].x + dif[arr[i].r][j][k].first;
				int dy = arr[i].y + dif[arr[i].r][j][k].second, uy = arr[i].y + dif[arr[i].r][j][k+1].second;
				if(!v[x][j].empty())
				{
					int l, r, L=0, R=v[x][j].size()-1;

					l = L, r = R;
					while(l != r)
					{
						int mid = (l+r)>>1;
						(v[x][j][mid] >= dy) ? r = mid : l = mid+1;
					}
					L = l;
					if(v[x][j][L] < dy) goto out;

					l = L, r = R;
					while(l != r)
					{
						int mid = (l+r+1)>>1;
						(v[x][j][mid] <= uy) ? l = mid : r = mid-1;
					}
					R = l;
					if(uy < v[x][j][R]) goto out;
					ans += R-L+1;
				}
				out: ;
			}
		}
	}
	printf("%d\n",ans/2);
	return 0;
}
