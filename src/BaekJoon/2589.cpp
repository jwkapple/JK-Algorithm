#include <iostream>
#include <queue>
#include <cstring>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { LAND = 0, WATER };
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
const int MAX = 50 + 1;

bool visited[MAX][MAX];
int map[MAX][MAX];

int H, W, result = 0;

void BFS(int A, int B)
{
	std::queue<pii> Q;
	int current = 0;

	Q.push(pii(A, B));

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x] = Q.front(); Q.pop();

			if (visited[y][x]) continue;

			visited[y][x] = true;

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= H && X > 0 && X <= W)
				{
					if (map[Y][X] == LAND && !visited[Y][X]) Q.push(pii(Y, X));
				}
			}
		}
		current++;
	}

	result = result > current ? result : current;
}

int main()
{
	Init();

	std::cin >> H >> W;

	char tmp;
	for (int y = 1; y <= H;++y)
	{
		for (int x = 1; x <= W;++x)
		{
			std::cin >> tmp;

			if (tmp == 'W') map[y][x] = WATER;
			else map[y][x] = LAND;
		}
	}

	for (int y = 1; y <= H;++y)
	{
		for (int x = 1; x <= W;++x)
		{
			if (map[y][x] == LAND)
			{
				BFS(y, x);
				std::memset(visited, false, sizeof(visited));
			}
		}
	}

	std::cout << result - 1;
}