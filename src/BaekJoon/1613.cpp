#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const uint32_t MAX = 401;

int32_t data[MAX][MAX];
int32_t result[50001];

int N, K, S;

void func()
{
	for (uint32_t i = 1; i <= N; ++i)
	{
		for (uint32_t y = 1; y <= N; ++y)
		{
			for (uint32_t x = 1; x <= N; ++x)
			{
				if (y == i || x == i || y == x) continue;

				if ((!data[y][i] && !data[i][x]) || data[y][i] != data[i][x]) continue;

				data[y][x] = data[y][i];
			}
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> K;

	uint32_t from, to;
	for (uint32_t i = 0; i < K; ++i)
	{
		std::cin >> from >> to;
		data[from][to] = -1; data[to][from] = 1;
	}

	func();

	std::cin >> S;
	for (uint32_t i = 0; i < S; ++i)
	{
		std::cin >> from >> to;

		result[i] = data[from][to];
	}

	for (uint32_t i = 0; i < S; ++i)
	{
		std::cout << result[i] << "\n";
	}
}