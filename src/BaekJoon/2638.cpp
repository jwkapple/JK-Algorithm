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
	int Y;
	int X;
	bool V;

	Node(int y, int x, bool v) : X(x), Y(y), V(v) {};
};

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 100 + 1;

std::vector<Node> data;
int map[MAX][MAX];
int N, M, size, cur = 0;

bool func(int y, int x)
{
	int total = 0;
	for (int i = 0; i < 4; ++i)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (map[Y][X] == -1) total++;
	}

	return total >= 2;
}

bool check(int y, int x)
{
	return (y > 0 && y <= N && x > 0 && x <= M);
}

void path(int y, int x)
{
	std::queue<pii> Q;

	Q.push(pii(y, x));
	while (!Q.empty())
	{
		auto[y, x] = Q.front(); Q.pop();

		if (map[y][x]) continue;

		map[y][x] = -1;

		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (Y < 0 || Y > N || X < 0 || X > M) continue;

			Q.push(pii(Y, X));
		}
	}
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
			if (map[y][x] == 1) data.push_back(Node(y, x, false));
		}
	}

	size = data.size();
	path(0, 0);

	int ret = 0;
	while (cur != size)
	{
		std::vector<pii> result;
		for (auto& p : data)
		{
			auto[y, x, v] = p;
			if (v) continue;

			if (func(y, x))
			{
				result.push_back(pii(y, x));;
				p.V = true;
			}
		}

		cur += result.size();

		for (auto p : result)
		{
			auto[y, x] = p;
			map[y][x] = 0;
			path(y, x);
		}

		ret++;
	}

	std::cout << ret;
}