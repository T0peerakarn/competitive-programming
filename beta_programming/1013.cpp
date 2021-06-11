#include <bits/stdc++.h>
using namespace std;

char str[100];
vector<int> query;

vector<int> CheckPlus(int l, int r)
{
	vector<int> ret;
	int bracket = 0;
	for(int i=l ; i<=r ; i++)
	{
		if(str[i] == '(') bracket++;
		else if(str[i] == ')') bracket--;
		if(str[i] == '+' && bracket == 0) ret.push_back(i);
	}
	return ret;
}

vector<int> CheckMul(int l, int r)
{
	vector<int> ret;
	int bracket = 0;
	for(int i=l ; i<=r ; i++)
	{
		if(str[i] == '(') bracket++;
		else if(str[i] == ')') bracket--;
		if(str[i] == '*' && bracket == 0) ret.push_back(i);
	}
	return ret;
}

vector<int> CheckPow(int l, int r)
{
	vector<int> ret;
	int bracket = 0;
	for(int i=l ; i<=r ; i++)
	{
		if(str[i] == '(') bracket++;
		else if(str[i] == ')') bracket--;
		if(str[i] == '^' && bracket == 0) ret.push_back(i);
	}
	return ret;
}

void express(int l, int r, int i, int sz)
{
	if(i == sz)
	{
		for(int k=l ; k<=r ; k++) printf("%c",str[k]);
		printf("\n");
		return ;
	}

	vector<int> v;

	v = CheckPlus(l, r);
	if(l == r && v.size() == 0 && query[i] == 1)
	{
		express(l, r, i+1, sz);
		return ;
	}
	else if(v.size() != 0)
	{
		if(v.size()+1 < query[i])
		{
			printf("null\n");
			return ;
		}
		else
		{
			if(query[i] == 1) express(l, v[0]-1, i+1, sz);
			else if(query[i] == v.size() + 1) express(v.back()+1, r, i+1, sz);
			else express(v[query[i]-2]+1, v[query[i]-1]-1, i+1, sz);
			return ;
		}
	}

	v = CheckMul(l, r);
	if(l == r && v.size() == 0 && query[i] == 1)
	{
		express(l, r, i+1, sz);
		return ;
	}
	else if(v.size() != 0)
	{
		if(v.size()+1 < query[i])
		{
			printf("null\n");
			return ;
		}
		else
		{
			if(query[i] == 1) express(l, v[0]-1, i+1, sz);
			else if(query[i] == v.size() + 1) express(v.back()+1, r, i+1, sz);
			else express(v[query[i]-2]+1, v[query[i]-1]-1, i+1, sz);
			return ;
		}
	}

	v = CheckPow(l, r);
	if(l == r && v.size() == 0 && query[i] == 1)
	{
		express(l, r, i+1, sz);
		return ;
	}
	else if(v.size() != 0)
	{
		if(v.size()+1 < query[i])
		{
			printf("null\n");
			return ;
		}
		else
		{
			if(query[i] == 1) express(l, v[0]-1, i+1, sz);
			else if(query[i] == v.size() + 1) express(v.back()+1, r, i+1, sz);
			else express(v[query[i]-2]+1, v[query[i]-1]-1, i+1, sz);
			return ;
		}
	}

	bool bl = (str[l] == '('), br = (str[r] == ')');
	if(!bl || !br || query[i] > 1)
	{
		printf("null\n");
		return ;
	}
	express(l+1, r-1, i+1, sz);
}

int main()
{
	scanf(" %s",str+1);
	int n = strlen(str+1);
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		query.clear();
		while(true)
		{
			int d;
			scanf(" %d",&d);
			if(d == 0) break;
			query.push_back(d);
		}
		int sz = query.size();
		for(int i=sz-1 ; i>=0 ; i--) printf("op(%d,",query[i]);
		printf("p");
		for(int i=0 ; i<sz ; i++) printf(")");
		printf("=");
		express(1, n, 0, query.size());
	}
	return 0;
}
