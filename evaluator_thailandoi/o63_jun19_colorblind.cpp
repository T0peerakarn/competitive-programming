#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;

string investivate_colors(int n)
{
	string ret = "R";
	int red = 1, blue = 0, normal = use_device(0, 1);
	for(int i=1 ; i<n+n-1 ; i+=2)
	{
		int now = use_device(i, i+1);
		if(now == normal)
		{
			if(ret[i-1] == 'R')
			{
				if(use_device(i-1, i+1) == now)
				{
					ret += "RR";
					red += 2;
				}
				else
				{
					ret += "BB";
					blue += 2;
				}
			}
			else
			{
				if(use_device(i-1, i+1) == now)
				{
					ret += "BB";
					blue += 2;
				}
				else
				{
					ret += "RR";
					red += 2;
				}
			}
		}
		else
		{
			if(red > blue)
			{
				ret += (now < normal) ? "RB" : "BR";
			}
			else
			{
				ret += (now < normal) ? "BR" : "RB";
			}
			red++, blue++;
		}
	}
	ret += (red < blue) ? "R" : "B";
	return ret;
}
