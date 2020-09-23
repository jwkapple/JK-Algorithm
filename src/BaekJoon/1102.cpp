#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 16;
const int IMPOSSIBLE = 1e9;

int data[MAX][MAX];
int dp[MAX][1 << MAX];

int N, P;
int size = 0;
int visited;

int TSP(int current, int visited)
{
	if (current >= P) return 0;

	int& ret = dp[current][visited];
	if (ret != -1) return ret;

	ret = IMPOSSIBLE;

	for (int i = 0; i < N; i++)
	{
		if ((visited & (1 << i)) == 0)
		{
			int work = IMPOSSIBLE;
			for (int j = 0; j < N; j++)
			{
				if (visited & (1 << j)) work = std::min(work, data[j][i]);
			}

			ret = std::min(ret, TSP(current + 1, visited | (1 << i)) + work);
		}
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

	std::string center;
	std::cin >> center;

	for (int i = 0; i < center.size(); i++)
	{
		if (center[i] == 'Y')
		{
			visited |= (1 << i);
			size++;
		}
	}

	std::cin >> P;

	if (size == 0)
	{
		if (P == 0) std::cout << 0;
		else std::cout << -1;
	}
	else std::cout << TSP(size, visited);
}