#include <bits/stdc++.h>
using namespace std;

int now;
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char t[10][10], tmp[10][10];
map<char, int> mp;

void Init()
{
	for(int i=1 ; i<=8 ; i++)
		for(int j=1 ; j<=8 ; j++)
			t[i][j] = '.';

	t[4][5] = t[5][4] = 'X';
	t[4][4] = t[5][5] = 'O';

	for(int i=0 ; i<8 ; i++) mp['a'+i] = i+1;
	mp['X'] = 1;
	mp['O'] = 2;
	now = 1;
}

void Copy()
{
	for(int i=1 ; i<=8 ; i++)
		for(int j=1 ; j<=8 ; j++)
			tmp[i][j] = t[i][j];
}

bool Try(int i, int j, int col)
{
	if(t[i][j] != '.') return false;
	Copy();
	tmp[i][j] = (col == 1) ? 'X' : 'O';
	for(int k=0 ; k<8 ; k++)
	{
		int ii = i+di[k], jj = j+dj[k];
		bool ch_enemy = false, ch_tail = false;
		while(1 <= ii && ii <= 8 && 1 <= jj && jj <= 8)
		{
			if(tmp[ii][jj] == '.') break;
			if(mp[tmp[ii][jj]] == col)
			{
				ch_tail = true;
				break;
			}
			if(mp[tmp[ii][jj]] != col) ch_enemy = true;
			ii += di[k], jj += dj[k];
		}
		if(ch_enemy && ch_tail) return true;
	}
	return false;
}

void Place(int i, int j, int col)
{
	t[i][j] = (col == 1) ? 'X' : 'O';
	for(int k=0 ; k<8 ; k++)
	{
		int ii = i+di[k], jj = j+dj[k];
		bool ch_enemy = false, ch_tail = false;
		while(1 <= ii && ii <= 8 && 1 <= jj && jj <= 8)
		{
			if(tmp[ii][jj] == '.') break;
			if(mp[tmp[ii][jj]] == col)
			{
				ch_tail = true;
				break;
			}
			if(mp[tmp[ii][jj]] != col) ch_enemy = true;
			ii += di[k], jj += dj[k];
		}
		if(ch_enemy && ch_tail)
		{
			ii = i+di[k], jj = j+dj[k];
			while(true)
			{
				t[ii][jj] = t[i][j];
				ii += di[k], jj += dj[k];
				if(t[ii][jj] == t[i][j]) break;
			}
		}
	}
}

void Print()
{
	for(int i=1 ; i<=8 ; i++)
	{
		for(int j=1 ; j<=8 ; j++)
			printf("%c",t[i][j]);
		printf("\n");
	}
}

int main()
{
	Init();
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		char c;
		int i, j;
		scanf(" %c %d",&c,&i);
		j = mp[c];

		if(Try(i, j, now)) Place(i, j, now);
		else
		{
			now ^= 3;
			Place(i, j, now);
		}
		now ^= 3;
	}
	Print();
	return 0;
}
