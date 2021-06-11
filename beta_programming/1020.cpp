#include <bits/stdc++.h>
using namespace std;

char str[205];

bool check(int l, int r)
{
	for(int i=l ; i<=r ; i++) if(str[i] != str[r-i+l]) return false;
	return true;
}

int main()
{
	scanf(" %s",str+1);
	int n = strlen(str+1);
	for(int i=1 ; i<=n ; i++) if(isalpha(str[i])) str[i] = tolower(str[i]);
	if(check(1, n))
	{
		if(check(1, n/2) && check((n+1)/2+1, n)) printf("Double ");
		printf("Palindrome\n");
	}
	else printf("No\n");
	return 0;
}
