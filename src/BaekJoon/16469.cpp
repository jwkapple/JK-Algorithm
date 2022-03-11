#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX = 100 + 1;

bool data[MAX][MAX];
int path[MAX][MAX];
bool visited[MAX][MAX][3];
int R, C, T = 1;

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
			data[y][x] = (tmp == '1');
		}
	}

	int tY, tX, cur = 0;
	for (int i = 0; i < 3; ++i)
	{
		std::queue<pii> Q;
		std::cin >> tY >> tX;

		Q.push(pii(tY, tX));

		visited[tY][tX][cur] = true;
		while (!Q.empty())
		{
			int size = Q.size();

			for (int a = 0; a < size; ++a)
			{
				auto [y, x] = Q.front();
				Q.pop();

				if (path[y][x] < T)
					path[y][x] = T;

				for (int i = 0; i < 4; ++i)
				{
					int Y = y + dir[i][0];
					int X = x + dir[i][1];

					if (Y > 0 && Y <= R && X > 0 && X <= C)
					{
						if (!visited[Y][X][cur] && !data[y][x])
						{
							visited[Y][X][cur] = true;
							Q.push(pii(Y, X));
						}
					}
				}
			}

			T++;
		}

		T = 1;
		cur++;
	}

	int min = 1e9, num = 1;
	for (int y = 1; y <= R; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			if (data[y][x])
				continue;

			auto ref = visited[y][x];

			if (!ref[0] || !ref[1] || !ref[2])
				continue;

			auto temp = path[y][x];

			if (temp < min)
			{
				num = 1;
				min = temp;
			}
			else if (temp == min)
			{
				num++;
			}
		}
	}

	if (min == 1e9)
		std::cout << -1;
	else
		std::cout << min - 1 << "\n"
				  << num;
}