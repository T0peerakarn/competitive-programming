#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long key;
	int sub, pri;
	node *l, *r;
	node(long long a)
	{
		key = a;
		sub = 1;
		pri = rand();
		l = r = NULL;
	}
};

long long qs[200005];

int Sub(node *t) {return (t) ? t->sub : 0;}

void Update(node *t)
{
	if(!t) return ;
	t->sub = 1 + Sub(t->l) + Sub(t->r);
}

void Split(node *t, node *&l, node *&r, long long key)
{
	if(!t) return void(l = r = NULL);
	if(t->key <= key) Split(t->r, t->r, r, key), l = t;
	else Split(t->l, l, t->l, key), r = t;
	Update(t);
}

void Insert(node *&t, node *it)
{
	if(!t) t = it;
	else if(it->pri > t->pri) Split(t, it->l, it->r, it->key), t = it;
	else if(t->key <= it->key) Insert(t->r, it);
	else Insert(t->l, it);
	Update(t);
}

long long Query(node *t, long long key)
{
	if(!t) return 0;
	return (t->key <= key) ? Query(t->r, key) : Sub(t->r) + 1 + Query(t->l, key);
}

int main()
{
	int n;
	long long t, ans = 0;
	scanf(" %d %lld",&n,&t);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %lld",&qs[i]);
		qs[i] += qs[i-1];
	}
	node *root = new node(0);
	for(int i=1 ; i<=n ; i++)
	{
		ans += Query(root, qs[i]-t);
		Insert(root, new node(qs[i]));
	}
	printf("%lld\n",ans);
	return 0;
}
