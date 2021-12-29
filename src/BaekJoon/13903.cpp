#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::queue<pii> Q;
pii path[11];
int DP[MAX][MAX];
bool data[MAX][MAX];
int R, C, N, result;

int main()
{
	Init();

	std::cin >> R >> C;

	for (int y = 1; y <= R; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	std::cin >> N;

	int Y, X;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> Y >> X;

		path[i] = pii(Y, X);
	}

	int value = 1, size;
	for (int tX = 1; tX <= C; ++tX)
	{
		if (data[1][tX])
			Q.push(pii(1, tX));
	}

	while (!Q.empty())
	{
		size = Q.size();
		for (int a = 0; a < size; ++a)
		{
			auto [y, x] = Q.front();
			Q.pop();

			if (DP[y][x])
				continue;

			DP[y][x] = value;
			if (y == R)
			{
				result = value;
				break;
			}

			for (int i = 0; i < N; ++i)
			{
				Y = y + path[i].first;
				X = x + path[i].second;

				if (Y > 0 && Y <= R && X > 0 && X <= C)
				{
					if (data[Y][X])
						Q.push(pii(Y, X));
				}
			}
		}

		if (result)
			break;
		value++;
	}
	if (!result)
		std::cout << -1;
	else
		std::cout << result - 1;
}