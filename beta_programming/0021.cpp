#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int len = str.length();
	for(int i=0 ; i<len ; i++)
	{
		printf("%c",str[i]);
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') i+=2;
	}
	return 0;
}
