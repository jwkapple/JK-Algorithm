#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { NONE = 0, WALL, FIRE, ME };
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 1000 + 5;

std::vector<int> result;
int map[MAX][MAX];
bool visited[MAX][MAX], visitF[MAX][MAX];
int T, H, W;

int main()
{
	Init();

	std::cin >> T;

	std::string tmp;

	while (T--)
	{
		std::queue<pii> Q, fire;

		bool isDone = false;
		int current = 0;

		std::cin >> W >> H;

		for (int y = 1; y <= H; ++y)
		{
			std::cin >> tmp;
			for (int x = 1; x <= W; ++x)
			{
				switch (tmp[x - 1])
				{
				case '.': map[y][x] = NONE; break;
				case '#': map[y][x] = WALL; break;
				case '*': map[y][x] = FIRE; fire.push(pii(y, x)); break;
				case '@': map[y][x] = ME;   Q.push(pii(y, x)); break;
				}
			}
		}

		while (!isDone)
		{
			int fireS = fire.size();

			for (int i = 0; i < fireS; ++i)
			{
				auto[y, x] = fire.front(); fire.pop();

				if (visitF[y][x]) continue;

				visitF[y][x] = true;
				for (int j = 0; j < 4; ++j)
				{
					int Y = y + dir[j][0];
					int X = x + dir[j][1];

					if (Y > 0 && Y <= H && X > 0 && X <= W)
					{
						if (map[Y][X] == NONE || map[Y][X] == ME)
						{
							if (!visitF[Y][X])
							{
								map[Y][X] = FIRE;
								fire.push(pii(Y, X));
							}
						}
					}
				}
			}

			int size = Q.size();
			if (!size)
			{
				result.push_back(-1);
				isDone = true;
				break;
			}

			for (int i = 0; i < size; ++i)
			{
				auto[y, x] = Q.front(); Q.pop();

				if (visited[y][x]) continue;

				visited[y][x] = true;

				map[y][x] = ME;
				for (int j = 0; j < 4; ++j)
				{
					int Y = y + dir[j][0];
					int X = x + dir[j][1];

					if (Y > 0 && Y <= H && X > 0 && X <= W)
					{
						if (map[Y][X] == NONE) Q.push(pii(Y, X));
					}
					else
					{
						result.push_back(current + 1);
						isDone = true;
						break;
					}
				}
				if (isDone) break;
			}

			if (isDone) break;

			current++;
		}
		for (int y = 0; y <= H; ++y)
		{
			for (int x = 0; x <= W; ++x)
			{
				map[y][x] = 0;
				visited[y][x] = false;
				visitF[y][x] = false;
			}
		}
	}

	for (auto p : result)
	{
		if (p < 0) std::cout << "IMPOSSIBLE\n";
		else std::cout << p << "\n";
	}
}