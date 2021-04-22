#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[3][2]{ {-1, 1}, {0, 1}, {1, 1} };
const int MAX = 1e4 + 1;

int visited[MAX][500 + 1];
int R, C, result = 0;

bool DFS(int y, int x)
{
	if (x == C) return true;

	for (int i = 0; i < 3; ++i)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (Y > 0 && Y <= R && X > 0 && X <= C)
		{
			if (!visited[Y][X])
			{
				visited[Y][X] = true;
				if (DFS(Y, X)) return true;
			}
		}
	}

	return false;
}
int main()
{
	Init();

	std::cin >> R >> C;

	char tmp;
	for (int y = 1; y <= R; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			std::cin >> tmp;
			if (tmp == 'x') visited[y][x] = true;
		}
	}

	for (int a = 1; a <= R; ++a)
	{
		if (DFS(a, 1)) result++;
	}

	std::cout << result;
}