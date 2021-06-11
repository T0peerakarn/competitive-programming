#include <bits/stdc++.h>
using namespace std;

int n, m, score;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
char t[5][5];
bool visit[5][5];

bool Block(int i, int j) {return (t[i][j] != '#' && t[i][j] != '-') ? true : false;}
bool Movable(int i, int j) {return (j < 0 || j >= m || t[i][j] != '-') ? false : true;}

void Fall()
{
	bool working = true;
	while(working)
	{
		working = false;
		for(int i=0 ; i<n-1 ; i++)
			for(int j=0 ; j<m ; j++)
				if(Block(i, j) && t[i+1][j] == '-')
				{
					swap(t[i][j], t[i+1][j]);
					working = true;
				}
	}
}

int Count(int i, int j, char c)
{
	int ret = 1;
	visit[i][j] = true;
	for(int k=0 ; k<4 ; k++)
	{
		int ii = i + di[k], jj = j + dj[k];
		if(ii < 0 || jj < 0 || ii >=n || jj >= m || visit[ii][jj] || t[ii][jj] != c) continue;
		ret += Count(ii, jj, c);
	}
	visit[i][j] = false;
	return ret;
}

void Remove(int i, int j, char c)
{
	t[i][j] = '-';
	score += 5;
	for(int k=0 ; k<4 ; k++)
	{
		int ii = i + di[k], jj = j + dj[k];
		if(ii < 0 || jj < 0 || ii >=n || jj >= m || t[ii][jj] != c) continue;
		Remove(ii, jj, c);
	}
}

bool Pop()
{
	bool ret = false;
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			if(Block(i, j) && Count(i, j, t[i][j]) > 1)
			{
				Remove(i, j, t[i][j]);
				ret = true;
			}
	return ret;
}

int main()
{
	scanf(" %d %d",&n,&m);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			scanf(" %c",&t[i][j]);
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		int a, b;
		char c;
		scanf(" %d %d %c",&a,&b,&c);
		if(!Block(a, b))
		{
			score -= 5;
			continue;
		}
		if(!Movable(a, b + (c == 'L' ? -1 : 1)))
		{
			score -= 5;
			continue ;
		}
		swap(t[a][b], t[a][b + (c == 'L' ? -1 : 1)]);
		bool working = true;
		while(working)
		{
			working = false;
			Fall();
			if(Pop()) working = true;
		}
	}
	printf("%d\n",score);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
			printf("%c ",t[i][j]);
		printf("\n");
	}
	return 0;
}
