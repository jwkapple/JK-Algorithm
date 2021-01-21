#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 800 + 1;

std::priority_queue<pii> Q;
std::vector<pii> data[MAX];
int dij[MAX];
int N, E, result = 0;

int dijstra(int from, int to)
{
	Q.push(pii(from, 0));

	dij[from] = 0;

	while (!Q.empty())
	{
		pii cur = Q.top(); Q.pop();

		auto[next, value] = cur;

		for (int i = 0; i < data[next].size(); ++i)
		{
			auto[n, v] = data[next][i];

			int curV = value + v;
			if (dij[n] > curV)
			{
				dij[n] = curV;
				Q.push(pii(n, curV));
			}
		}
	}

	int ret = dij[to];

	std::fill(dij + 1, dij + N + 1, INT_MAX);

	if (ret == INT_MAX) return -1;
	return ret;
}
int main()
{
	Init();

	std::cin >> N >> E;

	std::fill(dij + 1, dij + N + 1, INT_MAX);

	int from, to, v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(to, v));
		data[to].push_back(pii(from, v));
	}

	std::cin >> from >> to;

	result += dijstra(from, to);

	int first, second;

	int lf = dijstra(1, from), rf = dijstra(to, N);
	int ls = dijstra(1, to), rs = dijstra(from, N);

	if (lf == -1 || rf == -1) first = -1;
	else first = lf + rf;
	if (ls == -1 || rs == -1) second = -1;
	else second = ls + rs;

	if (first == -1 || second == -1)
	{
		if (first == second && first == -1) std::cout << -1;
		else { result += std::max(first, second); std::cout << result; }
	}
	else
	{
		result += std::min(first, second);
		std::cout << result;
	}
}