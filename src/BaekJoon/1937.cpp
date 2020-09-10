#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 501;

int N;
int max = 0;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int data[MAX][MAX];
int DP[MAX][MAX];

int dp(int x, int y)
{
	if (DP[x][y] != -1) return DP[x][y];

	for (int i = 0; i < 4; i++)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];

		if (X >= 0 && X < N && Y >= 0 && Y < N)
		{
			if (data[x][y] < data[X][Y]) DP[x][y] = dp(X, Y) + 1 > DP[x][y] ? dp(X, Y) + 1 : DP[x][y];
		}

	}

	if (DP[x][y] == -1) DP[x][y] = 1;

	max = max > DP[x][y] ? max : DP[x][y];

	return DP[x][y];
}
int main()
{
	Init();

	std::cin >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			DP[x][y] = -1;
		}
	}

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			std::cin >> data[x][y];
		}
	}

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			dp(x, y);
		}
	}

	std::cout << max;
}