#include <iostream>
#include <queue>
#include <string>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };

struct Node
{
	int Y;
	int X;
	bool W;

	Node(int y, int x, bool w) : Y(y), X(x), W(w) {};
};

const int MAX = 1000 + 2;

std::queue<Node> Q;
bool visited[MAX][MAX][2];
int map[MAX][MAX];
int N, M, result = 0;

bool check(int y, int x, int w)
{
	return (y > 0 && y <= N && x > 0 && x <= M) && !visited[y][x][w];
}
int main()
{
	Init();

	std::cin >> N >> M;

	std::string tmp;
	for (int y = 1; y <= N; ++y)
	{
		std::cin >> tmp;
		for (int x = 1; x <= M; ++x)
		{
			map[y][x] = tmp[x - 1] - '0';
		}
	}

	Q.push(Node(1, 1, false));

	int current = 1;
	while (!Q.empty() && !result)
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto[y, x, w] = Q.front(); Q.pop();

			if (visited[y][x][w]) continue;

			visited[y][x][w] = true;
			if (y == N && x == M)
			{
				result = current;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (check(Y, X, w))
				{
					if (map[Y][X])
					{
						if (w) continue;
						else { Q.push(Node(Y, X, true)); }
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