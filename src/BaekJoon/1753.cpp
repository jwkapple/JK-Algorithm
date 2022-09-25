#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<pii> path[MAX];

int dij[MAX];
int N, M;
int to;

void func(int num)
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
	int cur, value;

	dij[num] = 0;

	Q.push(pii(0, num));

	while (!Q.empty())
	{
		do
		{
			value = Q.top().first;
			cur = Q.top().second;
			Q.pop();
		} while (value >= dij[cur] && !Q.empty());

		dij[cur] = value;
		if (cur == to) return;

		for (auto p : path[cur])
		{
			auto [nValue, next] = p;

			nValue += value;
			if (dij[next] > nValue)
			{
				Q.push(pii(nValue, next));
			}
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> M;

	int from, v;

	for (int i = 1; i <= N; ++i)
	{
		dij[i] = INT_MAX;
	}

	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;

		path[from].push_back(pii(v, to));
	}

	std::cin >> from >> to;

	func(from);

	std::cout << dij[to];
}