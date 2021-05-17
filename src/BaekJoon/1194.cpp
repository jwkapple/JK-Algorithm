#include <iostream>
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

	Node(int y, int x, int v) : Y(y), X(x), V(v) {};
};
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 50 + 1;

std::queue<Node> Q;
char map[MAX][MAX];
int DP[MAX][MAX][1 << 5 + 1];
int R, C;

int main()
{
	Init();

	std::cin >> R >> C;

	char tmp;
	for (int y = 1; y <= R; ++y)
	{
		for (int x = 1; x <= C; ++x)
		{
			std::cin >> tmp;
			map[y][x] = tmp;
			if (tmp == '0') Q.push(Node(y, x, 0));
		}
	}

	int size, cur = 0;
	while (!Q.empty())
	{
		size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto[y, x, v] = Q.front(); Q.pop();
			if (DP[y][x][v] || map[y][x] == '#') continue;

			if (map[y][x] == '1')
			{
				std::cout << cur;
				return 0;
			}
			int ascii = map[y][x] - 65;
			if (ascii >= 0 && ascii <= 5)
			{
				if ((v & 1 << ascii) != 1 << ascii) continue;
			}

			DP[y][x][v] = cur;

			ascii = map[y][x] - 97;

			if (ascii >= 0 && ascii <= 5) v |= (1 << ascii);

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= R && X > 0 && X <= C)
				{
					Q.push(Node(Y, X, v));
				}
			}
		}

		cur++;
	}

	std::cout << -1;
}