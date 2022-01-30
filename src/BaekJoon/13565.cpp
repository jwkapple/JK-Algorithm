#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int MAX = 1000 + 1;

bool data[MAX][MAX], visited[MAX][MAX];

int H, W;

bool BFS(int y, int x)
{
	visited[y][x] = true;

	if (y == H)
		return true;

	for (int i = 0; i < 4; ++i)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (Y > 0 && Y <= H && X > 0 && X <= W)
		{
			if (!visited[Y][X] && !data[Y][X])
			{
				if (BFS(Y, X))
					return true;
			}
		}
	}

	return false;
}

int main()
{
	Init();

	std::cin >> H >> W;

	char tmp;
	for (int y = 1; y <= H; ++y)
	{
		for (int x = 1; x <= W; ++x)
		{
			std::cin >> tmp;
			data[y][x] = tmp - '0';
		}
	}

	for (int x = 1; x <= W; ++x)
	{
		if (visited[1][x] || data[1][x])
			continue;

		if (BFS(1, x))
		{
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";
}