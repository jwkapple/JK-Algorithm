#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>
#define mkpr std::make_pair

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 51;

std::queue<pii> Water;
std::queue<pii> Hog;

enum variable { empty, hedgehog, water, stone, pot };

int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool visitedW[MAX][MAX];
bool visitedH[MAX][MAX];
int map[MAX][MAX];
pii Pot;
bool done = false;
int R, C, time = 0, result = 0;

void func(int Y, int X, char cur)
{
	switch (cur)
	{
	case 'D': map[Y][X] = pot; Pot = mkpr(Y, X); break;
	case 'X': map[Y][X] = stone; break;
	case 'S': map[Y][X] = hedgehog; Hog.push(mkpr(Y, X)); visitedH[Y][X] = true; break;
	case '*': map[Y][X] = water; Water.push(mkpr(Y, X));  visitedW[Y][X] = true; break;
	}
}

int main()
{
	Init();

	std::cin >> R >> C;

	char tmp;
	for (int y = 0; y < R; ++y)
	{
		for (int x = 0; x < C; x++)
		{
			std::cin >> tmp;
			func(y, x, tmp);
		}
	}

	while (!done)
	{
		time++;
		if (Hog.empty()) break;

		int size = Hog.size();
		for (int i = 0;i < size; ++i)
		{
			pii cur = Hog.front();
			Hog.pop();

			if (visitedW[cur.first][cur.second]) continue;

			for (int j = 0; j < 4; ++j)
			{
				int Y = cur.first + dir[j][0];
				int X = cur.second + dir[j][1];

				if (Y >= 0 && Y < R && X >= 0 && X < C)
				{
					if (!visitedH[Y][X] && map[Y][X] != stone && map[Y][X] != water)
					{
						if (map[Y][X] == pot)
						{
							done = true;
							result = time;
							break;
						}
						map[Y][X] = hedgehog;
						visitedH[Y][X] = true;
						Hog.push(mkpr(Y, X));
					}
				}
			}
		}

		size = Water.size();
		for (int i = 0; i < size; ++i)
		{
			pii cur = Water.front();
			Water.pop();

			if (cur.first == Pot.first && cur.second == Pot.second) continue;
			
			for (int j = 0; j < 4; ++j)
			{
				int Y = cur.first + dir[j][0];
				int X = cur.second + dir[j][1];

				if (Y >= 0 && Y < R && X >= 0 && X < C)
				{
					if (!visitedW[Y][X] && map[Y][X] != stone && map[Y][X] != pot)
					{
						map[Y][X] = water;
						visitedW[Y][X] = true;
						Water.push(mkpr(Y, X));
					}
				}
			}
		}
	}

	if (!result) std::cout << "KAKTUS";
	else std::cout << result;
}