#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v(3);
  for(auto &x : v) scanf(" %d",&x);
  sort(v.begin(), v.end());
  printf((v[0] == 5 && v[1] == 5 && v[2] == 7) ? "YES\n" : "NO\n");
  return 0;
}
