#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val, sub, pri;
	bool rev;
	node *l, *r;
	node(int a)
	{
		val = a;
		sub = 1;
		pri = rand();
		rev = false;
		l = r = NULL;
	}
};

int Get_sub(node *t)
{
	return (t) ? t->sub : 0;
}

void Lazy(node *t)
{
	if(!t) return;
	if(t->rev)
	{
		swap(t->l, t->r);
		if(t->l) t->l->rev ^= true;
		if(t->r) t->r->rev ^= true;
		t->rev = false;
	}
}

void Update(node *t)
{
	if(!t) return;
	t->sub = Get_sub(t->l) + 1 + Get_sub(t->r);
}

void Split(node *t, node *&l, node *&r, int key, int add)
{
	Lazy(t);
	if(!t) return void(l = r = NULL);
	int now = Get_sub(t->l) + 1 + add;
	if(now <= key)
	{
		Split(t->r, t->r, r, key, now);
		l = t;
	}
	else
	{
		Split(t->l, l, t->l, key,add);
		r = t;
	}
	Update(t);
}

void Merge(node *&t, node *l, node *r)
{
	Lazy(l), Lazy(r);
	if(!l || !r)
	{
		t = (l) ? l : r;
	}
	else if(l->pri > r->pri)
	{
		Merge(l->r, l->r, r);
		t = l;
	}
	else
	{
		Merge(r->l, l, r->l);
		t = r;
	}
	Update(t);
}

int Query(node *t)
{
	Lazy(t);
	if(!t->l) return t->val;
	return Query(t->l);
}

void Reverse(node *&t, int key)
{
	node *L, *R;
	Split(t, L, R, key, 0);
	if(L) L->rev ^= true;
	Merge(t, L, R);
}

int main()
{
	node *root = NULL;
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		Merge(root, root, new node(d));
	}
	for(int i=0 ; true ; i++)
	{
		int left = Query(root);
		if(left == 1)
		{
			printf("%d\n",i);
			return 0;
		}
		else
		{
			Reverse(root, left);
		}
	}
	return 0;
}
