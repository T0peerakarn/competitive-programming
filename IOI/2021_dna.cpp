#include "dna.h"
#include <bits/stdc++.h>
using namespace std;
 
#define N 100005

int n;
int cnt_char[2][3][N], cnt_dif[6][N];
map<char, int> mp_char;
map<string, int> mp_str;
string a, b;

string get_string(int i)
{
	string ret = "";
	ret += a[i];
	ret += b[i];
	return ret;
}

void init(string _a, string _b)
{
	a = _a, b = _b;
	n = a.length();
	mp_char['A'] = 0;
	mp_char['T'] = 1;
	mp_char['C'] = 2;
	mp_str["AT"] = 0;
	mp_str["AC"] = 1;
	mp_str["TA"] = 2;
	mp_str["TC"] = 3;
	mp_str["CA"] = 4;
	mp_str["CT"] = 5;
	cnt_char[0][mp_char[a[0]]][1]++;
	cnt_char[1][mp_char[b[0]]][1]++;
	if(a[0] != b[0]) cnt_dif[mp_str[get_string(0)]][1]++;
	for(int i=2 ; i<=n ; i++)
	{
		cnt_char[0][mp_char[a[i-1]]][i]++;
		cnt_char[1][mp_char[b[i-1]]][i]++;
		for(int j=0 ; j<3 ; j++)
		{
			cnt_char[0][j][i] += cnt_char[0][j][i-1];
			cnt_char[1][j][i] += cnt_char[1][j][i-1];
		}
		if(a[i-1] != b[i-1]) cnt_dif[mp_str[get_string(i-1)]][i]++;
		for(int j=0 ; j<6 ; j++) cnt_dif[j][i] += cnt_dif[j][i-1];
	}
}
 
int get_distance(int x, int y)
{
	x++, y++;
	for(int j=0 ; j<3 ; j++) if(cnt_char[0][j][y]-cnt_char[0][j][x-1] != cnt_char[1][j][y]-cnt_char[1][j][x-1]) return -1;
	int ret = 0, mn;
	int at = cnt_dif[0][y] - cnt_dif[0][x-1];
	int ac = cnt_dif[1][y] - cnt_dif[1][x-1];
	int ta = cnt_dif[2][y] - cnt_dif[2][x-1];
	int tc = cnt_dif[3][y] - cnt_dif[3][x-1];
	int ca = cnt_dif[4][y] - cnt_dif[4][x-1];
	int ct = cnt_dif[5][y] - cnt_dif[5][x-1];

	mn = min(at, ta);
	ret += mn;
	at -= mn;
	ta -= mn;

	mn = min(ac, ca);
	ret += mn;
	ac -= mn;
	ca -= mn;

	mn = min(tc, ct);
	ret += mn;
	tc -= mn;
	ct -= mn;

	ret += at+at+ac+ac;
	return ret;
}
