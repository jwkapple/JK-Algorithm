#include <iostream>
#include <algorithm>
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

int dij[MAX], kist[100 + 1];
int N, V, E, A, B;
int from, to, result = 0;
bool a, b;

int main()
{
	Init();

	std::cin >> N >> V >> E;
	std::cin >> A >> B;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> kist[i];
	}

	int v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		path[from].push_back(pii(v, to));
		path[to].push_back(pii(v, from));
	}

	int cur, value;
	for (int i = 0; i < N; ++i)
	{
		std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

		std::fill(dij, dij + V + 1, 1e9);
		Q.push(pii(0, kist[i]));
		dij[kist[i]] = 0;
		while (!Q.empty())
		{
			do
			{
				value = Q.top().first;
				cur = Q.top().second;
				Q.pop();
			} while (value > dij[cur] && !Q.empty());

			if (Q.empty() && value > dij[cur])
				break;

			if (cur == A)
			{
				a = true;
				result += value;
			}

			if (cur == B)
			{
				b = true;
				result += value;
			}

			if (a && b)
				break;

			dij[cur] = value;

			for (auto p : path[cur])
			{
				auto [nValue, next] = p;
				nValue += value;

				if (nValue < dij[next])
				{
					Q.push(pii(nValue, next));
				}
			}
		}

		if (!a)
			result += -1;
		if (!b)
			result += -1;

		a = false, b = false;
	}

	std::cout << result;
}