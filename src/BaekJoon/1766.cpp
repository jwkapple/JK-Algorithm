#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}
const int MAX = 32001;

int degree[MAX];
std::vector<int> data[MAX];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
std::vector<int> result;
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		degree[to]++;

		data[from].push_back(to);
	}

	for (int i = 1; i <= N; ++i) { if (!degree[i]) pq.push(i); }

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		result.push_back(cur);

		for (int i = 0; i < data[cur].size(); ++i)
		{
			int current = data[cur][i];

			if (!(--degree[current])) pq.push(current);
		}
	}

	for (int i = 0; i < result.size(); ++i) { std::cout << result[i] << " "; }
}