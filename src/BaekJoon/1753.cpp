#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

typedef std::pair<int, int> pii;

const int MAX = 2e4 + 1;

std::vector<pii> adj[MAX];
std::priority_queue< pii, std::vector<pii>, std::greater<pii>> pq;
int dij[MAX];
bool visited[MAX];

int V, E, S;

int main()
{
	Init();

	std::cin >> V >> E >> S;

	std::fill(dij, dij + V + 1, INT_MAX);
	int from, to, v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		adj[from].push_back(pii(v, to));
	}

	dij[S] = 0;

	pq.push(pii(0, S));

	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;

		visited[cur] = true;

		for (auto &p : adj[cur])
		{
			int next = p.first; int d = p.second;

			if (dij[d] > dij[cur] + next)
			{
				dij[d] = dij[cur] + next;
				pq.push(pii(dij[d], d));
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dij[i] == INT_MAX) std::cout << "INF" << "\n";
		else std::cout << dij[i] << "\n";
	}
}