#include <bits/stdc++.h>
using namespace std;

struct Block
{
	int t, c, i, j;
};

vector<Block> v;
int col[1030][1030];
bool mark[5];

int mid(int a, int b)
{
	return (a+b)>>1;
}

void stair(int n, int t, int si, int sj)
{
	int ei = si+(1<<n)-1, ej = sj+(1<<n)-1;
	int mi = mid(si, ei), mj = mid(sj, ej);
	if(n == 2)
	{
		if(t == 1)
		{
			v.push_back({1, 1, mi, mj});
			v.push_back({1, 2, mi+1, mj+1});
			v.push_back({2, 3, mi+1, sj});
			v.push_back({3, 3, si, mj+1});
		}
		else if(t == 2)
		{
			v.push_back({2, 1, mi, mj});
			v.push_back({2, 3, mi+1, sj});
			v.push_back({4, 2, si, sj});
			v.push_back({1, 2, mi+1, mj+1});
		}
		else if(t == 3)
		{
			v.push_back({3, 1, mi, mj});
			v.push_back({3, 3, si, mj+1});
			v.push_back({4, 2, si, sj});
			v.push_back({1, 2, mi+1, mj+1});
		}
		else
		{
			v.push_back({4, 1, mi, mj});
			v.push_back({4, 2, si, sj});
			v.push_back({2, 3, mi+1, sj});
			v.push_back({3, 3, si, mj+1});
		}
	}
	else if(t == 1)
	{
		stair(n-1, 1, mid(si, mi)+1, mid(sj, mj)+1);
		stair(n-1, 1, mi+1, mj+1);
		stair(n-1, 2, mi+1, sj);
		stair(n-1, 3, si, mj+1);
	}
	else if(t == 2)
	{
		stair(n-1, 2, mid(si, mi)+1, mid(sj, mj)+1);
		stair(n-1, 2, mi+1, sj);
		stair(n-1, 4, si, sj);
		stair(n-1, 1, mi+1, mj+1);
	}
	else if(t == 3)
	{
		stair(n-1, 3, mid(si, mi)+1, mid(sj, mj)+1);
		stair(n-1, 3, si, mj+1);
		stair(n-1, 4, si, sj);
		stair(n-1, 1, mi+1, mj+1);
	}
	else
	{
		stair(n-1, 4, mid(si, mi)+1, mid(sj, mj)+1);
		stair(n-1, 4, si, sj);
		stair(n-1, 2, mi+1, sj);
		stair(n-1, 3, si, mj+1);
	}
}

void square(int n, int si, int sj, int x, int y)
{
	if(n == 1)
	{
		int t;
		if(si == y && sj == x) t = 1;
		else if(si == y) t = 2;
		else if(sj == x) t = 3;
		else t = 4;
		v.push_back({t, 0, si, sj});
		return;
	}
	int ei = si+(1<<n)-1, ej = sj+(1<<n)-1;
	int mi = mid(si, ei), mj = mid(sj, ej);
	if(y <= mi && x <= mj)
	{
		square(n-1, si, sj, x, y);
		stair(n, 1, si, sj);
	}
	else if(y <= mi)
	{
		square(n-1, si, mj+1, x, y);
		stair(n, 2, si, sj);
	}
	else if(x <= mj)
	{
		square(n-1, mi+1, sj, x, y);
		stair(n, 3, si, sj);
	}
	else
	{
		square(n-1, mi+1, mj+1, x, y);
		stair(n, 4, si, sj);
	}
}

void place(Block now)
{
	if(now.t == 1)
	{
		col[now.i][now.j+1] = col[now.i+1][now.j+1] = col[now.i+1][now.j] = now.c;
	}
	else if(now.t == 2)
	{
		col[now.i][now.j] = col[now.i+1][now.j+1] = col[now.i+1][now.j] = now.c;
	}
	else if(now.t == 3)
	{
		col[now.i][now.j] = col[now.i][now.j+1] = col[now.i+1][now.j+1] = now.c;
	}
	else
	{
		col[now.i][now.j] = col[now.i][now.j+1] = col[now.i+1][now.j] = now.c;
	}
}

void Try(Block &now)
{
	int t = now.t, i = now.i, j = now.j;
	if(t == 1)
	{
		mark[col[i][j]] = true;
		mark[col[i-1][j+1]] = true;
		mark[col[i][j+2]] = true;
		mark[col[i+1][j+2]] = true;
		mark[col[i+2][j+1]] = true;
		mark[col[i+2][j]] = true;
		mark[col[i+1][j-1]] = true;
	}
	else if(t == 2)
	{
		mark[col[i-1][j]] = true;
		mark[col[i][j+1]] = true;
		mark[col[i+1][j+2]] = true;
		mark[col[i+2][j+1]] = true;
		mark[col[i+2][j]] = true;
		mark[col[i+1][j-1]] = true;
		mark[col[i][j-1]] = true;
	}
	else if(t == 3)
	{
		mark[col[i-1][j]] = true;
		mark[col[i-1][j+1]] = true;
		mark[col[i][j+2]] = true;
		mark[col[i+1][j+2]] = true;
		mark[col[i+2][j+1]] = true;
		mark[col[i+1][j]] = true;
		mark[col[i][j-1]] = true;
	}
	else
	{
		mark[col[i-1][j]] = true;
		mark[col[i-1][j+1]] = true;
		mark[col[i][j+2]] = true;
		mark[col[i+1][j+1]] = true;
		mark[col[i+2][j]] = true;
		mark[col[i+1][j-1]] = true;
		mark[col[i][j-1]] = true;
	}
	now.c = (mark[1]) ? (mark[2]) ? 3 : 2 : 1;
}

int main()
{
	int n, x, y;
	scanf(" %d %d %d",&n,&x,&y);
	square(n, 1, 1, x, y);

	for(auto x : v)
		place(x);
				
	for(auto &x : v)
	{
		if(x.c == 0) Try(x);
		printf("%d %d %d %d\n",x.t,x.c,x.j,x.i);
	}
	return 0;
}
