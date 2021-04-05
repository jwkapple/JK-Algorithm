#include <iostream>
#include <string>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	pii First;
	pii Second;

	Node() {};
	Node(int fy, int fx, int sy, int sx) : First(pii(fy, fx)), Second(pii(sy, sx)) {};
	Node(pii f, pii s) : First(f), Second(s) {};
};
enum Case { NONE = 0, COIN, WALL };
const int MAX = 100 + 1;
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };

std::queue<Node> Q;
int map[MAX][MAX];
int H, W, result = 0;
pii EndY, EndX;

int isOut(pii First, pii Second)
{
	int v = 0;

	auto[y, x] = First;
	if (y > 0 && y <= H && x > 0 && x <= W) v++;
	y = Second.first, x = Second.second;
	if (y > 0 && y <= H && x > 0 && x <= W) v++;

	return v;
}
int main()
{
	Init();

	std::cin >> H >> W;

	Node start;
	std::string tmp;
	bool isFirst = true;
	for (int y = 1; y <= H; ++y)
	{
		std::cin >> tmp;
		for (int x = 1; x <= W; ++x)
		{
			switch (tmp[x - 1])
			{
			case '.': map[y][x] = NONE; break;
			case 'o':
			{
				if (isFirst) { start.First = pii(y, x); isFirst = false; }
				else { start.Second = pii(y, x); }
				break;
			}
			case '#': map[y][x] = WALL; break;
			}
		}
	}

	Q.push(start);

	int current = 0;
	while (!Q.empty() && !result)
	{
		if (current > 10) break;

		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[F, S] = Q.front(); Q.pop();

			int c = isOut(F, S);

			if (!c) continue;
			if (c == 1)
			{
				EndY = F, EndX = S;
				result = current;
			}

			if (result) break;

			pii iF, iS;
			for (int i = 0; i < 4; ++i)
			{
				auto[y, x] = F;
				int Y = y + dir[i][0];
				int X = x + dir[i][1];
				iF = map[Y][X] != WALL ? pii(Y, X) : pii(y, x);

				y = S.first, x = S.second;
				Y = y + dir[i][0];
				X = x + dir[i][1];
				iS = map[Y][X] != WALL ? pii(Y, X) : pii(y, x);
				Q.push(Node(iF, iS));
			}
		}
		current++;
	}

	if (current > 10) std::cout << -1;
	else std::cout << result;
}