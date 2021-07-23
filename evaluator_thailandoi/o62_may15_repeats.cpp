#include <bits/stdc++.h>
using namespace std;

char str[1010];

int main()
{
	int k, ans = 0;
	scanf(" %d %s",&k,str+1);
	int n = strlen(str+1);
	for(int sz=1 ; sz*2<=n ; sz++)
	{
		int cnt = 0;
		deque<char> sw1, sw2;
		for(int i=1 ; i<=sz ; i++)
			sw1.push_back(str[i]);
		for(int i=sz+1 ; i<=sz*2 ; i++)
		{
			if(str[i] != sw1[i-sz-1]) cnt++;
			sw2.push_back(str[i]);
		}
		if(cnt <= k) ans++;
		for(int j=sz*2+1 ; j<=n ; j++)
		{
			if(sw1.front() != sw2.front()) cnt--;
			sw1.pop_front(), sw2.pop_front();
			sw1.push_back(str[j-sz]), sw2.push_back(str[j]);
			if(sw1.back() != sw2.back()) cnt++;
			if(cnt <= k) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
