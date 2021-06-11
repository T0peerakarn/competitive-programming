#include <bits/stdc++.h>
using namespace std;

int di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};
map<int, char> mp;

int main()
{
	mp[0] = 'E';
	mp[1] = 'S';
	mp[2] = 'W';
	mp[3] = 'N';
	int q, now = 0, ni = 0, nj = 0;
	scanf(" %d",&q);
	while(q--)
	{
		char c, x;
		int d;
		scanf(" %c %c %d",&c,&x,&d);
		if(c == 'L') now += 3;
		else if(c == 'R') now += 1;
		else if(c == 'B') now += 2;
		now %= 4;
		ni += d*di[now];
		nj += d*dj[now];
		if(abs(ni) >= 50000 || abs(nj) >= 50000)
		{
			printf("DEAD\n");
			return 0;
		}
	}
	printf("%d %d\n%c\n",nj,ni,mp[now]);
	return 0;
}
