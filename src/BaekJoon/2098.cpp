#include <iostream>
#include <algorithm>
#include <cstring>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 16;

int N;

int data[MAX][MAX];
int dp[MAX][1 << 16];
const int IMPOSSIBLE = 1e9;

int TSP(int current, int visited)
{
	int& ret = dp[current][visited];

	if (ret != -1) return ret;

	if (visited == (1 << N) - 1)
	{
		if (data[current][0] != 0) return data[current][0];
		else return IMPOSSIBLE;
	}

	ret = IMPOSSIBLE;
	for (int i = 0;i < N; i++)
	{
		if (visited & (1 << i) || data[current][i] == 0) continue;

		ret = std::min(ret, TSP(i, visited | (1 << i)) + data[current][i]);
	}

	return ret;
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> data[i][j];
		}
	}

	std::memset(dp, -1, sizeof(dp));

	std::cout << TSP(0, 1);
}
