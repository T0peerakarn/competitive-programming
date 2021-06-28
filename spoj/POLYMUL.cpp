#include <bits/stdc++.h>
using namespace std;

using CD = complex<double>;
const double PI = acos(-1);

void fft(vector<CD> &P, bool inv)
{
	int n = P.size();
	if(n == 1) return ;
	vector<CD> even(n>>1), odd(n>>1);
	for(int i=0 ; i<(n>>1) ; i++)
	{
		even[i] = P[i<<1];
		odd[i] = P[i<<1|1];
	}
	fft(even, inv);
	fft(odd, inv);
	double ang = 2 * PI / n * (inv ? -1 : 1);
	CD w(1), t(cos(ang), sin(ang));
	for(int i=0 ; i<(n>>1) ; i++, w*=t)
	{
		P[i] = even[i] + w * odd[i];
		P[i + (n>>1)] = even[i] - w * odd[i];
		if(inv) P[i]/=2, P[i + (n>>1)]/=2;
	}
}

void solve()
{
	int n, k=1;
	cin >> n;
	n++;
	while(k < n) k *= 2;
	k *= 2;
	vector<CD> p1(k, 0.0), p2(k, 0.0);
	for(int i=n-1 ; i>=0 ; i--) cin >> p1[i];
	for(int i=n-1 ; i>=0 ; i--) cin >> p2[i];
	fft(p1, false);
	fft(p2, false);
	for(int i=0 ; i<k ; i++) p1[i] *= p2[i];
	fft(p1, true);
	for(int i=n+n-2 ; i>=0 ; i--)
	{
		long long d = round(p1[i].real());
		cout << d << " ";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
