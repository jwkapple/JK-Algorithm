#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int Dir[4][2]{ {-1, 0},{1, 0},{0, -1}, {0,1} };
enum Case { NONE = 0, WALL, KEN };

const int MAX = 100 + 1;

bool map[MAX][MAX], visited[MAX][MAX], kVisit[MAX][MAX], active;
std::queue<pii> Q;
int H, W, T, kY, kX;
int sResult = 1e9, kResult = 1e9;

int main()
{
	Init();

	std::cin >> H >> W >> T;

	int tmp;
	for (int y = 1; y <= H; ++y)
	{
		for (int x = 1; x <= W; ++x)
		{
			std::cin >> tmp;

			if (tmp == KEN) { kY = y, kX = x; }
			else map[y][x] = tmp;
		}
	}

	Q.push(pii(1, 1));

	int num = 0, size, Y, X;
	while (!Q.empty() && !sResult)
	{
		size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x] = Q.front(); Q.pop();

			if (visited[y][x]) continue;
			visited[y][x] = true;

			if (y == H && x == W)
			{
				sResult = num;
				active = true;
				break;
			}

			if (y == kY && x == kX) kResult = num;

			for (int i = 0; i < 4; ++i)
			{
				Y = y + Dir[i][0];
				X = x + Dir[i][1];

				if (!visited[Y][X]) Q.push(pii(Y, X));
			}
		}
		num++;
	}

	while (!Q.empty()) { Q.pop(); }

	bool done = false;
	Q.push(pii(kY, kX));
	num = 0;
	while (!Q.empty() && !done)
	{
		size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto[y, x] = Q.front(); Q.pop();

			if (kVisit[y][x]) continue;
			kVisit[y][x] = true;

			if (y == H && x == W)
			{
				kResult += num;
				active = true;
				done = true;
				break;
			}
		}
		num++;
	}

	if (!active) std::cout << "Fail";

	if (sResult < kResult) std::cout << sResult;
	else std::cout << kResult;
}