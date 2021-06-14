#include <bits/stdc++.h>
using namespace std;

int pos[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
vector<char> ans, button[10] = {{}, {}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'}};

void Type(int p, int t)
{
	if(p == 1)
	{
		while(!ans.empty() && t)
		{
			ans.pop_back();
			t--;
		}
	}
	else ans.push_back(button[p][(--t)%button[p].size()]);
}

int main()
{
	int n;
	scanf(" %d",&n);
	int now, ni, nj, di, dj, t;
	scanf(" %d %d",&now,&t);
	for(int i=0 ; i<3 ; i++) for(int j=0 ; j<3 ; j++) if(now == pos[i][j]) ni = i, nj = j;
	Type(now, t);
	for(int i=2 ; i<=n ; i++)
	{
		scanf(" %d %d %d",&dj,&di,&t);
		ni += di, nj += dj;
		now = pos[ni][nj];
		Type(now, t);
	}
	if(ans.empty()) printf("null\n");
	else for(auto x : ans) printf("%c",x);
	return 0;
}
