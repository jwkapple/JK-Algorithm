#include <iostream>
#include <climits>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 401;

int V, E;
int result = INT_MAX;
int data[MAX][MAX];

int main()
{
	Init();

	std::cin >> V >> E;

	int from, to, v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		data[from][to] = v;
	}

	for (int i = 1; i <= V; ++i)
	{
		for (int y = 1; y <= V; ++y)
		{
			for (int x = 1; x <= V; ++x)
			{
				if (y == x || y == i || x == i) continue;

				if (!data[y][i] || !data[i][x]) continue;

				int current = data[y][i] + data[i][x];

				if (!data[y][x]) data[y][x] = current;
				else data[y][x] = data[y][x] > current ? current : data[y][x];
			}
		}
	}

	for (int y = 1; y <= V; ++y)
	{
		for (int x = y + 1; x <= V; ++x)
		{
			if (!data[y][x] || !data[x][y]) continue;

			int value = data[y][x] + data[x][y];
			result = result > value ? value : result;
		}
	}

	if (result == INT_MAX) std::cout << -1;
	else std::cout << result;
}