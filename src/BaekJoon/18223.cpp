#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int INF = 5e8 + 1;
const int MAX = 5000 + 1;

int dij[MAX], dijP[MAX], dijV[MAX];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> path[MAX];
int V, E, P, min, minP, minV;

int main()
{
	Init();

	std::cin >> V >> E >> P;

	int from, to, v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		path[from].push_back(pii(v, to));
		path[to].push_back(pii(v, from));
	}

	for (int i = 1; i <= V; ++i)
	{
		dij[i] = INF;
		dijP[i] = INF;
		dijV[i] = INF;
	}
	Q.push(pii(0, 1));

	int value, cur;
	while (!Q.empty())
	{
		do
		{
			value = Q.top().first;
			cur = Q.top().second;

			Q.pop();
		} while (!Q.empty() && dij[cur] != INF);

		if (cur == V)
		{
			min = value;
			break;
		}

		if (cur == P)
			minP = value;

		dij[cur] = value;

		for (auto p : path[cur])
		{
			auto [nValue, next] = p;

			if (dij[next] == INF)
			{
				Q.push(pii(nValue + value, next));
			}
		}
	}

	if (minP == 0)
	{
		std::priority_queue<pii, std::vector<pii>, std::greater<pii>> PQ;

		PQ.push(pii(0, 1));

		while (!PQ.empty())
		{
			do
			{
				value = PQ.top().first;
				cur = PQ.top().second;

				PQ.pop();
			} while (!PQ.empty() && dijP[cur] != INF);

			if (cur == P)
			{
				minP = value;
				break;
			}

			dijP[cur] = value;

			for (auto p : path[cur])
			{
				auto [nValue, next] = p;

				if (dijP[next] == INF)
				{
					PQ.push(pii(nValue + value, next));
				}
			}
		}
	}

	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> VQ;

	VQ.push(pii(0, P));

	while (!VQ.empty())
	{
		do
		{
			value = VQ.top().first;
			cur = VQ.top().second;

			VQ.pop();
		} while (!VQ.empty() && dijV[cur] != INF);

		if (cur == V)
		{
			minV = value;
			break;
		}

		dijV[cur] = value;

		for (auto p : path[cur])

			auto [nValue, next] = p;

		if (dijV[next] == INF)
		{
			VQ.push(pii(nValue + value, next));
		}
	}
}

if (minV + minP == min)
	std::cout << "SAVE HIM";
else
	std::cout << "GOOD BYE";
}