#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long a, b, sum_a, ans;
	int pri;
	node *l, *r;
	node(long long x, long long y)
	{
		a = sum_a = x;
		b = y;
		ans = x+y;
		pri = rand();
	}
};

long long Get_sum(node *t)
{
	return (t) ? t->sum_a : 0;
}

long long Get_ans(node *t)
{
	return (t) ? t->ans : 0;
}

void Update(node *t)
{
	if(!t) return;
	t->sum_a = t->a + Get_sum(t->l) + Get_sum(t->r);
	t->ans = max(t->a + t->b + Get_sum(t->r), max(Get_ans(t->l) + t->a + Get_sum(t->r), Get_ans(t->r)));
}

void Split(node *t, node *&l, node *&r, long long b)
{
	if(!t) return void(l = r = NULL);
	if(t->b <= b)
	{
		Split(t->r, t->r, r, b);
		l = t;
	}
	else
	{
		Split(t->l, l, t->l, b);
		r = t;
	}
	Update(t);
}


void Insert(node *&t, node *it)
{
	if(!t)
	{
		t = it;
	}
	else if(t->pri < it->pri)
	{
		Split(t, it->l, it->r, it->b);
		t = it;
	}
	else if(t->b <= it->b)
	{
		Insert(t->r, it);
	}
	else
	{
		Insert(t->l, it);
	}
	Update(t);
}

int main()
{
	int n, t;
	long long m1, m2, ans = 0;
	node *root = NULL;
	scanf(" %d %d %lld %lld",&n,&t,&m1,&m2);
	while(n--)
	{
		long long a, b;
		scanf(" %lld %lld",&a,&b);
		if(t == 2) a += (ans%m1), b += (ans%m2);
		Insert(root, new node(a, b));
		ans = Get_ans(root);
		printf("%lld\n",ans);
	}
	return 0;
}
