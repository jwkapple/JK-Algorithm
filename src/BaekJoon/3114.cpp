#include <iostream>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[3][2]{ {1,0},{1, 1}, {0, 1} };
enum Case { DOWN, DIAGONAL, RIGHT };
const int MAX = 1500 + 1;

int DP[MAX][MAX];
pii map[MAX][MAX];
int R, C;
int result = 0;

int get(int y, int x)
{
	int A = map[R][x].first - map[y][x].first;
	int B = map[y - 1][x].second;

	return A + B;
}

int func(int y, int x)
{
	auto& ret = DP[y][x];
	if (ret) return ret;

	if (x == C && y == R) return ret = map[R - 1][C].second;

	int max = 0, value = 0, Y, X;
	bool isBottom = y == R;
	bool isCorner = x == C;
	for (int i = 0; i < 3; ++i)
	{
		Y = y + dir[i][0];
		X = x + dir[i][1];

		if (isBottom)
		{
			if (i == DIAGONAL || i == DOWN) continue;
		}
		if (isCorner)
		{
			if (i == DIAGONAL || i == RIGHT) continue;
		}

		if (i == DOWN)
		{
			int current = map[y][x].second - map[y - 1][x].second;
			value = func(Y, X) - current;
		}
		else value = get(y, x) + func(Y, X);
		max = value > max ? value : max;
	}

	return ret = max;
}

int main()
{
	Init();

	std::cin >> R >> C;

	char c;
	int tmp;

	for (int y = 1; y <= R; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			auto[pA, pB] = map[y - 1][x];

			std::cin >> c >> tmp;

			if (c == 'A') map[y][x] = pii(pA + tmp, pB);
			else map[y][x] = pii(pA, pB + tmp);
		}
	}

	std::cout << func(1, 1);
}