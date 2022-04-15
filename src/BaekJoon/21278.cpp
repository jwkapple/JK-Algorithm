#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int data[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		data[from][to] = data[to][from] = 1;
	}

	for (int a = 1; a <= N; ++a)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == a)
				continue;
			for (int x = y + 1; x <= N; ++x)
			{
				if (x == a)
					continue;
				if (!data[y][a] || !data[x][a])
					continue;

				int total = data[y][a] + data[x][a];

				if (data[y][x])
				{
					data[y][x] = data[y][x] > total ? total : data[y][x];
				}
				else
					data[y][x] = total;

				data[x][y] = data[y][x];
			}
		}
	}

	int result = 1e9, minX, minY;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = y + 1; x <= N; ++x)
		{
			int total = 0;
			for (int a = 1; a <= N; ++a)
			{
				if (y == a || x == a)
					continue;

				total += data[y][a] > data[x][a] ? data[x][a] : data[y][a];
			}

			if (result > total)
			{
				minY = y;
				minX = x;
				result = total;
			}
		}
	}

	std::cout << minY << " " << minX << " " << result * 2;
}