#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 2000 + 1;
std::vector<int> result;
std::vector<int> container;

std::vector<pii> path[MAX]; // <path, value>
int dijS[MAX], dijG[MAX], dijH[MAX];

int A, N, M, T, S, G, H;

void func(int start, int data[MAX]) // dijkstra
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

	pq.push(pii(0, start)); // <value, point>

	while (!pq.empty())
	{
		int value = pq.top().first;
		int point = pq.top().second;
		pq.pop();

		if (data[point] > value)
		{
			data[point] = value;

			for (int i = 0; i < path[point].size(); ++i)
			{
				pq.push(pii(value + path[point][i].second, path[point][i].first));
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> A;

	int from, to, v;
	while (A--)
	{
		int val = 0;
		std::vector<int> factor;
		std::cin >> N >> M >> T;
		std::cin >> S >> G >> H;

		std::fill(dijS, dijS + N + 1, INT_MAX);
		std::fill(dijG, dijG + N + 1, INT_MAX);
		std::fill(dijH, dijH + N + 1, INT_MAX);

		for (int i = 0; i < M; ++i)
		{
			std::cin >> from >> to >> v;

			if (from == G && to == H) val = v;
			if (from == H && to == G) val = v;
			path[from].push_back(pii(to, v)); path[to].push_back(pii(from, v));
		}

		func(S, dijS); func(G, dijG); func(H, dijH);

		int tmp;
		for (int i = 0; i < T; ++i) { std::cin >> tmp; factor.push_back(tmp); }
		std::sort(factor.begin(), factor.end());

		int tot = 0;

		for (int i = 0; i < T; ++i)
		{
			if (dijS[G] + val + dijH[factor[i]] == dijS[factor[i]] ||
				dijS[H] + val + dijG[factor[i]] == dijS[factor[i]])
			{
				tot++;
				result.push_back(factor[i]);
			}
		}

		container.push_back(tot);
		for (int i = 1; i <= N; ++i) { path[i].clear(); }
	}

	int cur = 0;
	for (int i = 0; i < container.size(); ++i)
	{
		int current = container[i];
		for (int j = 0; j < current; ++j)
		{
			std::cout << result[cur++] << " ";
		}

		std::cout << "\n";
	}
}