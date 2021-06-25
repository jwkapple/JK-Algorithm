#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int V;
	int Y;
	int X;

	Node() {};
	Node(int v, int y, int x) : V(v), Y(y), X(x) {};
};

bool operator>(Node L, Node R)
{
	return L.V > R.V;
}

int Dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };

const int INF = 1e9, MAX = 50 + 2, GARBAGE = -1, NEAR = 1, FINISH = 3;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
int map[MAX][MAX], dij[MAX][MAX];
pii S, E;
int N, M, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int Y, X;
	char tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> tmp;

			switch (tmp)
			{
			case 'g':
			{
				map[y][x] = GARBAGE;

				for (int i = 0; i < 4; ++i)
				{
					Y = y + Dir[i][0];
					X = x + Dir[i][1];
					map[Y][X] = map[Y][X] == GARBAGE ? GARBAGE : NEAR;
				}

				break;
			}
			case 'F': E = pii(y, x); break;
			case 'S': S = pii(y, x); break;
			}

			dij[y][x] = INF;
		}
	}

	map[E.first][E.second] = FINISH;
	map[S.first][S.second] = 0;
	Q.push(Node(0, S.first, S.second));

	int v, y, x;
	while (!Q.empty())
	{
		do
		{
			auto[tV, tY, tX] = Q.top(); Q.pop();
			v = tV, y = tY, x = tX;
		} while (!Q.empty() && dij[y][x] <= v);

		if (dij[y][x] <= v) continue;

		dij[y][x] = v;

		if (map[y][x] == FINISH)
		{
			result = v;
			break;
		}

		if (map[y][x] == NEAR) v++;
		if (map[y][x] == GARBAGE) v += 10000;

		for (int i = 0; i < 4; ++i)
		{
			Y = y + Dir[i][0];
			X = x + Dir[i][1];

			if (Y > 0 && Y <= N && X > 0 && X <= M)
			{
				if (dij[Y][X] > v)	Q.push(Node(v, Y, X));
			}
		}
	}

	std::cout << result / 10000 << " " << result % 10000;
}