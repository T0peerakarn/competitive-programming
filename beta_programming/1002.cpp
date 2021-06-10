#include <bits/stdc++.h>
using namespace std;

int cnt[5];

void f1(int n)
{
	if(n == 1 || n == 4 || n == 6 || n == 9) cnt[0] += 1;
	if(n == 2 || n == 7) cnt[0] += 2;
	if(n == 3 || n == 8) cnt[0] += 3;
	if(n == 4 || n == 5 || n == 6 || n == 7 || n == 8) cnt[1] += 1;
	if(n == 9 || n == 10) cnt[2] += 1;
}

void f10(int n)
{
	if(n == 1 || n == 4 || n == 6 || n == 9) cnt[2] += 1;
	if(n == 2 || n == 7) cnt[2] += 2;
	if(n == 3 || n == 8) cnt[2] += 3;
	if(n == 4 || n == 5 || n == 6 || n == 7 || n == 8) cnt[3] += 1;
	if(n == 9 || n == 10) cnt[4] += 1;
}

void f100(int n)
{
	if(n == 1 || n == 4) cnt[4] += 1;
	else if(n == 2) cnt[4] += 2;
	else if(n == 3) cnt[4] += 3;
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		int tmp = i;
		f1(tmp%10);
		tmp /= 10;
		f10(tmp%10);
		tmp /= 10;
		f100(tmp);
	}
	for(int i=0 ; i<5 ; i++) printf("%d ",cnt[i]);
	return 0;
}
