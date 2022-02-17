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
int map[MAX][MAX], advantage[MAX][MAX], visited[MAX][MAX];
bool pVisited[MAX][MAX];
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
			auto [y, x] = data[0];
			advantage[y][x] += total;

			if (!pVisited[y][x])
			{
				pVisited[y][x] = true;
				point.push_back(data[0]);
			}
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

	for (int i = 0; i < rSize; ++i)
	{
		auto [v, s, e] = result[i];
		int total = 0;
		total += advantage[s.first][s.second];
		total += advantage[e.first][e.second];
		total += v;
		for (int j = 0; j < rSize; ++j)
		{
			if (i == j)
				continue;

			auto [cV, S, E] = result[j];
			if (s == S && e == E)
				total += cV;
			else if (e == S && s == E)
				total += cV;
		}
		max = max > total ? max : total;
	}

	if (size == 1)
	{
		int total = 0;
		total = advantage[point[0].first][point[0].second];
		max = max > total ? max : total;
	}
	else
	{
		for (int y = 0; y < size - 1; ++y)
		{
			for (int x = y + 1; x < size; ++x)
			{
				int total = 0;
				auto [sX, sY] = point[y];
				auto [eX, eY] = point[x];
				total += advantage[sX][sY] + advantage[eX][eY];
				max = max > total ? max : total;
			}
		}
	}

	std::cout << max;
}