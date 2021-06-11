#include <bits/stdc++.h>
using namespace std;

int puzzle[10][10], ans[10][10], cnt[10];

int main()
{
	int q;
	scanf(" %d",&q);
	for(int i=1 ; i<=9 ; i++)
		for(int j=1 ; j<=9 ; j++)
			scanf(" %d",&puzzle[i][j]);
	for(int qq=1 ; qq<=q ; qq++)
	{
		for(int i=1 ; i<=9 ; i++)
			for(int j=1 ; j<=9 ; j++)
				scanf(" %d",&ans[i][j]);

		for(int i=1 ; i<=9 ; i++)
			for(int j=1 ; j<=9 ; j++)
				if(puzzle[i][j] != 0 && puzzle[i][j] != ans[i][j]) goto wrong;

		for(int i=1 ; i<=9 ; i++)
		{
			memset(cnt, 0, sizeof cnt);
			for(int j=1 ; j<=9 ; j++)
			{
				cnt[ans[i][j]]++;
				if(cnt[ans[i][j]] > 1) goto wrong;
			}

			memset(cnt, 0, sizeof cnt);
			for(int j=1 ; j<=9 ; j++)
			{
				cnt[ans[j][i]]++;
				if(cnt[ans[j][i]] > 1) goto wrong;
			}
		}

		for(int i=1 ; i<=9 ; i+=3)
			for(int j=1 ; j<=9 ; j+=3)
			{
				memset(cnt, 0, sizeof cnt);
				for(int ii=i ; ii<i+3 ; ii++)
					for(int jj=j ; jj<j+3 ; jj++)
					{
						cnt[ans[ii][jj]]++;
						if(cnt[ans[ii][jj]] > 1) goto wrong;
					}
			}
			
		printf("%d\n",qq);
		wrong: ;
	}
	printf("END\n");
	return 0;
}
