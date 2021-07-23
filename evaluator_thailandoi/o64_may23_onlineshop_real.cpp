#include "onlineshop.h"
#include <bits/stdc++.h>
using namespace std;


void sell_all(int N)
{
  int l = 1000, r = 1000000;
 	for(int i=0; i<N; i++)
 	{
 	  int mid = (l+r)>>1;
 		sell_price(mid) ? l = mid : r = mid-1;
 	}
}
