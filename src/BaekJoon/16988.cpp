#include <iostream>
#include <vector>
#include <queue>
#define BL 2
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	int V;
	pii S;
	pii E;

	Node(){};
	Node(int v, pii s, pii e) : V(v), S(s), E(e){};
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const int MAX = 20 + 1;

std::vector<pii> point;
std::vector<Node> result;
int map[MAX][MAX], advantage[MAX][MAX], visited[MAX][MAX], pVisited[MAX][MAX];
int N, M, cur = 1;

void func(int aY, int aX)
{
	std::vector<pii> data;
	std::queue<pii> Q;
	int total = 0;

	Q.push(pii(aY, aX));
	visited[aY][aX] = cur;

	while (!Q.empty())
	{
		auto [y, x] = Q.front();
		Q.pop();

		total++;

		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (Y > 0 && Y <= N && X > 0 && X <= M)
			{
				if (map[Y][X] == BL)
				{
					if (!visited[Y][X])
					{
						Q.push(pii(Y, X));
						visited[Y][X] = cur;
					}
				}
				else if (map[Y][X] == 0)
				{
					if (visited[Y][X] != cur)
					{
						data.push_back(pii(Y, X));
					}

					visited[Y][X] = cur;
				}
			}
		}
	}

	if (data.size() <= 2)
	{
		if (data.size() == 2)
		{
			result.push_back(Node(total, data[0], data[1]));
		}
		else
		{
			advantage[data[0].first][data[0].second] += total;
		}

		for (auto p : data)
		{
			auto [y, x] = p;

			if (!pVisited[y][x])
			{
				pVisited[y][x] = cur;
				point.push_back(p);
			}
		}
	}
	else
	{
		for (auto p : data)
		{
			auto [y, x] = p;

			visited[y][x] = pVisited[y][x];
		}
	}

	cur++;
}

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> map[y][x];
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			if (map[y][x] == BL && !visited[y][x])
			{
				func(y, x);
			}
		}
	}

	int size = point.size();
	int rSize = result.size();
	int max = 0;

	if (size == 1)
	{
		max = advantage[point[0].first][point[0].second];
	}
	else if (size >= 2)
	{
		for (int y = 0; y < size - 1; ++y)
		{
			for (int x = y + 1; x < size; ++x)
			{
				int total = 0;
				pii S = point[y];
				pii E = point[x];

				total += advantage[S.first][S.second];
				total += advantage[E.first][E.second];

				for (int i = 0; i < rSize; ++i)
				{
					auto [v, s, e] = result[i];

					if (s == S && e == E)
						total += v;
					else if (e == S && s == E)
						total += v;
				}

				max = max > total ? max : total;
			}
		}
	}

	std::cout << max;
}