#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int map[MAX][MAX];
int data[MAX][MAX];
int parent[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;

		map[from][to] = 1;
		if (!data[from][to]) data[from][to] = v;
		else
		{
			if (data[from][to] > v) data[from][to] = v;
		}
		parent[from][to] = to;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == i) continue;
			for (int x = 1; x <= N; ++x)
			{
				if (y == x || x == i || !data[y][i] || !data[i][x]) continue;

				int value = data[y][i] + data[i][x];
				if (!data[y][x] || value < data[y][x])
				{
					data[y][x] = value;
					parent[y][x] = parent[y][i];
					map[y][x] = map[y][i] + map[i][x];
				}

			}
		}
	}


	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cout << data[y][x] << " ";
		}
		std::cout << "\n";
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (!map[y][x]) { std::cout << 0 << "\n"; continue; }

			std::cout << map[y][x] + 1 << " " << y << " ";
			int cur = y;
			while (true)
			{
				std::cout << parent[cur][x] << " ";

				if (parent[cur][x] == x) break;

				cur = parent[cur][x];
			}

			std::cout << "\n";
		}
	}
}