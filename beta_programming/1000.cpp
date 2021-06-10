#include <bits/stdc++.h>
using namespace std;

char word[2][1010];

int main()
{
	int l, n;
	scanf(" %d %d",&l,&n);
	scanf(" %s",word[1]);
	for(int i=2 ; i<=n ; i++)
	{
		scanf(" %s",word[i%2]);
		int cnt = 0;
		for(int j=0 ; j<l ; j++)
			if(word[i%2][j] != word[(i-1)%2][j]) cnt++;
		if(cnt > 2)
		{
			cout << word[(i-1)%2] << endl;
			return 0;
		}
	}
	cout << word[n%2] << endl;
	return 0;
}
