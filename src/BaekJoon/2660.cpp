#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 51;

int data[MAX][MAX];
int result[MAX];
int cur[MAX];
int N, mini = 55, current = 0;

int main()
{
	Init();

	std::cin >> N;

	int from, to;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = y; x <= N; ++x)
		{
			data[y][x] = mini; data[x][y] = mini;
		}
	}

	std::cin >> from >> to;
	while (from != -1 && to != -1)
	{
		data[from][to] = 1; data[to][from] = 1;
		cur[from] = 1; cur[to] = 1;

		std::cin >> from >> to;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (y == i || x == i || y == x) continue;

				if (data[y][i] && data[x][i])
				{
					if (data[y][x] > data[y][i] + data[i][x])
					{
						data[y][x] = data[y][i] + data[i][x];
						data[x][y] = data[y][x];
					}
				}

			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		std::sort(data[i], data[i] + N + 1);

		cur[i] = data[i][N - 1];
	}
	for (int i = 1; i <= N; ++i) { if (cur[i] < mini) mini = cur[i]; }

	for (int i = 1; i <= N; ++i) { if (cur[i] == mini) result[current++] = i; }

	std::cout << mini << " " << current << "\n";
	for (int i = 0; i < current; ++i) { std::cout << result[i] << " "; }
}