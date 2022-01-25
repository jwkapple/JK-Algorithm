#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;
int N;

int result[MAX];
bool data[MAX][MAX];
int main()
{
	Init();

	std::cin >> N;

	int from, to;
	for (int i = 1; i < N; ++i)
	{
		std::cin >> from >> to;

		data[from][to] = true;
		result[to]++;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == i)
				continue;

			for (int x = 1; x <= N; ++x)
			{
				if (y == x || x == i || data[y][x])
					continue;

				if (!data[y][i] || !data[i][x])
					continue;

				data[y][x] = true;
				result[x]++;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (result[i] == N - 1)
		{
			std::cout << i;
			return 0;
		}
	}

	std::cout << -1;
}