#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int len = str.length(), last = -1;
	double x = 0, y = 0;
	for(int i=0 ; i<len ; i++)
	{
		if(str[i] == '*') break;
		if(str[i] == ' ')
		{
			string direction = "";
			double walk = 0;
			for(int j=last+1; j<i ; j++)
			{
				if('0' <= str[j] && str[j] <= '9')
				{
					walk *= 10;
					walk += (str[j]-'0');
				}
				else direction += str[j];
			}
			last = i;
			double walks = walk / sqrt(2);
			if(direction == "N") y += walk;
			else if(direction == "S") y -= walk;
			else if(direction == "W") x -= walk;
			else if(direction == "E") x += walk;
			else if(direction == "NW") x -= walks, y += walks;
			else if(direction == "NE") x += walks, y += walks;
			else if(direction == "SW") x -= walks, y -= walks;
			else if(direction == "SE") x += walks, y -= walks;
		}
	}
	printf("%.3lf %.3lf\n%.3lf\n",x,y,sqrt(x*x+y*y));
	return 0;
}
