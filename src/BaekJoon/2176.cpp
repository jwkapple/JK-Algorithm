#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> path[MAX];
int DP[MAX];
int data[MAX][MAX];
int dij[MAX][MAX];
int N, M, result = 0;

void input(int x, int y, int v)
{
	data[x][y] = v, data[y][x] = v;
	path[x].push_back(y), path[y].push_back(x);
}

int dijkstra(int num)
{
	std::priority_queue< pii, std::vector<pii>, std::greater<pii >> pq;

	auto& p = dij[num];
	pq.push(pii(0, num));
	p[num] = 0;

	while (pq.size())
	{
		auto[value, to] = pq.top();

		pq.pop();

		if (value > p[to])
			continue;

		for (int i = 0; i < path[to].size(); ++i)
		{
			auto& nPath = path[to][i];
			int nValue = value + data[nPath][to];

			if (nValue < p[nPath])
			{
				p[nPath] = nValue;
				pq.push(pii(nValue, nPath));
			}
		}
	}

	return p[2];
}

int func(int num)
{
	if (num == 2) return 1;

	auto& ret = DP[num];

	if (ret != -1) return ret;

	ret = 0;

	auto& nPath = path[num];
	for (int i = 0; i < nPath.size(); ++i)
	{
		if (dij[num][2] > dij[nPath[i]][2])
			ret += func(nPath[i]);
	}

	return ret;
}
int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		input(from, to, v);
	}

	for (int i = 0; i <= N; ++i)
	{
		DP[i] = -1;
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			dij[y][x] = INT_MAX;
		}
	}

	for (int i = 1; i <= N; ++i) { dijkstra(i); }

	std::cout << func(1);
}