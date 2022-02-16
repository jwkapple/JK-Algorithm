#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	int L;
	int Y;
	int X;

	Node(){};

	Node(int l, int x, int y) : L(l), Y(y), X(x){};
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX = 30 + 1;

std::vector<int> result;
bool map[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int L, R, C;
int eL, eX, eY;

int main()
{
	Init();

	std::cin >> L >> R >> C;

	char tmp;
	int current = 1;
	while (L && R && C)
	{
		int time = 0;
		std::queue<Node> Q;
		for (int l = 1; l <= L; ++l)
		{
			for (int y = 1; y <= R; ++y)
			{
				for (int x = 1; x <= C; ++x)
				{
					std::cin >> tmp;

					switch (tmp)
					{
					case 'S':
					{
						Q.push(Node(l, y, x));
						break;
					}
					case 'E':
					{
						eL = l;
						eY = y;
						eX = x;
						break;
					}
					case '#':
					{
						map[l][y][x] = 1;
						break;
					}
					}
				}
			}
			std::cin >> tmp;
		}

		bool isDone;
		int size;
		while (!Q.empty())
		{
			size = Q.size();

			for (int a = 0; a < size; ++a)
			{
				auto [l, y, x] = Q.front();
				Q.pop();

				if (l == eL && y == eY && x == eX)
				{
					result.push_back(time);
					isDone = true;
					break;
				}

				visited[l][y][x] = current;

				for (int i = 0; i < 4; ++i)
				{
					int Y = y + dir[i][0];
					int X = x + dir[i][1];

					if (Y > 0 && Y <= R && X > 0 && X <= C)
					{
						if (!map[l][Y][X] && visited[l][Y][X] != current)
						{
							Q.push(Node(l, Y, X));
							visited[l][Y][X] = current;
						}
					}
				}

				if (++l <= L)
				{
					if (!map[l][y][x] && visited[l][y][x] != current)
					{
						Q.push(Node(l, y, x));
						visited[l][y][x] = current;
					}
				}

				l -= 2;

				if (l > 0)
				{
					if (!map[l][y][x] && visited[l][y][x] != current)
					{
						Q.push(Node(l, y, x));
						visited[l][y][x] = current;
					}
				}
			}

			if (isDone)
				break;
			time++;
		}

		if (!isDone)
			result.push_back(-1);
		std::cin >> L >> R >> C;
		current++;
	}

	for (auto p : result)
	{
		if (p == -1)
		{
			std::cout << "Trapped!\n";
		}
		else
			std::cout << "Escaped in " << p << " minute(s).\n";
	}
}