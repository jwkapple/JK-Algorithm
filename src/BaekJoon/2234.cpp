#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {0,-1},{-1,0},{0,1},{1,0} };

const int MAX = 100 + 1;

int map[MAX][MAX], data[MAX * MAX], visited[MAX][MAX];
int N, M, result = 0, max = 0;

int DFS(int y, int x, int num)
{
	int total = 0;

	if (visited[y][x]) return 0;

	visited[y][x] = num;

	for (int i = 0; i < 4; ++i)
	{
		if ((map[y][x] & 1 << i) == 1 << i) continue;

		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (Y > 0 && Y <= N && X > 0 && X <= M) total += DFS(Y, X, num);
	}

	return total + 1;
}

int main()
{
	Init();

	std::cin >> M >> N;

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> map[y][x];
		}
	}

	int cur = 1;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			if (!visited[y][x])
			{
				data[cur] = DFS(y, x, cur);
				visited[y][x] = cur++;
			}

			for (int i = 0; i < 4; ++i)
			{
				if ((map[y][x] & 1 << i) == 1 << i)
				{
					int Y = y + dir[i][0];
					int X = x + dir[i][1];

					if (visited[Y][X] && visited[Y][X] != visited[y][x])
					{
						int value = data[visited[Y][X]] + data[visited[y][x]];
						max = max > value ? max : value;
					}
				}
			}
		}
	}

	for (int i = 1; i < cur; ++i)
	{
		result = result > data[i] ? result : data[i];
	}

	std::cout << cur - 1 << "\n";
	std::cout << result << "\n";
	std::cout << max;
}