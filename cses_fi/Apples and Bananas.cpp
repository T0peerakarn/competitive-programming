#include <bits/stdc++.h>
using namespace std;

typedef complex<double> CD;
const double PI = acos(-1);
const int N = 200005;
int cnt_a[N], cnt_b[N];

void fft(vector<CD> &P, bool inv)
{
	int n = P.size();
	for(int i=1, j=0 ; i<n ; i++)
	{
		int bit = n>>1;
		for( ; j&bit ; bit>>=1) j ^= bit;
		j ^= bit;
		if(i < j) swap(P[i], P[j]);
	}
	for(int len=2 ; len<=n ; len<<=1)
	{
		double ang = 2 * PI / len * (inv ? -1 : 1);
		CD t(cos(ang), sin(ang));
		for(int i=0 ; i<n ; i+=len)
		{
			CD w(1);
			for(int j=0 ; j<len/2 ; j++)
			{
				CD even = P[i+j], odd = w * P[i+j+len/2];
				P[i+j] = even + odd;
				P[i+j+len/2] = even - odd;
				w *= t;
			}
		}
	}
	if(inv) for(CD &x : P) x /= n;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		cin >> d;
		cnt_a[d]++;
	}
	for(int i=1 ; i<=m ; i++)
	{
		int d;
		cin >> d;
		cnt_b[d]++;
	}
	int K = 1;
	while(K < k*2) K *= 2;
	vector<CD> p1(K), p2(K);
	for(int i=1 ; i<=k ; i++) p1[i] = cnt_a[i], p2[i] = cnt_b[i];
	fft(p1, false), fft(p2, false);
	for(int i=0 ; i<K ; i++) p1[i] *= p2[i];
	fft(p1, true);
	for(int i=2 ; i<=k*2 ; i++) cout << (long long)(p1[i].real()+0.5) << ' ';
	return 0;
}
