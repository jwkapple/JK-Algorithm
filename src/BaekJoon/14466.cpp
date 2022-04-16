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

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MAX = 100 + 1;

std::vector<int> result;
int data[MAX][MAX];
bool road[MAX][MAX][4];
int N, K, R;

void path(int aY, int aX, int bY, int bX)
{
	if (aY == bY)
	{
		if (aX - bX < 0)
		{
			road[aY][aX][RIGHT] = true;
			road[aY][bX][LEFT] = true;
		}
		else
		{
			road[aY][aX][LEFT] = true;
			road[aY][bX][RIGHT] = true;
		}
	}
	else
	{
		if (aY - bY < 0)
		{
			road[aY][aX][DOWN] = true;
			road[bY][aX][UP] = true;
		}
		else
		{
			road[aY][aX][UP] = true;
			road[bY][aX][DOWN] = true;
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> K >> R;

	int aY, aX, bY, bX;
	for (int i = 0; i < R; ++i)
	{
		std::cin >> aY >> aX >> bY >> bX;
		path(aY, aX, bY, bX);
	}

	int value = 1;
	result.push_back(0);
	for (int i = 0; i < K; ++i)
	{
		std::cin >> aY >> aX;
		if (data[aY][aX])
		{
			result[data[aY][aX]]++;
		}
		else
		{
			result.push_back(1);

			std::queue<pii> Q;
			Q.push(pii(aY, aX));

			while (!Q.empty())
			{
				auto [y, x] = Q.front();
				Q.pop();

				if (data[y][x])
					continue;

				data[y][x] = value;

				for (int i = 0; i < 4; ++i)
				{
					if (road[y][x][i])
						continue;

					int Y = y + dir[i][0];
					int X = x + dir[i][1];

					if (Y > 0 && Y <= N && X > 0 && X <= N)
					{
						Q.push(pii(Y, X));
					}
				}
			}

			value++;
		}
	}

	int total = 0;

	for (auto p : result)
	{
		total += p * (K - p);
		K -= p;
	}

	std::cout << total;
}