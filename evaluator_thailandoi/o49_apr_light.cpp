#include <bits/stdc++.h>
using namespace std;

struct node
{
	int l, r, v, laz;
	node *L, *R;
	node(int a, int b, int c)
	{
		l = a, r = b, v = c;
		laz = 0;
		L = R = NULL;
	}
};

void push_lazy(node *now)
{
	if(now->laz)
	{
		now->v = (now->r - now->l + 1) - now->v;
		if(now->l != now->r)
		{
			int mid = (now->l + now->r)>>1;
			if(!now->L) now->L = new node(now->l, mid, mid-now->l+1);
			if(!now->R) now->R = new node(mid+1, now->r, now->r-mid);
			now->L->laz ^= now->laz;
			now->R->laz ^= now->laz;
		}
		now->laz = 0;
	}
}

void update(node *now, int a, int b)
{
	push_lazy(now);
	if(now->r < a || b < now->l) return ;
	if(a <= now->l && now->r <= b)
	{
		now->laz ^= 1;
		push_lazy(now);
		return ;
	}
	int mid = (now->l + now->r)>>1;
	if(!now->L) now->L = new node(now->l, mid, mid-now->l+1);
	if(!now->R) now->R = new node(mid+1, now->r, now->r-mid);
	update(now->L, a, b), update(now->R, a, b);
	now->v = now->L->v + now->R->v;
}

int main()
{
	int l, q;
	scanf(" %d %d",&l,&q);
	node *root = new node(1, l, l); 
	while(q--)
	{
		int d;
		scanf(" %d",&d);
		update(root, d+1, l);
		printf("%d\n",root->v);
	}
	return 0;
}
