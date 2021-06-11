#include <bits/stdc++.h>
using namespace std;

struct Rice
{
	double price, weight;
	bool operator < (const Rice & o) const
	{
		return price > o.price;
	}
};

priority_queue<Rice> heap;

int main()
{
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		double p, w;
		scanf(" %lf %lf",&p,&w);
		heap.push({p/w, w});
	}
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		double w, ans = 0;
		scanf(" %lf",&w);
		while(true)
		{
			if(heap.top().weight >= w)
			{
				ans += heap.top().price * w;
				Rice now = {heap.top().price, heap.top().weight - w};
				heap.pop();
				if(now.weight > 0) heap.push(now);
				break;
			}
			else
			{
				ans += heap.top().price*heap.top().weight;
				w -= heap.top().weight;
				heap.pop();
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
