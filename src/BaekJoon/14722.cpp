#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

int data[MAX][MAX], DP[MAX][MAX][3];
int N;

int func(int y, int x, int v)
{
	if (y > N || x > N)
		return -1;

	if (y == N && x == N)
		return v == data[y][x];

	auto &ret = DP[y][x][v];

	if (ret)
		return ret;

	int down = 0, right = 0;
	int nDown = func(y + 1, x, v);
	int nRight = func(y, x + 1, v);

	int milk = v % 3;

	if (milk == data[y][x])
	{
		milk = (v + 1) % 3;
		down = func(y + 1, x, milk) + 1;
		right = func(y, x + 1, milk) + 1;
	}

	down = down > nDown ? down : nDown;
	right = right > nRight ? right : nRight;

	return ret = down > right ? down : right;
}
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

	std::cout << func(1, 1, 0);
}