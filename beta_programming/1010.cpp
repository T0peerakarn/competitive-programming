#include <bits/stdc++.h>
using namespace std;

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char t[30][30];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
		{
			scanf(" %c",&t[i][j]);
			t[i][j] = tolower(t[i][j]);
		}
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		char str[20];
		scanf(" %s",str+1);
		int len = strlen(str+1);
		for(int i=1 ; i<=len ; i++) str[i] = tolower(str[i]);
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
				for(int k=0 ; k<8 ; k++)
				{
					int ii = i, jj = j;
					for(int it = 1 ; it<=len ; it++)
					{
						if(ii < 1 || ii > n || jj < 1 || jj > m || t[ii][jj] != str[it]) goto out1;
						ii += di[k], jj += dj[k];
					}
					printf("%d %d\n",i-1,j-1);
					goto out2;
					out1: ;
				}
		out2: ;
	}
	return 0;
}
