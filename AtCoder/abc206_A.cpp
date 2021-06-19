#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n *= 108;
	n /= 100;
	if(n < 206) cout << "Yay!\n";
	else if(n == 206) cout << "so-so\n";
	else cout << ":(\n";
	return 0;
}
