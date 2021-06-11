#include <bits/stdc++.h>
using namespace std;

int score[10];
char str[10005];
bool lose[10];

int main()
{
	int close = 0;
	while(true)
	{
		scanf(" %s",str);
		if(str[0] == '!') break;
		int len = strlen(str);
		for(int i=0 ; i<len ; i++) if(!lose[str[i]-'A']) score[str[i]-'A']++;
		int mn = 1e9, frq = 0;
		for(int i=0 ; i<7 ; i++)
		{
			if(lose[i]) continue;
			if(mn > score[i])
			{
				mn = score[i];
				frq = 1;
			}
			else if(mn == score[i]) frq++;
		}
		if(frq > 1 || close == 6) goto skip;
		for(int i=0 ; i<7 ; i++) if(!lose[i] && score[i] == mn) lose[i] = true, close++;
		skip: ;
	}
	vector<pair<int, char>> v;
	for(int i=0 ; i<7 ; i++) if(!lose[i]) v.push_back({-score[i], 'A'+i});
	sort(v.begin(), v.end());
	printf("%d\n",v.size());
	for(auto x : v) printf("%c %d\n",x.second,-x.first);
	return 0;
}
