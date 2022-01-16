#include <iostream>
#include <string>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int MAX = 100 + 1;

bool visited[MAX][MAX];
char data[MAX][MAX];
int N, M, B, W;

int main()
{
	Init();

	std::cin >> M >> N;

	std::string tmp;
	for (int y = 1; y <= N; ++y)
	{
		std::cin >> tmp;
		for (int x = 1; x <= M; ++x)
		{
			data[y][x] = tmp[x - 1];
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			if (visited[y][x])
				continue;

			std::queue<pii> Q;
			int total = 0;

			char current = data[y][x];
			Q.push(pii(y, x));

			while (!Q.empty())
			{
				auto [tY, tX] = Q.front();
				Q.pop();
				if (visited[tY][tX])
					continue;

				visited[tY][tX] = true;
				total++;

				for (int i = 0; i < 4; ++i)
				{
					int Y = tY + dir[i][0];
					int X = tX + dir[i][1];

					if (Y > 0 && Y <= N && X > 0 && X <= M)
					{
						if (!visited[Y][X] && data[Y][X] == current)
						{
							Q.push(pii(Y, X));
						}
					}
				}
			}

			if (current == 'B')
				B += total * total;
			else
				W += total * total;
		}
	}
	std::cout << W << " " << B;
}