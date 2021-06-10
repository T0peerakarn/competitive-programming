#include <bits/stdc++.h>
using namespace std;

int score[3];

int main()
{
	vector<vector<char>> answer = {{'A', 'B', 'C'}, {'B', 'A', 'B', 'C'}, {'C', 'C', 'A', 'A', 'B', 'B'}};
	int n, mx = 0;
	scanf(" %d",&n);
	for(int i=0 ; i<n ; i++)
	{
		char sol;
		scanf(" %c",&sol);
		for(int j=0 ; j<3 ; j++)
		{
			score[j] += (answer[j][i%answer[j].size()] == sol) ? 1 : 0;
			mx = max(mx, score[j]);
		}
	}
	printf("%d\n",mx);
	if(score[0] == mx) printf("Adrian\n");
	if(score[1] == mx) printf("Bruno\n");
	if(score[2] == mx) printf("Goran\n");
	return 0;
}
