#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

bool visited[MAX][MAX];
int map[MAX][MAX], data[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		data[from][to] = v, data[to][from] = v;
		map[from][to] = to, map[to][from] = from;
		visited[from][to] = true;
	}

	for (int a = 1; a <= N; ++a)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == a) continue;
			for (int x = 1; x <= N; ++x)
			{
				if (x == a || y == x) continue;

				if (data[y][a] && data[a][x])
				{
					int value = data[y][a] + data[a][x];
					if (!data[y][x])
					{
						data[y][x] = value;
						map[y][x] = map[y][a];
					}
					else
					{
						if (data[y][x] > value)
						{
							data[y][x] = value;
							int A = map[y][a];
							while (true)
							{
								int tmp = map[y][A];
								if (visited[y][tmp]) break;
								A = tmp;
							}
							map[y][x] = A;
						}

					}
				}
			}
		}
	}

	for (int y = 1;y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (y == x) std::cout << "- ";
			else std::cout << map[y][x] << " ";
		}

		std::cout << "\n";
	}
}
