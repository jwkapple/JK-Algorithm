#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

const int MAX = 100 + 1;

std::vector<pii> data;
std::queue<pii> Q;
int map[MAX][MAX];
int N, M, result = 0, total = 0;

bool check(int y, int x)
{
	return (y > 0 || y <= N || x > 0 || x <= M);
}
int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> map[y][x];
			if (map[y][x] == 1) data.push_back(pii(y, x));
		}
	}

	std::queue<pii> tmp;
	tmp.push(pii(0, 0));

	while (!tmp.empty())
	{
		auto[y, x] = tmp.front();
		tmp.pop();

		if (map[y][x] == 1 || map[y][x] == -1) continue;

		map[y][x] = -1;

		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (Y >= 0 && Y <= N && X >= 0 && X <= M)
			{
				tmp.push(pii(Y, X));
			}
		}
	}

	while (true)
	{
		std::vector<pii> current;
		int size = 0;
		for (auto& p : data)
		{
			auto[y, x] = p;
			if (map[y][x] == -1) continue;

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (!check(Y, X)) continue;
				if (map[Y][X] == -1)
				{
					current.push_back(pii(y, x));
					Q.push(pii(y, x));
					size++;

					break;
				}
			}
		}

		if (total + size == data.size())
		{
			total = current.size();
			break;
		}

		total += size;
		for (auto& p : current)
		{
			auto[y, x] = p;
			map[y][x] = -1;
			tmp.push(pii(y, x));
		}

		while (!tmp.empty())
		{
			auto[y, x] = tmp.front();
			tmp.pop();

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (!check(Y, X)) continue;
				if (!map[Y][X])
				{
					map[Y][X] = -1;
					tmp.push(pii(Y, X));
				}
			}
		}

		result++;
	}

	std::cout << result + 1 << "\n" << total;
}