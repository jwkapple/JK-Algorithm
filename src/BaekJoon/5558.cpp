#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Y;
	int X;
	int S;

	Node(int y, int x, int s) : Y(y), X(x), S(s) {};
};

const int WALL = 11;
int dir[4][2]{ {-1,0},{1, 0},{0, -1},{0,1} };
const int MAX = 1000 + 1;

std::queue<Node> Q;
int map[MAX][MAX], DP[MAX][MAX][10];
int H, W, N, result = 0;

int main()
{
	Init();

	std::cin >> H >> W >> N;

	char tmp;
	for (int y = 1; y <= H; ++y)
	{
		for (int x = 1; x <= W; ++x)
		{
			std::cin >> tmp;

			switch (tmp)
			{
			case 'S': Q.push(Node(y, x, 1)); break;
			case 'X': map[y][x] = WALL; break;
			case '.': map[y][x] = 0; break;
			default: map[y][x] = tmp - '0'; break;
			}
		}
	}

	int current = 0, max = 1;
	while (!Q.empty() && !result)
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x, s] = Q.front(); Q.pop();

			if (DP[y][x][s] || max != s) continue;
			DP[y][x][s] = true;
			if (map[y][x] == s) { max = ++s; }
			if (s == N + 1) { result = current; break; }
			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];
				if (Y > 0 && Y <= H && X > 0 && X <= W)
				{
					if (map[Y][X] != WALL) Q.push(Node(Y, X, s));
				}
			}
		}

		current++;
	}

	std::cout << result;
}