#include <iostream>
#include <queue>
#include <cstring>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 50 + 1;
int dir[4][2]{ {-1,0}, {1,0},{0,1},{0,-1} };

int map[MAX][MAX];
int data[MAX][MAX];
int res[3000];

int N, L, R, result = 0;
bool tag;

void func()
{
	while (true)
	{
		std::memset(data, 0, sizeof(data));
		int divNum = 1, cnt = 0, sum = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (data[i][j]) continue;
				std::queue<pii> Q;
				Q.push(pii(i, j));
				data[i][j] = divNum;

				while (!Q.empty())
				{
					auto [x, y] = Q.front(); Q.pop();
					sum += map[x][y];
					cnt++;

					for (int k = 0; k < 4; ++k)
					{
						int X = x + dir[k][0];
						int Y = y + dir[k][1];
						if (!data[X][Y])
						{
							if (X >= 0 && X < N && Y >= 0 && Y < N)
							{
								int diff = map[X][Y] - map[x][y];
								if (diff < 0) diff *= -1;
								if (diff < L || diff > R) continue;
								data[X][Y] = divNum;
								Q.push(pii(X, Y));
							}

						}
					}
				}
				res[divNum++] = sum / cnt;

				if (cnt >= 2) tag = true;
				cnt = 0; sum = 0;
			}
		}

		if (tag)
		{
			divNum = 1;
			result++;
			tag = false;
		}
		else return;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				map[i][j] = res[data[i][j]];
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> map[i][j];
		}
	}

	func();

	std::cout << result;
}
