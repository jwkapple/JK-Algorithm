#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

enum Case
{
	NONE = 0,
	WALL,
	VIRUS
};
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MAX = 50 + 1;

std::vector<pii> virus;

bool active[11], data[MAX][MAX];

int map[MAX][MAX];
int N, M, total = 0, activeNum = 0;

int calc()
{
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			data[y][x] = false;
		}
	}
	std::queue<pii> Q;
	int value = 0, time = 0;

	for (int i = 0; i < virus.size(); ++i)
	{
		if (active[i])
		{
			Q.push(virus[i]);
			data[virus[i].first][virus[i].second] = true;
		}
	}

	while (!Q.empty())
	{
		int size = Q.size();

		if (value == total)
			break;
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
					if (map[Y][X] != WALL)
					{
						if (!data[Y][X])
						{
							if (map[Y][X] == NONE)
							{
								value++;
							}

							data[Y][X] = true;
							Q.push(pii(Y, X));
						}
					}
				}
			}
		}

		if (Q.empty())
			break;
		time++;
	}

	return value == total ? time : 1e9;
}
int func(int cur)
{
	if (cur == virus.size() && activeNum != M)
	{
		return 1e9;
	}
	if (activeNum == M)
	{
		return calc();
	}

	activeNum++;
	active[cur] = true;
	int on = func(cur + 1);

	activeNum--;
	active[cur] = false;
	int off = func(cur + 1);

	return on > off ? off : on;
}
int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> map[y][x];

			switch (map[y][x])
			{
			case NONE:
			{
				total++;
				break;
			}
			case WALL:
			{
				break;
			}
			case VIRUS:
			{
				virus.push_back(pii(y, x));
				break;
			}
			}
		}
	}

	int result = func(0);
	if (result == 1e9)
		std::cout << -1;
	else
		std::cout << result;
}