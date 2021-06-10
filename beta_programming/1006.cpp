#include <bits/stdc++.h>
using namespace std;

int arr[10];
char str[1010];

void Operate(char c)
{
	if(c == 'F')
	{
		int tmp = arr[1];
		arr[1] = arr[5];
		arr[5] = arr[6];
		arr[6] = arr[2];
		arr[2] = tmp;
	}
	else if(c == 'B')
	{
		int tmp = arr[1];
		arr[1] = arr[2];
		arr[2] = arr[6];
		arr[6] = arr[5];
		arr[5] = tmp;
	}
	else if(c == 'L')
	{
		int tmp = arr[1];
		arr[1] = arr[4];
		arr[4] = arr[6];
		arr[6] = arr[3];
		arr[3] = tmp;
	}
	else if(c == 'R')
	{
		int tmp = arr[1];
		arr[1] = arr[3];
		arr[3] = arr[6];
		arr[6] = arr[4];
		arr[4] = tmp;
	}
	else if(c == 'C')
	{
		int tmp = arr[2];
		arr[2] = arr[4];
		arr[4] = arr[5];
		arr[5] = arr[3];
		arr[3] = tmp;
	}
	else
	{
		int tmp = arr[2];
		arr[2] = arr[3];
		arr[3] = arr[5];
		arr[5] = arr[4];
		arr[4] = tmp;
	}
}

int main()
{
	int t;
	scanf(" %d",&t);
	vector<int> ans;
	while(t--)
	{
		scanf(" %s",str);
		int n = strlen(str);
		for(int i=1 ; i<=6 ; i++) arr[i] = i;
		for(int i=0 ; i<n ; i++) Operate(str[i]);
		ans.push_back(arr[2]);
	}
	for(auto x : ans)
		printf("%d ",x);
	return 0;
}
