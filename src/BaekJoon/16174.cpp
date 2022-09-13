#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[2][2] = {{1, 0}, {0, 1}};

const int MAX = 64 + 1;

std::queue<pii> Q;
bool visited[MAX][MAX];
int data[MAX][MAX];
int N;

int main()
{
	Init();

	std::cin >> N;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	Q.push(pii(1, 1));
	visited[1][1] = true;

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto [y, x] = Q.front();
			Q.pop();

			if (y == N && x == N)
			{
				std::cout << "HaruHaru";
				return 0;
			}

			int cur = data[y][x];

			for (int i = 0; i < 2; ++i)
			{
				int Y = y + dir[i][0] * cur;
				int X = x + dir[i][1] * cur;

				if (Y > 0 && Y <= N && X > 0 && X <= N)
				{
					if (!visited[Y][X])
					{
						visited[Y][X] = true;
						Q.push(pii(Y, X));
					}
				}
			}
		}
	}

	std::cout << "Hing";
}