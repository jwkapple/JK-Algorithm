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
	int H;

	Node(int y, int x, int h) : Y(y), X(x), H(h) {}
};
enum Case { NONE = 0, WALL };
const int MAX = 200 + 1;
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
int horse[8][2]{ {-2, -1}, {-2, 1}, {-1, -2},{-1, 2}, {1, -2},{1, 2}, {2, -1}, {2, 1} };

std::queue<Node> Q;
int data[MAX][MAX], DP[MAX][MAX][30 + 2];
int W, H, K, result = 0;

int main()
{
	Init();

	std::cin >> K;

	std::cin >> W >> H;

	for (int y = 1; y <= H; ++y)
	{
		for (int x = 1; x <= W; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	Q.push(Node(1, 1, 0));

	int current = 1;
	while (!Q.empty() && !result)
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x, h] = Q.front(); Q.pop();

			if (DP[y][x][h]) continue;

			DP[y][x][h] = current;

			if (y == H && x == W)
			{
				result = current;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= H && X > 0 && X <= W)
				{
					if (data[Y][X] != WALL) Q.push(Node(Y, X, h));
				}
			}

			if (h < K)
			{
				for (int i = 0; i < 8; ++i)
				{
					int Y = y + horse[i][0];
					int X = x + horse[i][1];

					if (Y > 0 && Y <= H && X > 0 && X <= W)
					{
						if (data[Y][X] != WALL) Q.push(Node(Y, X, h + 1));
					}
				}
			}
		}

		current++;
	}

	if (!result) std::cout << -1;
	else std::cout << result - 1;
}