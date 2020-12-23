#include <iostream>
#include <queue>
#include <climits>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 50 + 1;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

std::queue<pii> Q;
int visited[MAX][MAX];
int data[MAX][MAX];
int N;

bool check(int y, int x)
{
	if (y >= 1 && y <= N && x >= 1 && x <= N) return true;
	return false;
}
int main()
{
	Init();

	std::cin >> N;

	char tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;
			if (tmp == '1') data[y][x] = true;

			visited[y][x] = INT_MAX;
		}
	}

	Q.push(pii(1, 1));
	visited[1][1] = 0;
	while (!Q.empty())
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto[y, x] = Q.front();
			Q.pop();

			for (int a = 0; a < 4; ++a)
			{
				int Y = y + dir[a][0];
				int X = x + dir[a][1];

				if (check(Y, X))
				{
					if (data[Y][X])
					{
						if (visited[Y][X] > visited[y][x])
						{
							visited[Y][X] = visited[y][x];
							Q.push(pii(Y, X));
						}
					}
					else
					{
						if (visited[Y][X] > visited[y][x] + 1)
						{
							visited[Y][X] = visited[y][x] + 1;
							Q.push(pii(Y, X));
						}
					}
				}
			}
		}
	}
	std::cout << visited[N][N];
}