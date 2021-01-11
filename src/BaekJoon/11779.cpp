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

const int MAX = 1e4 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
std::vector<int> result;
std::vector<pii> path[MAX];
int dij[MAX];
int prev[MAX];
bool visited[MAX];
int N, M, S, E;

int main()
{
	Init();

	std::cin >> N >> M;

	std::fill(dij + 1, dij + N + 1, INT_MAX);

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		path[from].push_back(pii(v, to));
	}

	std::cin >> S >> E;

	dij[S] = 0;

	pq.push(pii(0, S));

	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second;
			pq.pop();
		} while (visited[cur] && !pq.empty());

		if (visited[cur]) break;

		visited[cur] = true;

		for (auto& p : path[cur])
		{
			int next = p.first; int d = p.second;

			if (dij[d] > dij[cur] + next)
			{
				dij[d] = dij[cur] + next;
				pq.push(pii(dij[d], d));
				prev[d] = cur;
			}
		}
	}

	std::queue<int> Q;
	Q.push(E);

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		result.push_back(cur);

		if (!prev[cur]) break;
		Q.push(prev[cur]);
	}

	int size = result.size();
	std::cout << dij[E] << "\n";
	std::cout << size << "\n";
	for (int i = size - 1; i >= 0; --i)
	{
		std::cout << result[i] << " ";
	}
}