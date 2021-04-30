#include <iostream>
#include <cstring>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Y;
	int X;
	int V;

	Node() {};
	Node(int y, int x, int v) : Y(y), X(x), V(v) {};
};

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int bMAX = 1 << 9;
const int MAX = 50 + 2;

enum Case { NONE = 0, WALL = 6, END = 7 };
std::queue<Node> Q;
int map[MAX][MAX];
bool visited[MAX][MAX][bMAX];
int H, W;

int main()
{
	Init();

	std::cin >> W >> H;

	char tmp;
	int key = 0;
	for (int y = 1; y <= H; ++y)
	{
		for (int x = 1; x <= W; ++x)
		{
			std::cin >> tmp;

			switch (tmp)
			{
			case '#': map[y][x] = WALL; break;
			case 'X': map[y][x] = ++key; break;
			case 'E': map[y][x] = END; break;
			case 'S': Q.push(Node(y, x, 0)); break;
			}
		}
	}

	int num = 0;
	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x, v] = Q.front(); Q.pop();

			if (visited[y][x][v]) continue;

			visited[y][x][v] = true;

			if (map[y][x] == END)
			{
				if ((1 << (key + 1)) - 2 == v)
				{
					std::cout << num;
					return 0;
				}
			}

			if (map[y][x] >= 1 && map[y][x] < 6) v |= 1 << map[y][x];

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= H && X > 0 && X <= W)
				{
					if (map[Y][X] != WALL) Q.push(Node(Y, X, v));
				}
			}
		}

		num++;
	}
}