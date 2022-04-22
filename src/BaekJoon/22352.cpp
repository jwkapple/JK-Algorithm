#include <iostream>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX = 30 + 1;

std::queue<pii> Q;
bool visited[MAX][MAX];
int OG[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> OG[y][x];
		}
	}

	int dDiff = 0, tY = 0, tX = 0, size = 0;

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> tmp;

			if (OG[y][x] != tmp)
			{
				if (dDiff == 0)
				{
					dDiff = tmp;
					tY = y, tX = x;
				}
				else
				{
					if (dDiff != tmp || OG[tY][tX] != OG[y][x])
					{
						std::cout << "NO";
						return 0;
					}
				}

				size++;
			}
		}
	}

	Q.push(pii(tY, tX));

	int total = 0;
	while (!Q.empty())
	{
		auto [y, x] = Q.front();
		Q.pop();

		if (visited[y][x])
			continue;

		visited[y][x] = true;
		total++;

		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (Y > 0 && Y <= N && X > 0 && X <= M)
			{
				if (!visited[Y][X] && OG[y][x] == OG[Y][X])
				{
					Q.push(pii(Y, X));
				}
			}
		}
	}

	if (dDiff == 0)
	{
		std::cout << "YES";
	}
	else
	{
		if (total == size)
			std::cout << "YES";
		else
			std::cout << "NO";
	}
}