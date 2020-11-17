#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 501;

int data[MAX][MAX];

int N, M, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;
		data[from][to] = 1;
		data[to][from] = 2;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (y == i || x == i || y == x) continue;

				if (data[y][i] == 1 && data[i][x] == 1) data[y][x] = 1;
				if (data[y][i] == 2 && data[i][x] == 2) data[y][x] = 2;
			}
		}
	}

	for (int x = 1; x <= N; ++x)
	{
		int cur = 0;
		for (int y = 1; y <= N; ++y)
		{
			if (data[y][x]) cur++;
		}

		if (cur == N - 1) result++;
	}

	std::cout << result;
}