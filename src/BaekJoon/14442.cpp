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
	int W;

	Node(int y, int x, int w) : Y(y), X(x), W(w) {};
};
int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 1000 + 2;

std::queue<Node> Q;
int map[MAX][MAX], DP[MAX][MAX][11];
int N, M, K, result;

int main()
{
	Init();

	std::cin >> N >> M >> K;

	char tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> tmp;
			map[y][x] = tmp - '0';
		}
	}

	int current = 1;
	Q.push(Node(1, 1, 0));

	while (!Q.empty() && !result)
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x, w] = Q.front(); Q.pop();

			if (DP[y][x][w]) continue;
			if (y == N && x == M)
			{
				result = current;
				break;
			}
			DP[y][x][w] = current;

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (Y > 0 && Y <= N && X > 0 && X <= M)
				{
					if (map[Y][X] == 1)
					{
						if (w < K) Q.push(Node(Y, X, w + 1));
					}
					else Q.push(Node(Y, X, w));
				}

			}
		}

		current++;
	}

	if (!result) std::cout << -1;
	else std::cout << result;
} 