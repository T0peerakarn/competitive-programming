#include <bits/stdc++.h>
using namespace std;

using CD = complex<double>;
const double PI = acos(-1);

void fft(vector<CD> &P, bool inv)
{
	int n = P.size();
	if(n == 1) return ;
	vector<CD> even(n/2), odd(n/2);
	for(int i=0 ; i<n/2 ; i++)
	{
		even[i] = P[i*2];
		odd[i] = P[i*2+1];
	}
	fft(even, inv);
	fft(odd, inv);
	double ang = 2 * PI / n * (inv ? -1 : 1);
	CD w(1), t(cos(ang), sin(ang));
	for(int i=0 ; i<n/2 ; i++, w*=t)
	{
		P[i] = even[i] + w * odd[i];
		P[i + n/2] = even[i] - w * odd[i];
		if(inv) P[i]/=2, P[i+n/2]/=2;
	}
}

void solve()
{
	char a[300005], b[300005];
	cin >> a >> b;
	int la = strlen(a), lb = strlen(b), k=1;
	if((la == 1 && a[0] == '0') || (lb == 1 && b[0] == '0'))
	{
		cout << "0\n";
		return ;
	}
	while(k < la+lb) k*=2;
	vector<CD> p1(k), p2(k);
	for(int i=0 ; i<la ; i++) p1[i] = double(a[la-i-1] - '0');
	for(int i=0 ; i<lb ; i++) p2[i] = double(b[lb-i-1] - '0');
	fft(p1, false);
	fft(p2, false);
	for(int i=0 ; i<k ; i++) p1[i] *= p2[i];
	fft(p1, true);
	int shift = 0;
	bool start = false;
	stack<int> rev;
	for(int i=0 ; i<k ; i++)
	{
		int now = round(p1[i].real()) + shift;
		shift = now/10;
		now %= 10;
		rev.push(now);
	}
	while(!rev.empty())
	{
		if(rev.top() != 0) start = true;
		if(start) cout << rev.top();
		rev.pop();
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
