#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };

int map[MAX][MAX], data[MAX][MAX], visited[MAX][MAX];
int N, result = 1e6 + 1;

void dfs(int y, int x, int cnt)
{
	visited[y][x] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];
		if (X >= 0 && Y >= 0 && X < N && Y < N)
		{
			if (!visited[X][Y] && map[X][Y])
			{
				dfs(Y, X, cnt);
			}
		}
	}
}

int main(void)
{
	std::cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			std::cin >> map[y][x];

	int cnt = 0;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (!visited[y][x] && map[y][x])
			{
				dfs(y, x, ++cnt);
			}
		}
	}

	for (int k = 1; k <= cnt; ++k)
	{
		std::queue<pii> Q;
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
			{
				data[y][x] = -1;
				if (visited[y][x] == k)
				{
					Q.push(pii(y, x));
					data[y][x] = 0;
				}
			}

		while (!Q.empty())
		{
			auto[y, x] = Q.front(); Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (X >= 0 && Y >= 0 && X < N && Y < N)
				{
					if (data[Y][X] == -1)
					{
						data[Y][X] = data[y][x] + 1;
						Q.push(pii(Y, X));
					}
				}
			}
		}

		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
			{
				if (visited[y][x] != k && visited[y][x])
				{
					if (data[y][x] - 1 < result)
						result = data[y][x] - 1;
				}

			}
	}

	std::cout << result << "\n";
}