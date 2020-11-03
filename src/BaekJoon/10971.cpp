#include <iostream>
#include <cstring>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 10;
const int IMPOSSIBLE = 1e9;
int data[MAX][MAX];
int dp[MAX][1 << MAX];

int N;

int TSP(int current, int visited)
{
	int& ref = dp[current][visited];
	if (ref != -1) return ref;

	if (visited == (1 << N) - 1)
	{
		if (data[current][0] != 0) return data[current][0];
		else return IMPOSSIBLE;
	}

	ref = IMPOSSIBLE;
	for (int i = 0; i < N; ++i)
	{
		if (visited & (1 << i) || data[current][i] == 0) continue;

		ref = std::min(ref, TSP(i, visited | (1 << i)) + data[current][i]);
	}

	return ref;
}
int main()
{
	Init();

	std::cin >> N;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	std::memset(dp, -1, sizeof(dp));

	std::cout << TSP(0, 1);
}