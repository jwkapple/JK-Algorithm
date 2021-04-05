#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { NONE = 0, WALL };
const int MAX = 9;
int dir[9][2]{ {-1,0},{1,0},{0,-1},{0,1},{1, 1},{1, -1},{-1, 1}, {-1, -1},{0,0} };

std::queue<pii> Q;
bool visited[100][MAX][MAX];
int map[MAX][MAX];
int current = 0;
bool isDone = false;
int main()
{
	Init();

	char tmp;
	for (int y = 1; y < MAX; ++y)
	{
		for (int x = 1; x < MAX; ++x)
		{
			std::cin >> tmp;
			if (tmp == '#') map[y][x] = WALL;
			else			map[y][x] = NONE;
		}
	}

	Q.push(pii(8, 1));

	while (!Q.empty() && !isDone)
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x] = Q.front(); Q.pop();

			if (visited[current][y][x]) continue;
			visited[current][y][x] = true;
			if (y == 1 && x == 8) { isDone = true; break; }
			if (map[y - current][x] == WALL) continue;


			for (int i = 0; i < 9; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= 8 && X > 0 && X <= 8)
				{
					if (map[Y - current][X] != WALL) Q.push(pii(Y, X));
				}
			}
		}

		current++;
	}

	std::cout << isDone;
}