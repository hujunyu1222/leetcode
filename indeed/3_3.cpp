#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R,C;
vector<vector<char> > square;
vector<pair<int,int> > add;
int count = 0;
int count_step = 0;

void putdown(vector<vector<char> > &squ, int i, int j)
{
	if(i >= R || j >= C)
		return;
	if(squ[i][j] == 'R')
		putdown(squ, i, j + 1);
	if(squ[i][j] == 'C')
		putdown(squ, i + 1, j);
	squ[i][j] = 'D';
}

int run()
{
	int step = 0;
	vector<vector<char> > squ = square;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(squ[i][j] != 'D')
			{
				putdown(squ, i, j);
				step++;
			}
		}
	}
	return step;
}

void backTracking(int pos)
{
	if(pos == add.size())
	{
		count_step += run();
		count++;
		return;
	}
	int m = add[pos].first;
	int n = add[pos].second;
	square[m][n] = 'R';
	backTracking(pos + 1);
	square[m][n] = 'C';
	backTracking(pos + 1);
}

int main()
{
	cin >> R >> C;
	square.resize(R);
	for(int i = 0; i < R; i++)
	{
		square[i].resize(C);
		for(int j = 0; j < C; j++)
		{
			cin >> square[i][j];
			if(square[i][j] == '?')
				add.push_back(pair<int,int>(i,j));
		}
	}
	backTracking(0);
	double pro = (double)count_step / count;
	cout << pro << endl;

	return 0;
}
