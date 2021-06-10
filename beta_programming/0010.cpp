#include <bits/stdc++.h>
using namespace std;

char str[55];
bool ball[4];

int main()
{
	ball[1] = true;
	scanf(" %s",str);
	int len = strlen(str);
	for(int i=0 ; i<len ; i++)
	{
		if(str[i] == 'A') swap(ball[1], ball[2]);
		else if(str[i] == 'B') swap(ball[2], ball[3]);
		else swap(ball[1], ball[3]);
	}
	for(int i=1 ; i<=3 ; i++)
		if(ball[i]) printf("%d\n",i);
	return 0;
}
