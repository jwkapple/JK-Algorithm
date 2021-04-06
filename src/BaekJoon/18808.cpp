#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { ZERO, NINE, EIGHT, SEVEN };
const int MAX = 40 + 1;

std::vector<pii> size;
int map[MAX][MAX], stickers[100 + 1][10 + 1][10 + 1];
int N, M, K, result = 0;

bool match(int y, int x, int num, int rot)
{
	auto& cur = stickers[num];
	auto[R, C] = size[num];
	switch (rot)
	{
	case ZERO:
	{
		for (int Y = 1; Y <= R; ++Y)
		{
			for (int X = 1; X <= C; ++X)
			{
				if (cur[Y][X] && map[Y][X]) return false;
			}
		}
		break;
	}
	case NINE:
	{
		for (int Y = 1; Y <= C; ++Y)
		{
			for (int X = 1; X <= R; ++X)
			{
				if (cur[Y][R - X + 1] && map[Y][X]) return false;
			}
		}
		break;
	}
	case EIGHT:
	{
		for (int Y = 1; Y <= R; ++Y)
		{
			for (int X = 1; X <= C; ++X)
			{
				if (cur[R - Y + 1][C - X + 1] && map[Y][X]) return false;
			}
		}

		break;
	}
	case SEVEN:
	{
		for (int Y = 1; Y <= C; ++Y)
		{
			for (int X = 1; X <= R; ++X)
			{
				if (cur[C - Y + 1][X] && map[Y][X]) return false;
			}
		}

		break;
	}
	}

	return true;
}

void attach(int y, int x, int num, int rot)
{
	auto& cur = stickers[num];
	auto[R, C] = size[num];
	switch (rot)
	{
	case ZERO:
	{
		for (int Y = 1; Y <= R; ++Y)
		{
			for (int X = 1; X <= C; ++X)
			{
				if (cur[Y][X]) { map[Y][X] = 1; result++; }
			}
		}
		break;
	}
	case NINE:
	{
		for (int Y = 1; Y <= C; ++Y)
		{
			for (int X = 1; X <= R; ++X)
			{
				if (cur[Y][R - X + 1]) { map[Y][X] = 1; result++; }
			}
		}
		break;
	}
	case EIGHT:
	{
		for (int Y = 1; Y <= R; ++Y)
		{
			for (int X = 1; X <= C; ++X)
			{
				if (cur[R - Y + 1][C - X + 1]) { map[Y][X] = 1; result++; }
			}
		}

		break;
	}
	case SEVEN:
	{
		for (int Y = 1; Y <= C; ++Y)
		{
			for (int X = 1; X <= R; ++X)
			{
				if (cur[C - Y + 1][X]) { map[Y][X] = 1; result++; }
			}
		}

		break;
	}
	}

}
int main()
{
	Init();

	std::cin >> N >> M >> K;

	size.push_back(pii(0, 0));

	int R, C;
	for (int a = 1; a <= K; ++a)
	{
		std::cin >> R >> C;

		size.push_back(pii(R, C));
		for (int y = 1; y <= R; ++y)
		{
			for (int x = 1; x <= C; ++x)
			{
				std::cin >> stickers[a][y][x];
			}
		}
	}

	for (int a = 1; a <= K; ++a) // 각 스티커
	{
		for (int i = 0; i < 4; ++i)  // 돌림경우
		{
			bool isDone = false;
			for (int y = 1; y <= N; ++y)
			{
				for (int x = 1; x <= M; ++x)
				{
					if (match(y, x, a, i))
					{
						attach(y, x, a, i);
						isDone = true;
						break;
					}
				}

				if (isDone) break;
			}

			if (isDone) break;
		}
	}

	std::cout << result;
}