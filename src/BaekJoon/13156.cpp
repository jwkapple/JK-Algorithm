#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 101;

int data[MAX][MAX]; // [seller][CPU]
int dp[MAX][MAX];
int C, M;

int func(int y, int x)
{
	int result = 0;
	for (int i = 0; i <= x; ++i)
	{
		result = std::max(result, data[y][i] + dp[y - 1][x - i]);
	}

	return result;
}
int main()
{
	Init();

	std::cin >> C >> M;

	int tmp;
	for (int y = 1; y <= M; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			std::cin >> tmp;
			data[y][x] = std::max(tmp, data[y][x - 1]);
		}
	}

	for (int y = 1; y <= M; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			dp[y][x] = func(y, x);
		}
	}

	std::cout << dp[M][C];
}