#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
const int MAX = 300 + 2;

bool visited[MAX][MAX];
int map[MAX][MAX];
std::queue<pii> melt;
std::vector<pii> iceberg;
int H, W, result = 0, current = 0;

void check()
{
	for (auto p : iceberg)
	{
		int cur = 0;
		auto[y, x] = p;

		if (map[y][x])
		{
			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= H && X > 0 && X <= W)
				{
					if (!map[Y][X]) cur++;
				}
			}

			if (map[y][x] - cur <= 0) melt.push(pii(y, x));
			else map[y][x] -= cur;
		}
	}
}
void BFS(int A, int B)
{
	std::queue<pii> Q;

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
					if (map[Y][X]) Q.push(pii(Y, X));
				}
			}
		}
	}
}
void func()
{
	while (!melt.empty())
	{
		auto[y, x] = melt.front(); melt.pop();

		map[y][x] = 0;
	}
}
int main()
{
	Init();

	std::cin >> H >> W;

	for (int y = 1; y <= H;++y)
	{
		for (int x = 1; x <= W;++x)
		{
			std::cin >> map[y][x];

			if (map[y][x]) iceberg.push_back(pii(y, x));
		}
	}

	current = iceberg.size();
	int t = 1;
	while (!result)
	{
		std::memset(visited, false, sizeof(visited));

		int ice = 0;
		check();
		for (auto p : iceberg)
		{
			auto[y, x] = p;

			if (map[y][x] && !visited[y][x])
			{
				BFS(y, x);

				ice++;
			}
		}

		if (ice == 0) { result = -1; break; }
		if (ice != 1) { result = t; break; }

		func();
		t++;
	}

	if (result == -1) std::cout << 0;
	else std::cout << result - 1;
}