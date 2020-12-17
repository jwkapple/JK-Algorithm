#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii std::pair<int, int>
#define mkpii std::make_pair
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 1000 + 1;

std::queue<pii> fireQ, SHQ;
std::vector<int> result;
bool visited[MAX][MAX], fire[MAX][MAX], wall[MAX][MAX], SH[MAX][MAX];
int T, W, H;

bool border(int y, int x, bool arr[MAX][MAX], bool Fire)
{
	if (!Fire) { Fire = !fire[y][x]; }
	return Fire && !arr[y][x] && !wall[y][x] && y >= 0 && y < H && x >= 0 && x < W;
}

void insert(pii pos, bool arr[MAX][MAX], std::queue<pii> Q, bool Fire)
{
	for (int i = 0; i < 4; ++i)
	{
		int Y = pos.first + dir[i][0];
		int X = pos.second + dir[i][1];

		if (border(Y, X, fire, Fire))
		{
			arr[Y][X] = true;
			Q.push(pii(Y, X));
		}
	}
}
void init(int w, int h)
{
	char tmp;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			wall[y][x] = false;
			visited[y][x] = false;
			fire[y][x] = false;
			SH[y][x] = false;

			std::cin >> tmp;
			switch (tmp)
			{
			case '#': wall[y][x] = true; break;
			case '*': fire[y][x] = true; fire[y][x] = true; fireQ.push(mkpii(y, x)); break;
			case '@': SH[y][x] = true; SH[y][x] = true; SHQ.push(mkpii(y, x)); break;
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> W >> H;

		init(W, H);

		while (!SHQ.empty())
		{
			int size = fireQ.size();
			pii cur;
			// fire case
			for (int i = 0; i < size; ++i)
			{
				auto[y, x] = fireQ.front();
				fireQ.pop();

				if (border(y, x, fire, true)) insert(cur, fire, fireQ, true);
			}

			size = SHQ.size();

			// SH case
			for (int i = 0; i < size; ++i)
			{
				auto[y, x] = SHQ.front();
				SHQ.pop();

				if (border(y, x, SH, false)) insert(cur, SH, SHQ, false);
			}
		}
	}
}