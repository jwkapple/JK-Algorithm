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

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
enum Case
{
	NONE = 0,
	WALL,
	VIRUS
};
const int MAX = 50 + 1;

std::vector<pii> virus, data;
int map[MAX][MAX], path[MAX][MAX];

int N, M, size, total, current = 1;

int calc()
{
	std::queue<pii> Q;

	int value = 0;
	for (auto p : data)
	{
		auto [y, x] = p;
		Q.push(p);
		path[y][x] = current;
	}

	value += data.size();

	if (value == total)
		return 0;
	int time = 0;

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto [y, x] = Q.front();
			Q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= N && X > 0 && X <= N)
				{
					if (map[Y][X] != WALL && path[Y][X] != current)
					{
						Q.push(pii(Y, X));
						value++;
						path[Y][X] = current;
					}
				}
			}
		}

		if (value == total)
		{
			time++;
			break;
		}

		time++;
	}

	current++;

	return value != total ? -1 : time;
}

int func(int value, int num)
{
	if (num == M)
	{
		return calc();
	}

	int tmp, min = 1e9;
	auto &ret = data[num];

	int max = size - M + num + 1;

	for (int i = value; i < max; ++i)
	{
		auto [y, x] = virus[i];
		ret = pii(y, x);
		tmp = func(i + 1, num + 1);
		if (tmp == -1)
			continue;
		min = min > tmp ? tmp : min;
	}

	return min;
}
int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;

	data.resize(M);
	total = N * N;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;

			if (tmp == WALL)
				total--;
			if (tmp == VIRUS)
				virus.push_back(pii(y, x));

			map[y][x] = tmp;
		}
	}

	size = virus.size();

	int result = func(0, 0);

	if (result == 1e9)
		std::cout << -1;
	else
		std::cout << result;
}