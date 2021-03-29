#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0}, {1,0}, {0,-1}, {0,1} };
const int MAX = 500 + 1;

int data[MAX][MAX], DP[MAX][MAX];
int N, M;

int DFS(int y, int x)
{
	if (y == N && x == M) return 1;
	auto& ret = DP[y][x];
	if (ret == -1) return 0;
	if (ret) return ret;

	for (int i = 0; i < 4; ++i)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (Y > 0 && Y <= N && X > 0 && X <= M)
		{
			if (data[Y][X] < data[y][x])
			{
				ret += DFS(Y, X);
			}
		}
	}

	if (!ret) { ret = -1; return 0; }
	else return ret;
}

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	std::cout << DFS(1, 1);
}