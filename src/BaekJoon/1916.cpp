#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}


const int MAX = 1000 + 1;

std::vector<pii> data[MAX];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
bool visited[MAX];
int dij[MAX];

int N, M, S, E;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		data[from].push_back(pii(v, to));
	}

	std::cin >> S >> E;

	std::fill(dij, dij + N + 1, INT_MAX);
	pq.push(pii(0, S));
	dij[S] = 0;

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
		for (auto& p : data[cur])
		{
			int dist = p.first; int next = p.second;

			if (dij[next] > dij[cur] + dist)
			{
				dij[next] = dij[cur] + dist;
				pq.push(pii(dij[next], next));
			}
		}
	}

	std::cout << dij[E];
}