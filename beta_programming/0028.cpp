#include <bits/stdc++.h>
using namespace std;

struct Football
{
	string name;
	int score, shoot, lose;
	bool operator < (const Football & o) const
	{
		return (score == o.score) ? (shoot-lose == o.shoot-o.lose) ? shoot > o.shoot : shoot-lose > o.shoot-o.lose : score > o.score;
	}	
};

int result[5][5];
Football arr[5];

int main()
{
	for(int i=1 ; i<=4 ; i++)
		getline(cin, arr[i].name);
	for(int i=1 ; i<=4 ; i++)
		for(int j=1 ; j<=4 ; j++)
			scanf(" %d",&result[i][j]);
	for(int i=1 ; i<=4 ; i++)
		for(int j=1 ; j<=4 ; j++)
		{
			if(i == j) continue;
			if(result[i][j] > result[j][i]) arr[i].score += 3;
			else if(result[i][j] == result[j][i]) arr[i].score += 1;
			arr[i].shoot += result[i][j];
			arr[i].lose += result[j][i];
		}
	sort(arr+1, arr+5);
	for(int i=1 ; i<=4 ; i++)
		cout << arr[i].name << ' ' << arr[i].score << endl;
	return 0;
}
