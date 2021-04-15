#include <iostream>
#include <string>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 50 + 1;

std::queue<pii> Q;
bool visited[MAX][MAX];
int map[MAX][MAX], DP[MAX][MAX];
int N, M, result = 0;

int func(int y, int x)
{
	auto& ret = DP[y][x];
	int cur;

	if (visited[y][x]) return -1;

	if (ret) return ret + 1;

	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int Y = y + dir[i][0] * map[y][x];
		int X = x + dir[i][1] * map[y][x];

		if (Y > 0 && Y <= N && X > 0 && X <= M)
		{
			if (map[Y][X] != -1)
			{
				cur = func(Y, X);
				if (cur == -1) return -1;

				ret = cur > ret ? cur : ret;
			}
		}
	}

	visited[y][x] = false;

	return ret + 1;
}
int main()
{
	Init();

	std::cin >> N >> M;

	std::string tmp;
	for (int y = 1; y <= N; ++y)
	{
		std::cin >> tmp;
		for (int x = 1; x <= M; ++x)
		{
			if (tmp[x - 1] == 'H') map[y][x] = -1;
			else map[y][x] = tmp[x - 1] - '0';
		}
	}

	std::cout << func(1, 1);
}